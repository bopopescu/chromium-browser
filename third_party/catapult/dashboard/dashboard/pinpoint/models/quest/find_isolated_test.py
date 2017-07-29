# Copyright 2016 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import unittest

from google.appengine.ext import ndb
from google.appengine.ext import testbed

from dashboard.pinpoint.models import change as change_module
from dashboard.pinpoint.models import isolated
from dashboard.pinpoint.models.quest import find_isolated


class _FindIsolatedTest(unittest.TestCase):

  def setUp(self):
    self.testbed = testbed.Testbed()
    self.testbed.activate()
    self.testbed.init_datastore_v3_stub()
    self.testbed.init_memcache_stub()
    ndb.get_context().clear_cache()

    change = change_module.Change(change_module.Dep('src', 'f9f2b720'))
    isolated.Put((
        ('Mac Builder', change, 'telemetry_perf_tests', '7c7e90be'),
    ))

  def tearDown(self):
    self.testbed.deactivate()

  def assertExecutionFailure(self, execution):
    self.assertTrue(execution.completed)
    self.assertTrue(execution.failed)
    self.assertEqual(len(execution.result_values), 1)
    self.assertIsInstance(execution.result_values[0], Exception)
    self.assertEqual(execution.result_arguments, {})

  def assertExecutionSuccess(self, execution):
    self.assertTrue(execution.completed)
    self.assertFalse(execution.failed)
    self.assertEqual(execution.result_values, (0,))


class IsolateLookupTest(_FindIsolatedTest):

  def testIsolateLookupSuccess(self):
    change = change_module.Change(change_module.Dep('src', 'f9f2b720'))
    execution = find_isolated.FindIsolated('Mac Pro Perf').Start(change)
    execution.Poll()

    self.assertExecutionSuccess(execution)
    self.assertEqual(execution.result_arguments, {'isolated_hash': '7c7e90be'})

  def testNoIsolatedAvailable(self):
    change = change_module.Change(change_module.Dep('src', 'bad_hash'))
    execution = find_isolated.FindIsolated('Mac Pro Perf').Start(change)

    execution.Poll()
    self.assertExecutionFailure(execution)


class BuilderLookupTest(_FindIsolatedTest):

  def testSuccesfulBuilderLookupForAllBuilders(self):
    builder_testers = (
        ('arm-builder-rel', 'health-plan-clankium-phone'),
        ('Android Builder', 'Android Nexus5 Perf'),
        ('Android arm64 Builder', 'Android Nexus5X Perf'),
        ('Linux Builder', 'Linux Perf'),
        ('Mac Builder', 'Mac Air Perf'),
        ('Win Builder', 'Win 7 Perf'),
        ('Win x64 Builder', 'Win Zenbook Perf'),
    )

    change = change_module.Change(change_module.Dep('src', 'git hash'))
    isolated.Put(
        (builder, change, 'telemetry_perf_tests', hex(hash(builder)))
        for builder, _ in builder_testers)

    for builder, tester in builder_testers:
      execution = find_isolated.FindIsolated(tester).Start(change)
      execution.Poll()

      self.assertExecutionSuccess(execution)
      self.assertEqual(execution.result_arguments,
                       {'isolated_hash': hex(hash(builder))})

  def testUnknownBuilder(self):
    with self.assertRaises(NotImplementedError):
      find_isolated.FindIsolated('Unix Perf')
