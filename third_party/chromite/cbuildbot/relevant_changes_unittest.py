# Copyright 2016 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Unittests for RelevantChanges."""

from __future__ import print_function

import copy
import mock

from chromite.cbuildbot import build_status_unittest
from chromite.cbuildbot import chromeos_config
from chromite.cbuildbot import relevant_changes
from chromite.lib import builder_status_lib
from chromite.lib import clactions
from chromite.lib import constants
from chromite.lib import fake_cidb
from chromite.lib import failures_lib
from chromite.lib import patch_unittest
from chromite.lib import triage_lib


# pylint: disable=protected-access
class RelevantChangesTest(patch_unittest.MockPatchBase):
  """Tests for RelevantChanges."""

  def setUp(self):
    self._bot_id = 'master-paladin'
    self.site_config = chromeos_config.GetConfig()
    self.build_config = copy.deepcopy(self.site_config[self._bot_id])

    self.fake_cidb = fake_cidb.FakeCIDBConnection()
    self.master_build_id = self.fake_cidb.InsertBuild(
        self._bot_id, 'chromeos', '1', self._bot_id, 'bot_hostname')

  def _InsertSlaveBuildAndCLActions(self, slave_config):
    changes = set(self.GetPatches(how_many=4))
    test_build_id = self.fake_cidb.InsertBuild(
        slave_config, 'chromeos', '2', slave_config, 'bot_hostname',
        master_build_id=self.master_build_id, buildbucket_id='bb_id_1')

    for change in changes:
      self.fake_cidb.InsertCLActions(
          test_build_id, [clactions.CLAction.FromGerritPatchAndAction(
              change, constants.CL_ACTION_PICKED_UP)])

    return test_build_id, changes

  def test_GetSlaveMappingAndCLActionsOnNotMasterBuild(self):
    """Test _GetSlaveMappingAndCLActions on not-master build."""
    self.build_config.master = False
    mock_cidb = mock.Mock()
    self.assertRaises(
        Exception,
        relevant_changes.RelevantChanges._GetSlaveMappingAndCLActions,
        self.master_build_id, mock_cidb, self.build_config, mock.Mock(),
        ['bb_id_1'])
    self.assertFalse(mock_cidb.GetSlaveStatuses.called)

  def test_GetSlaveMappingAndCLActionsIncludesMaster(self):
    """Tests _GetSlaveMappingAndCLActions with include_master=True."""
    slave_config = 'test-paladin'
    test_build_id, changes = self._InsertSlaveBuildAndCLActions(slave_config)

    config_map, action_history = (
        relevant_changes.RelevantChanges._GetSlaveMappingAndCLActions(
            self.master_build_id, self.fake_cidb, self.build_config,
            changes, ['bb_id_1'], include_master=True))
    expected_config_map = {
        self.master_build_id: self._bot_id,
        test_build_id: slave_config
    }
    self.assertDictEqual(config_map, expected_config_map)
    self.assertEqual(len(action_history), 4)

  def test_GetSlaveMappingAndCLActionsExcludesMaster(self):
    """Tests _GetSlaveMappingAndCLActions with include_master=False."""
    slave_config = 'test-paladin'
    test_build_id, changes = self._InsertSlaveBuildAndCLActions(slave_config)

    config_map, action_history = (
        relevant_changes.RelevantChanges._GetSlaveMappingAndCLActions(
            self.master_build_id, self.fake_cidb, self.build_config,
            changes, ['bb_id_1']))
    expected_config_map = {
        test_build_id: slave_config
    }
    self.assertDictEqual(config_map, expected_config_map)
    self.assertEqual(len(action_history), 4)

  def testGetRelevantChangesForSlaves(self):
    """Tests the logic of GetRelevantChangesForSlaves()."""
    change_set1 = set(self.GetPatches(how_many=2))
    change_set2 = set(self.GetPatches(how_many=3))
    changes = set.union(change_set1, change_set2)
    no_stat = ['no_stat-paladin']
    config_map = {'123': 'foo-paladin',
                  '124': 'bar-paladin',
                  '125': 'no_stat-paladin'}
    changes_by_build_id = {'123': change_set1,
                           '124': change_set2}
    # If a slave did not report status (no_stat), assume all changes
    # are relevant.
    expected = {'foo-paladin': change_set1,
                'bar-paladin': change_set2,
                'no_stat-paladin': changes}

    self.PatchObject(relevant_changes.RelevantChanges,
                     '_GetSlaveMappingAndCLActions',
                     return_value=(config_map, []))
    self.PatchObject(clactions, 'GetRelevantChangesForBuilds',
                     return_value=changes_by_build_id)

    results = relevant_changes.RelevantChanges.GetRelevantChangesForSlaves(
        self.master_build_id, self.fake_cidb, self.build_config, changes,
        no_stat, None)
    self.assertEqual(results, expected)

  def testGetSubsysResultForSlaves(self):
    """Tests for the GetSubsysResultForSlaves."""
    def get_dict(build_config, message_type, message_subtype, message_value):
      return {'build_config': build_config,
              'message_type': message_type,
              'message_subtype': message_subtype,
              'message_value': message_value}

    slave_msgs = [get_dict('config_1', constants.SUBSYSTEMS,
                           constants.SUBSYSTEM_PASS, 'a'),
                  get_dict('config_1', constants.SUBSYSTEMS,
                           constants.SUBSYSTEM_PASS, 'b'),
                  get_dict('config_1', constants.SUBSYSTEMS,
                           constants.SUBSYSTEM_FAIL, 'c'),
                  get_dict('config_2', constants.SUBSYSTEMS,
                           constants.SUBSYSTEM_UNUSED, None),
                  get_dict('config_3', constants.SUBSYSTEMS,
                           constants.SUBSYSTEM_PASS, 'a'),
                  get_dict('config_3', constants.SUBSYSTEMS,
                           constants.SUBSYSTEM_PASS, 'e'),]
    # Setup DB and provide list of slave build messages.
    mock_cidb = mock.MagicMock()
    self.PatchObject(mock_cidb, 'GetSlaveBuildMessages',
                     return_value=slave_msgs)

    expect_result = {
        'config_1': {'pass_subsystems':set(['a', 'b']),
                     'fail_subsystems':set(['c'])},
        'config_2': {},
        'config_3': {'pass_subsystems':set(['a', 'e'])}}
    self.assertEqual(
        relevant_changes.RelevantChanges.GetSubsysResultForSlaves(
            1, mock_cidb),
        expect_result)


class TriageRelevantChangesTest(patch_unittest.MockPatchBase):
  """Tests for TriageRelevantChanges."""
  FAIL = constants.BUILDER_STATUS_FAILED
  PASS = constants.BUILDER_STATUS_PASSED
  FORGIVEN = constants.BUILDER_STATUS_FORGIVEN

  COMMIT_QUEUE_SYNC = (
      relevant_changes.TriageRelevantChanges.COMMIT_QUEUE_SYNC)

  BuildbucketInfos = build_status_unittest.BuildbucketInfos

  def setUp(self):
    self._bot_id = 'master-paladin'
    self.site_config = chromeos_config.GetConfig()
    self.build_config = self.site_config[self._bot_id]
    self.fake_cidb = fake_cidb.FakeCIDBConnection()
    self.slaves = ['slave_1', 'slave_2', 'slave_3', 'slave_4']
    self.buildbucket_info_dict = self._GetDefaultSuccessBuildbucketInfoDict(
        self.slaves)
    self.buildbucket_ids = [bb_info.buildbucket_id
                            for bb_info in self.buildbucket_info_dict.values()]
    self.master_build_id = self.fake_cidb.InsertBuild(
        self._bot_id, 'chromeos', '1', self._bot_id, 'bot_hostname')
    self.changes = self.GetPatches(how_many=4)
    self._InsertCLActionsForBuild(self.master_build_id, self.changes,
                                  constants.CL_ACTION_PICKED_UP)
    self.version = '9289.0.0-rc2'
    self.build_root = '/tmp/build_root'
    self.PatchObject(builder_status_lib.BuilderStatusManager,
                     'GetBuilderStatus',
                     return_value=self._GetMissingBuilderStatus())

  def _GetDefaultSuccessBuildbucketInfoDict(self, builds):
    return {build: self.BuildbucketInfos.GetSuccessBuild(
        bb_id='bb_id_%s' % build) for build in builds}

  def _InsertCLActionsForBuild(self, build_id, changes, action):
    """Insert CL_ACTION_PICKED_UP for master build."""
    for change in changes:
      self.fake_cidb.InsertCLActions(
          build_id, [clactions.CLAction.FromGerritPatchAndAction(
              change, action)])

  def GetTriageRelevantChanges(self,
                               changes=None,
                               buildbucket_info_dict=None,
                               cidb_status_dict=None,
                               completed_builds=None,
                               dependency_map=None):
    """Returns a TriageRelevantChanges instance."""
    if changes is None:
      changes = self.changes
    if buildbucket_info_dict is None:
      buildbucket_info_dict = self.buildbucket_info_dict
    if cidb_status_dict is None:
      cidb_status_dict = {}
    if completed_builds is None:
      completed_builds = {}
    if dependency_map is None:
      dependency_map = {}

    return relevant_changes.TriageRelevantChanges(
        self.master_build_id, self.fake_cidb, self.build_config, self.version,
        self.build_root, changes, buildbucket_info_dict, cidb_status_dict,
        completed_builds, dependency_map)

  def _MockSlaveInfo(self, slave_stages_dict, slave_changes_dict,
                     slave_subsys_dict):
    mock_get_stages = self.PatchObject(relevant_changes.TriageRelevantChanges,
                                       'GetSlaveStages',
                                       return_value=slave_stages_dict)
    mock_get_changes = self.PatchObject(relevant_changes.TriageRelevantChanges,
                                        '_GetRelevantChanges',
                                        return_value=slave_changes_dict)
    mock_get_subsys = self.PatchObject(relevant_changes.RelevantChanges,
                                       'GetSubsysResultForSlaves',
                                       return_value=slave_subsys_dict)

    return mock_get_stages, mock_get_changes, mock_get_subsys

  def testGetTriageRelevantChanges_UpdateSlaveInfo(self):
    """test GetTriageRelevantChanges init with _UpdateSlaveInfo."""
    mock_stage_dict = mock.Mock()
    mock_changes_dict = mock.Mock()
    mock_subsys_dict = mock.Mock()
    mock_get_stages, mock_get_changes, mock_get_subsys = self._MockSlaveInfo(
        mock_stage_dict, mock_changes_dict, mock_subsys_dict)
    self.GetTriageRelevantChanges()
    mock_get_stages.assert_called_once_with(
        self.master_build_id, self.fake_cidb, self.buildbucket_info_dict)
    mock_get_changes.assert_called_once_with(
        mock_stage_dict)
    mock_get_subsys.assert_called_once_with(
        self.master_build_id, self.fake_cidb)

  def _BuildDependMap(self):
    """Helper method to build dependency_map for GetDependChanges tests."""
    p = self.GetPatches(how_many=6)
    dependency_map = {
        # p1, p2, p3 depend on p0
        p[0]: {p[1], p[2], p[3]},
        # p0, p2, p3 depend on p1
        p[1]: {p[0], p[2], p[3]},
        # p5 depends on p4
        p[4]: {p[5]}
    }
    return p, dependency_map

  def testGetDependChangesWithDepends(self):
    """Test GetDependChanges with on changes with depends."""
    p, depend_map = self._BuildDependMap()
    dep_changes = relevant_changes.TriageRelevantChanges.GetDependChanges(
        set(p[0:2]), depend_map)

    self.assertSetEqual(dep_changes, set(p[0:4]))

  def testGetDependChangesWithoutDepends(self):
    """Test GetDependChanges with on changes without depends."""
    p, depend_map = self._BuildDependMap()
    dep_changes = relevant_changes.TriageRelevantChanges.GetDependChanges(
        set([p[5]]), depend_map)

    self.assertSetEqual(dep_changes, set())

  def testGetDependChangesWithEmptySet(self):
    """Test GetDependChanges on empty change set."""
    _, depend_map = self._BuildDependMap()
    dep_changes = relevant_changes.TriageRelevantChanges.GetDependChanges(
        set(), depend_map)

    self.assertSetEqual(dep_changes, set())

  def _InsertSlaveBuilds(self, builds, buildbucket_info_dict):
    """Insert slave build into cidb buildTable.

    Returns:
      A dict mapping build config name to build id.
    """
    return {
        build: self.fake_cidb.InsertBuild(
            build, 'chromeos', '1', build, 'bot_hostname',
            master_build_id=self.master_build_id,
            buildbucket_id=buildbucket_info_dict[build].buildbucket_id)
        for build in builds
    }

  def _InsertDefaultSlaveStages(self, builds):
    self.fake_cidb.InsertBuildStage(
        1, self.COMMIT_QUEUE_SYNC, builds[0], status=self.FAIL)

    self.fake_cidb.InsertBuildStage(
        2, self.COMMIT_QUEUE_SYNC, builds[1], status=self.PASS)

    self.fake_cidb.InsertBuildStage(
        3, self.COMMIT_QUEUE_SYNC, builds[2], status=self.PASS)

    self.fake_cidb.InsertBuildStage(
        4, self.COMMIT_QUEUE_SYNC, builds[3], status=self.PASS)

  def testGetSlaveStages(self):
    """Test GetSlaveStages."""
    self._InsertSlaveBuilds(self.slaves, self.buildbucket_info_dict)
    self._InsertDefaultSlaveStages(self.slaves)

    slave_stages = relevant_changes.TriageRelevantChanges.GetSlaveStages(
        self.master_build_id, self.fake_cidb, self.buildbucket_info_dict)

    self.assertItemsEqual(slave_stages.keys(), self.slaves)
    self.assertEqual(len(slave_stages['slave_1']), 1)
    self.assertEqual(len(slave_stages['slave_2']), 1)
    self.assertEqual(len(slave_stages['slave_3']), 1)
    self.assertEqual(len(slave_stages['slave_4']), 1)

  def testGetBuildsPassedAnyOfStagesOnSyncStage(self):
    """Returns builds which passed STAGE_SYNC."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    self._InsertSlaveBuilds(self.slaves, self.buildbucket_info_dict)
    self._InsertDefaultSlaveStages(self.slaves)
    triage_changes = self.GetTriageRelevantChanges()
    slave_stages = relevant_changes.TriageRelevantChanges.GetSlaveStages(
        self.master_build_id, self.fake_cidb, self.buildbucket_info_dict)
    passed_builds = triage_changes.GetBuildsPassedAnyOfStages(
        slave_stages, relevant_changes.TriageRelevantChanges.STAGE_SYNC)

    self.assertItemsEqual(passed_builds, {'slave_2', 'slave_3', 'slave_4'})

  def test_GetRelevantChangesWithoutCLActions(self):
    """Test _GetRelevantChanges without CLActions."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    self._InsertSlaveBuilds(self.slaves, self.buildbucket_info_dict)
    self._InsertDefaultSlaveStages(self.slaves)
    triage_changes = self.GetTriageRelevantChanges()
    slave_stages_dict = triage_changes.GetSlaveStages(
        self.master_build_id, self.fake_cidb, self.buildbucket_info_dict)
    slave_changes_dict = triage_changes._GetRelevantChanges(slave_stages_dict)

    self.assertEqual(len(slave_changes_dict.keys()), 4)
    self.assertItemsEqual(slave_changes_dict['slave_1'], self.changes)
    for slave in ['slave_2', 'slave_3', 'slave_4']:
      self.assertEqual(slave_changes_dict[slave], set())

  def test_GetRelevantChangesWithCLActions(self):
    """Test _GetRelevantChanges with CLActions."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    build_dict = self._InsertSlaveBuilds(self.slaves,
                                         self.buildbucket_info_dict)
    self._InsertDefaultSlaveStages(self.slaves)
    self._InsertCLActionsForBuild(build_dict[self.slaves[1]], self.changes,
                                  constants.CL_ACTION_PICKED_UP)
    self._InsertCLActionsForBuild(build_dict[self.slaves[2]], self.changes,
                                  constants.CL_ACTION_PICKED_UP)
    self._InsertCLActionsForBuild(build_dict[self.slaves[2]], self.changes[2:4],
                                  constants.CL_ACTION_IRRELEVANT_TO_SLAVE)
    self._InsertCLActionsForBuild(build_dict[self.slaves[3]], self.changes,
                                  constants.CL_ACTION_PICKED_UP)
    self._InsertCLActionsForBuild(build_dict[self.slaves[3]], self.changes,
                                  constants.CL_ACTION_IRRELEVANT_TO_SLAVE)

    triage_changes = self.GetTriageRelevantChanges()
    slave_stages_dict = triage_changes.GetSlaveStages(
        self.master_build_id, self.fake_cidb, self.buildbucket_info_dict)
    slave_changes_dict = triage_changes._GetRelevantChanges(slave_stages_dict)

    self.assertEqual(len(slave_changes_dict.keys()), 4)
    self.assertItemsEqual(slave_changes_dict['slave_1'], self.changes)
    self.assertItemsEqual(slave_changes_dict['slave_2'], self.changes)
    self.assertItemsEqual(slave_changes_dict['slave_3'], self.changes[0:2])
    self.assertItemsEqual(slave_changes_dict['slave_4'], set())

  def _GetFailedBuilderStatus(self, contains_message=True):
    """Helper to return a failed BuilderStatus."""
    failure_message = failures_lib.BuildFailureMessage(
        'messages', [], True, 'reason', 'builder') if contains_message else None
    return builder_status_lib.BuilderStatus(
        constants.BUILDER_STATUS_FAILED, failure_message)

  def _GetPassedBuilderStatus(self):
    """Helper to return a passed BuilderStatus."""
    return builder_status_lib.BuilderStatus(
        constants.BUILDER_STATUS_PASSED, None)

  def _GetMissingBuilderStatus(self):
    """Helper to return a missing BuilderStatus."""
    return builder_status_lib.BuilderStatus(
        constants.BUILDER_STATUS_MISSING, None)

  def test_GetIgnorableChangesOnFailedStatusReturnsNone(self):
    """Test _GetIgnorableChanges on Failed BuilderStatus returns empty set."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    builder_status = self._GetFailedBuilderStatus()
    triage_changes = self.GetTriageRelevantChanges()
    self.PatchObject(triage_lib.CalculateSuspects, 'CanIgnoreFailures',
                     return_value=(False, None))
    ignorable_changes = triage_changes._GetIgnorableChanges(
        'test-paladin', builder_status, set(self.changes))

    self.assertEqual(ignorable_changes, set())

  def test_GetIgnorableChangesOnFailedStatusReturnsAll(self):
    """Test _GetIgnorableChanges on Failed BuilderStatus returns all changes."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    builder_status = self._GetFailedBuilderStatus()
    triage_changes = self.GetTriageRelevantChanges()
    self.PatchObject(triage_lib.CalculateSuspects, 'CanIgnoreFailures',
                     return_value=(True, constants.STRATEGY_CQ_PARTIAL))
    ignorable_changes = triage_changes._GetIgnorableChanges(
        'test-paladin', builder_status, set(self.changes))

    self.assertItemsEqual(ignorable_changes, self.changes)

  def test_GetIgnorableChangesOnFailedStatusWithoutMessageReturnsNone(self):
    """Test _GetIgnorableChanges on Failed BuilderStatus without messages."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    builder_status = self._GetFailedBuilderStatus(contains_message=False)
    triage_changes = self.GetTriageRelevantChanges()
    self.PatchObject(triage_lib.CalculateSuspects, 'CanIgnoreFailures',
                     return_value=(True, constants.STRATEGY_CQ_PARTIAL))
    ignorable_changes = triage_changes._GetIgnorableChanges(
        'test-paladin', builder_status, set(self.changes))

    self.assertEqual(ignorable_changes, set())

  def test_GetIgnorableChangesOnMissingStatusReturnsNone(self):
    """Test _GetIgnorableChanges on Missing BuilderStatus returns None."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    builder_status = self._GetMissingBuilderStatus()
    triage_changes = self.GetTriageRelevantChanges()
    ignorable_changes = triage_changes._GetIgnorableChanges(
        'test-paladin', builder_status, set(self.changes))

    self.assertEqual(ignorable_changes, set())

  def test_GetIgnorableChangesOnPassStatusReturnsAll(self):
    """Test _GetIgnorableChanges on Passed BuilderStatus returns all changes."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    builder_status = self._GetPassedBuilderStatus()
    triage_changes = self.GetTriageRelevantChanges()
    ignorable_changes = triage_changes._GetIgnorableChanges(
        'test-paladin', builder_status, set(self.changes))

    self.assertEqual(ignorable_changes, set(self.changes))

  def test_UpdateWillNotSubmitChanges(self):
    """Test _UpdateWillNotSubmitChanges."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    triage_changes = self.GetTriageRelevantChanges()
    triage_changes.might_submit = set(self.changes[0: 5])
    triage_changes.will_not_submit = set()

    triage_changes._UpdateWillNotSubmitChanges(set(self.changes[0:2]))
    self.assertSetEqual(triage_changes.might_submit, set(self.changes[2:5]))
    self.assertSetEqual(triage_changes.will_not_submit, set(self.changes[0:2]))

  def test_UpdateWillNotSubmitChangesRemoveAllChanges(self):
    """Test _UpdateWillNotSubmitChanges to remove all changes."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    triage_changes = self.GetTriageRelevantChanges()
    triage_changes.might_submit = set(self.changes[0:4])
    triage_changes.will_not_submit = set(self.changes[4:5])

    triage_changes._UpdateWillNotSubmitChanges(set(self.changes))
    self.assertSetEqual(triage_changes.might_submit, set())
    self.assertSetEqual(triage_changes.will_not_submit, set(self.changes))

  def _GetStage(self, build_id=0, status=PASS, build_config='build_config',
                name='name', board='board'):
    return {
        'build_id': build_id,
        'status': status,
        'build_config': build_config,
        'name': name,
        'board': board
    }

  def _GetMockSlaveInfoForProcessCompletedBuilds(self, build, stages):
    slave_stages_dict = {build: stages}
    slave_changes_dict = {build: set(self.changes[0:2])}

    self.buildbucket_info_dict = {
        build: self.BuildbucketInfos.GetCanceledBuild()
    }

    self._MockSlaveInfo(slave_stages_dict, slave_changes_dict, {})

  def test_ProcessCompletedBuildsNoStage(self):
    """Test _ProcessCompletedBuilds on build without stages."""
    build = 'slave_1'
    self._GetMockSlaveInfoForProcessCompletedBuilds(build, [])
    triage_changes = self.GetTriageRelevantChanges(
        completed_builds={build})

    triage_changes._ProcessCompletedBuilds()
    self.assertItemsEqual(triage_changes.will_submit, set())
    self.assertItemsEqual(triage_changes.might_submit, set())
    self.assertItemsEqual(triage_changes.will_not_submit,
                          self.changes)

  def test_ProcessCompletedBuildsFailedSyncStage(self):
    """Test _ProcessCompletedBuilds on build failing at the sync stage."""
    build = 'slave_1'
    stages = [self._GetStage(
        status=self.FAIL, build_config=build, name=self.COMMIT_QUEUE_SYNC)]
    self._GetMockSlaveInfoForProcessCompletedBuilds(build, stages)
    triage_changes = self.GetTriageRelevantChanges(
        completed_builds={build})

    triage_changes._ProcessCompletedBuilds()
    self.assertItemsEqual(triage_changes.will_submit, set())
    self.assertItemsEqual(triage_changes.might_submit, set())
    self.assertItemsEqual(triage_changes.will_not_submit, self.changes)

  def test_ProcessCompletedBuildsNoCompletionStageWithMissingStatus(self):
    """Test build without completion stage and missing BuilderStatus."""
    build = 'slave_1'
    stages = [self._GetStage(status=self.PASS, build_config=build,
                             name=self.COMMIT_QUEUE_SYNC)]
    self._GetMockSlaveInfoForProcessCompletedBuilds(build, stages)
    triage_changes = self.GetTriageRelevantChanges(
        completed_builds={build})

    triage_changes._ProcessCompletedBuilds()
    self.assertItemsEqual(triage_changes.will_submit, set())
    self.assertItemsEqual(triage_changes.might_submit, set(self.changes[2:4]))
    self.assertItemsEqual(triage_changes.will_not_submit,
                          set(self.changes[0:2]))

  def test_ProcessCompletedBuildsFailedCompletionStageWithMissingStatus(self):
    """Test build with failed completion stage and missing BuilderStatus."""
    build = 'slave_1'
    stages = [self._GetStage(status=self.PASS, build_config=build,
                             name=self.COMMIT_QUEUE_SYNC)]
    self._GetMockSlaveInfoForProcessCompletedBuilds(build, stages)
    triage_changes = self.GetTriageRelevantChanges(
        completed_builds={build})

    triage_changes._ProcessCompletedBuilds()
    self.assertItemsEqual(triage_changes.will_submit, set())
    self.assertItemsEqual(triage_changes.might_submit, set(self.changes[2:4]))
    self.assertItemsEqual(triage_changes.will_not_submit,
                          set(self.changes[0:2]))

  def test_ProcessCompletedBuildsForgivenCompletionStageWithPassedStatus(self):
    """Test build with forgiven completion stage and passed BuilderStatus."""
    build = 'slave_1'
    stages = [self._GetStage(status=self.PASS, build_config=build,
                             name=self.COMMIT_QUEUE_SYNC)]
    self._GetMockSlaveInfoForProcessCompletedBuilds(build, stages)
    self.PatchObject(builder_status_lib.BuilderStatusManager,
                     'GetBuilderStatus',
                     return_value=self._GetPassedBuilderStatus())
    can_ignore_failures_mock = self.PatchObject(
        triage_lib.CalculateSuspects, 'CanIgnoreFailures')
    triage_changes = self.GetTriageRelevantChanges(
        completed_builds={build})

    triage_changes._ProcessCompletedBuilds()
    self.assertFalse(can_ignore_failures_mock.called)
    self.assertItemsEqual(triage_changes.will_submit, set())
    self.assertItemsEqual(triage_changes.might_submit, set(self.changes))
    self.assertItemsEqual(triage_changes.will_not_submit, set())

  def test_ProcessCompletedBuildsForgivenCompletionStageWithMissingStatus(self):
    """Test build with forgiven completion stage and missing BuilderStatus."""
    build = 'slave_1'
    stages = [self._GetStage(status=self.PASS, build_config=build,
                             name=self.COMMIT_QUEUE_SYNC)]
    self._GetMockSlaveInfoForProcessCompletedBuilds(build, stages)
    can_ignore_failures_mock = self.PatchObject(
        triage_lib.CalculateSuspects, 'CanIgnoreFailures')
    triage_changes = self.GetTriageRelevantChanges(
        completed_builds={build})

    triage_changes._ProcessCompletedBuilds()
    self.assertFalse(can_ignore_failures_mock.called)
    self.assertItemsEqual(triage_changes.will_submit, set())
    self.assertItemsEqual(triage_changes.might_submit, set(self.changes[2:4]))
    self.assertItemsEqual(triage_changes.will_not_submit,
                          set(self.changes[0:2]))

  def test_ProcessCompletedBuildsForgivenCompletionStageWithFailedStatus(self):
    """Test build with forgiven completion stage and failed BuilderStatus."""
    build = 'slave_1'
    stages = [self._GetStage(status=self.PASS, build_config=build,
                             name=self.COMMIT_QUEUE_SYNC)]
    self._GetMockSlaveInfoForProcessCompletedBuilds(build, stages)
    self.PatchObject(builder_status_lib.BuilderStatusManager,
                     'GetBuilderStatus',
                     return_value=self._GetFailedBuilderStatus())
    self.PatchObject(
        relevant_changes.TriageRelevantChanges, '_GetIgnorableChanges',
        return_value={self.changes[1]})
    triage_changes = self.GetTriageRelevantChanges(
        completed_builds={build})

    triage_changes._ProcessCompletedBuilds()
    self.assertItemsEqual(triage_changes.will_submit, set())
    self.assertItemsEqual(triage_changes.might_submit, set(self.changes[1:4]))
    self.assertItemsEqual(triage_changes.will_not_submit,
                          set(self.changes[0:1]))

  def test_ProcessCompletedBuildsPassedCompletionStage(self):
    """Test build with passed completion stage and passed BuilderStatus."""
    build = 'slave_1'
    stages = [self._GetStage(status=self.PASS, build_config=build,
                             name=self.COMMIT_QUEUE_SYNC)]
    self._GetMockSlaveInfoForProcessCompletedBuilds(build, stages)
    self.PatchObject(builder_status_lib.BuilderStatusManager,
                     'GetBuilderStatus',
                     return_value=self._GetPassedBuilderStatus())
    self.PatchObject(
        relevant_changes.TriageRelevantChanges, '_GetIgnorableChanges',
        return_value=set(self.changes))
    triage_changes = self.GetTriageRelevantChanges(
        completed_builds={build})

    triage_changes._ProcessCompletedBuilds()
    self.assertItemsEqual(triage_changes.will_submit, set())
    self.assertItemsEqual(triage_changes.might_submit, set(self.changes))
    self.assertItemsEqual(triage_changes.will_not_submit, set())

  def test_GetChangeToSlavesDict(self):
    """Test _GetChangeToSlavesDict."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    triage_changes = self.GetTriageRelevantChanges()
    slave_changes_dict = {
        self.slaves[0]: set(self.changes[0:1]),
        self.slaves[1]: set(self.changes[0:2]),
        self.slaves[2]: set(self.changes[2:4]),
        self.slaves[3]: set()
    }
    change_slaves_dict = triage_changes._GetChangeToSlavesDict(
        slave_changes_dict)

    expected_dict = {
        self.changes[0]: set(self.slaves[0:2]),
        self.changes[1]: set([self.slaves[1]]),
        self.changes[2]: set([self.slaves[2]]),
        self.changes[3]: set([self.slaves[2]])
    }
    self.assertDictEqual(change_slaves_dict, expected_dict)

  def test_ChangeCanBeSubmittedOnStartedBuildReturnsFalse(self):
    """_ChangeCanBeSubmitted Returns False on Started build."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    self.buildbucket_info_dict = {
        self.slaves[0]: self.BuildbucketInfos.GetSuccessBuild(),
        self.slaves[1]: self.BuildbucketInfos.GetStartedBuild()}
    triage_changes = self.GetTriageRelevantChanges()
    self.assertFalse(triage_changes._ChangeCanBeSubmitted(
        self.changes[0], self.slaves[0:2], {}))

  def test_ChangeCanBeSubmittedOnNotIgnorableChangeReturnsFalse(self):
    """_ChangeCanBeSubmitted returns False for not ignorable change"""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    self.buildbucket_info_dict = {
        self.slaves[0]: self.BuildbucketInfos.GetSuccessBuild(),
        self.slaves[1]: self.BuildbucketInfos.GetFailureBuild()}
    triage_changes = self.GetTriageRelevantChanges()
    self.assertFalse(triage_changes._ChangeCanBeSubmitted(
        self.changes[0], self.slaves[0:2], {}))

  def test_ChangeCanBeSubmittedOnIgnorableChangeReturnsTrue(self):
    """_CanIgnoreFailedBuildsForChange returns True for ignorable change."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    self.buildbucket_info_dict = {
        self.slaves[0]: self.BuildbucketInfos.GetSuccessBuild(),
        self.slaves[1]: self.BuildbucketInfos.GetFailureBuild()}
    build_ignorable_changes_dict = {
        'slave_1': set(self.changes[0:1]),
        'slave_2': set(self.changes[1:3])
    }
    triage_changes = self.GetTriageRelevantChanges()
    self.assertTrue(triage_changes._ChangeCanBeSubmitted(
        self.changes[1], self.slaves[0:2], build_ignorable_changes_dict))

  def _GetMockBuildbucketInfoForProcessMightSubmitChanges(self):
    self.buildbucket_info_dict = {
        self.slaves[0]: self.BuildbucketInfos.GetSuccessBuild(),
        self.slaves[1]: self.BuildbucketInfos.GetSuccessBuild(),
        self.slaves[2]: self.BuildbucketInfos.GetStartedBuild(),
        self.slaves[3]: self.BuildbucketInfos.GetScheduledBuild()
    }

  def test_ProcessMightSubmitChanges(self):
    """Test _ProcessMightSubmitChanges."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    self._GetMockBuildbucketInfoForProcessMightSubmitChanges()
    change_slaves_dict = {
        self.changes[0]: set(self.slaves[0:2]),
        self.changes[1]: set([self.slaves[1]]),
        self.changes[2]: set([self.slaves[2]]),
        self.changes[3]: set([self.slaves[2]])
    }
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_GetChangeToSlavesDict',
                     return_value=change_slaves_dict)
    triage_changes = self.GetTriageRelevantChanges()
    triage_changes._ProcessMightSubmitChanges()

    self.assertSetEqual(triage_changes.will_submit, set(self.changes[0:2]))
    self.assertSetEqual(triage_changes.might_submit, set(self.changes[2:4]))
    self.assertSetEqual(triage_changes.will_not_submit, set())

  def test_ProcessMightSubmitChangesOnChangesWithoutRelevantSlaves(self):
    """Test _ProcessMightSubmitChangesOnChanges without relevant slaves."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    self._GetMockBuildbucketInfoForProcessMightSubmitChanges()
    change_slaves_dict = {
        self.changes[0]: set(self.slaves[0:4]),
        self.changes[1]: set([self.slaves[2]]),
        self.changes[2]: set([self.slaves[2]]),
    }
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_GetChangeToSlavesDict',
                     return_value=change_slaves_dict)
    triage_changes = self.GetTriageRelevantChanges()
    triage_changes._ProcessMightSubmitChanges()

    self.assertSetEqual(triage_changes.will_submit, set([self.changes[3]]))
    self.assertSetEqual(triage_changes.might_submit, set(self.changes[0:3]))
    self.assertSetEqual(triage_changes.will_not_submit, set())

  def testShouldWaitReturnsTrue(self):
    """Test ShouldWait which returns True."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_ProcessCompletedBuilds')
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_ProcessMightSubmitChanges')
    triage_changes = self.GetTriageRelevantChanges()

    self.assertTrue(triage_changes.ShouldWait())

  def testShouldWaitReturnsFalse(self):
    """Test ShouldWait which returns False."""
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_UpdateSlaveInfo')
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_ProcessCompletedBuilds')
    self.PatchObject(relevant_changes.TriageRelevantChanges,
                     '_ProcessMightSubmitChanges')
    triage_changes = self.GetTriageRelevantChanges()
    triage_changes.might_submit = set()

    self.assertFalse(triage_changes.ShouldWait())
