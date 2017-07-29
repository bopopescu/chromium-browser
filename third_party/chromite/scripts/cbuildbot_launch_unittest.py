# Copyright 2016 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Unit tests for chromite.lib.git and helpers for testing that module."""

from __future__ import print_function

import mock
import os

from chromite.cbuildbot import repository
from chromite.lib import constants
from chromite.lib import cros_build_lib
from chromite.lib import cros_build_lib_unittest
from chromite.lib import cros_test_lib
from chromite.lib import osutils
from chromite.scripts import cbuildbot_launch


EXPECTED_MANIFEST_URL = 'https://chrome-internal-review.googlesource.com/chromeos/manifest-internal'  # pylint: disable=line-too-long


# It's reasonable for unittests to look at internals.
# pylint: disable=protected-access


class FakeException(Exception):
  """Test exception to raise during tests."""


class CbuildbotLaunchTest(cros_test_lib.MockTestCase):
  """Tests for cbuildbot_launch script."""

  def testPreParseArguments(self):
    """Test that we can correctly extract branch values from cbuildbot args."""
    CASES = (
        (['--buildroot', '/buildroot', 'daisy-incremental'],
         (None, '/buildroot', None)),

        (['--buildbot', '--buildroot', '/buildroot',
          '--git-cache-dir', '/git-cache',
          '-b', 'release-R57-9202.B',
          'daisy-incremental'],
         ('release-R57-9202.B', '/buildroot', '/git-cache')),

        (['--debug', '--buildbot', '--notests',
          '--buildroot', '/buildroot',
          '--git-cache-dir', '/git-cache',
          '--branch', 'release-R57-9202.B',
          'daisy-incremental'],
         ('release-R57-9202.B', '/buildroot', '/git-cache')),
    )

    for cmd_args, expected in CASES:
      expected_branch, expected_buildroot, expected_cache_dir = expected

      options = cbuildbot_launch.PreParseArguments(cmd_args)

      self.assertEqual(options.branch, expected_branch)
      self.assertEqual(options.buildroot, expected_buildroot)
      self.assertEqual(options.git_cache_dir, expected_cache_dir)

  def testInitialCheckout(self):
    """Test InitialCheckout with minimum settings."""
    mock_repo = mock.MagicMock()
    mock_repo.branch = 'branch'

    cbuildbot_launch.InitialCheckout(mock_repo)

    self.assertEqual(mock_repo.mock_calls, [
        mock.call.Sync(detach=True),
    ])

  def testConfigureGlobalEnvironment(self):
    """Ensure that we can setup our global runtime environment correctly."""

    os.environ.pop('LANG', None)
    os.environ['LC_MONETARY'] = 'bad'

    cbuildbot_launch.ConfigureGlobalEnvironment()

    # Verify umask is updated.
    self.assertEqual(os.umask(0), 0o22)

    # Verify ENVs are cleaned up.
    self.assertEqual(os.environ['LANG'], 'en_US.UTF-8')
    self.assertNotIn('LC_MONETARY', os.environ)


class RunTests(cros_build_lib_unittest.RunCommandTestCase):
  """Tests for cbuildbot_launch script."""

  ARGS_BASE = ['--buildroot', '/buildroot']
  ARGS_GIT_CACHE = ['--git-cache-dir', '/git-cache']
  ARGS_CONFIG = ['config']
  CMD = ['/buildroot/chromite/bin/cbuildbot']

  def verifyRunCbuildbot(self, args, expected_cmd, version):
    """Ensure we invoke cbuildbot correctly."""
    options = cbuildbot_launch.PreParseArguments(args)

    self.PatchObject(
        cros_build_lib, 'GetTargetChromiteApiVersion', autospec=True,
        return_value=version)

    cbuildbot_launch.RunCbuildbot(options)

    self.assertCommandCalled(
        expected_cmd, cwd=options.buildroot, error_code_ok=True)

  def testRunCbuildbotSimple(self):
    """Ensure we invoke cbuildbot correctly."""
    self.verifyRunCbuildbot(
        self.ARGS_BASE + self.ARGS_CONFIG,
        self.CMD + self.ARGS_CONFIG + self.ARGS_BASE,
        (0, 4))

  def testRunCbuildbotNotFiltered(self):
    """Ensure we invoke cbuildbot correctly."""
    self.verifyRunCbuildbot(
        self.ARGS_BASE + self.ARGS_CONFIG + self.ARGS_GIT_CACHE,
        self.CMD + self.ARGS_CONFIG + self.ARGS_BASE + self.ARGS_GIT_CACHE,
        (0, 4))

  def testRunCbuildbotFiltered(self):
    """Ensure we invoke cbuildbot correctly."""
    self.verifyRunCbuildbot(
        self.ARGS_BASE + self.ARGS_CONFIG + self.ARGS_GIT_CACHE,
        self.CMD + self.ARGS_CONFIG + self.ARGS_BASE,
        (0, 2))

  def testMainMin(self):
    """Test a minimal set of command line options."""
    self.PatchObject(osutils, 'SafeMakedirs', autospec=True)
    self.PatchObject(cros_build_lib, 'GetTargetChromiteApiVersion',
                     autospec=True, return_value=(constants.REEXEC_API_MAJOR,
                                                  constants.REEXEC_API_MINOR))
    mock_repo = mock.MagicMock()
    mock_repo.branch = 'master'
    mock_repo_create = self.PatchObject(repository, 'RepoRepository',
                                        autospec=True, return_value=mock_repo)
    mock_clean = self.PatchObject(cbuildbot_launch, 'CleanBuildroot',
                                  autospec=True)
    mock_checkout = self.PatchObject(cbuildbot_launch, 'InitialCheckout',
                                     autospec=True)

    cbuildbot_launch._main(['--buildroot', '/buildroot', 'config'])

    # Did we create the repo instance correctly?
    self.assertEqual(mock_repo_create.mock_calls,
                     [mock.call(EXPECTED_MANIFEST_URL, '/buildroot',
                                git_cache_dir=None, branch='master')])

    # Ensure we clean, as expected.
    self.assertEqual(mock_clean.mock_calls,
                     [mock.call('/buildroot', mock_repo,
                                {'branch_name': 'master'})])

    # Ensure we checkout, as expected.
    self.assertEqual(mock_checkout.mock_calls,
                     [mock.call(mock_repo)])

    # Ensure we invoke cbuildbot, as expected.
    self.assertCommandCalled(
        ['/buildroot/chromite/bin/cbuildbot',
         'config', '--buildroot', '/buildroot'],
        cwd='/buildroot',
        error_code_ok=True)

  def testMainMax(self):
    """Test a larger set of command line options."""
    self.PatchObject(osutils, 'SafeMakedirs', autospec=True)
    self.PatchObject(cros_build_lib, 'GetTargetChromiteApiVersion',
                     autospec=True, return_value=(constants.REEXEC_API_MAJOR,
                                                  constants.REEXEC_API_MINOR))
    mock_repo = mock.MagicMock()
    mock_repo.branch = 'branch'
    mock_repo_create = self.PatchObject(repository, 'RepoRepository',
                                        autospec=True, return_value=mock_repo)
    mock_clean = self.PatchObject(cbuildbot_launch, 'CleanBuildroot',
                                  autospec=True)
    mock_checkout = self.PatchObject(cbuildbot_launch, 'InitialCheckout',
                                     autospec=True)

    cbuildbot_launch._main(['--buildroot', '/buildroot',
                            '--branch', 'branch',
                            '--git-cache-dir', '/git-cache',
                            'config'])

    # Did we create the repo instance correctly?
    self.assertEqual(mock_repo_create.mock_calls,
                     [mock.call(EXPECTED_MANIFEST_URL, '/buildroot',
                                git_cache_dir='/git-cache', branch='branch')])

    # Ensure we clean, as expected.
    self.assertEqual(mock_clean.mock_calls,
                     [mock.call('/buildroot', mock_repo,
                                {'branch_name': 'branch'})])

    # Ensure we checkout, as expected.
    self.assertEqual(mock_checkout.mock_calls,
                     [mock.call(mock_repo)])

    # Ensure we invoke cbuildbot, as expected.
    self.assertCommandCalled(
        ['/buildroot/chromite/bin/cbuildbot',
         'config',
         '--buildroot', '/buildroot',
         '--branch', 'branch',
         '--git-cache-dir', '/git-cache'],
        cwd='/buildroot',
        error_code_ok=True)


class CleanBuildrootTest(cros_test_lib.MockTempDirTestCase):
  """Tests for CleanBuildroot method."""

  def setUp(self):
    """Create standard buildroot contents for cleanup."""
    self.root = os.path.join(self.tempdir, 'buildroot')
    self.state = os.path.join(self.root, '.cbuildbot_launch_state')
    self.repo = os.path.join(self.root, '.repo/repo')
    self.chroot = os.path.join(self.root, 'chroot/chroot')
    self.general = os.path.join(self.root, 'general/general')
    # TODO: Add .cache, and distfiles.

    self.mock_repo = mock.MagicMock()

    self.metrics = {}

  def populateBuildroot(self, state=None):
    """Create standard buildroot contents for cleanup."""
    osutils.SafeMakedirs(self.root)

    if state:
      osutils.WriteFile(self.state, state)

    # Create files.
    for f in (self.repo, self.chroot, self.general):
      osutils.Touch(f, makedirs=True)

  def testNoBuildroot(self):
    """Test CleanBuildroot with no history."""
    self.mock_repo.branch = 'master'

    cbuildbot_launch.CleanBuildroot(self.root, self.mock_repo, self.metrics)

    self.assertEqual(osutils.ReadFile(self.state), '1 master')

  def testBuildrootNoState(self):
    """Test CleanBuildroot with no state information."""
    self.populateBuildroot()
    self.mock_repo.branch = 'master'

    cbuildbot_launch.CleanBuildroot(self.root, self.mock_repo, self.metrics)

    self.assertEqual(osutils.ReadFile(self.state), '1 master')
    self.assertNotExists(self.repo)
    self.assertNotExists(self.chroot)
    self.assertNotExists(self.general)

  def testBuildrootFormatMismatch(self):
    """Test CleanBuildroot with no state information."""
    self.populateBuildroot('0 master')
    self.mock_repo.branch = 'master'

    cbuildbot_launch.CleanBuildroot(self.root, self.mock_repo, self.metrics)

    self.assertEqual(osutils.ReadFile(self.state), '1 master')
    self.assertNotExists(self.repo)
    self.assertNotExists(self.chroot)
    self.assertNotExists(self.general)

  def testBuildrootBranchChange(self):
    """Test CleanBuildroot with a change in branches."""
    self.populateBuildroot('1 branchA')
    self.mock_repo.branch = 'branchB'

    cbuildbot_launch.CleanBuildroot(self.root, self.mock_repo, self.metrics)

    self.assertEqual(osutils.ReadFile(self.state), '1 branchB')
    self.assertExists(self.repo)
    self.assertNotExists(self.chroot)
    self.assertExists(self.general)

  def testBuildrootBranchMatch(self):
    """Test CleanBuildroot with no change in branch."""
    self.populateBuildroot('1 branchA')
    self.mock_repo.branch = 'branchA'

    cbuildbot_launch.CleanBuildroot(self.root, self.mock_repo, self.metrics)

    self.assertEqual(osutils.ReadFile(self.state), '1 branchA')
    self.assertExists(self.repo)
    self.assertExists(self.chroot)
    self.assertExists(self.general)

  def testBuildrootRepoCleanFailure(self):
    """Test CleanBuildroot with repo checkout failure."""
    self.populateBuildroot('1 branchA')
    self.mock_repo.branch = 'branchA'
    self.mock_repo.BuildRootGitCleanup.side_effect = Exception

    cbuildbot_launch.CleanBuildroot(self.root, self.mock_repo, self.metrics)

    self.assertEqual(osutils.ReadFile(self.state), '1 branchA')
    self.assertNotExists(self.repo)
    self.assertNotExists(self.chroot)
    self.assertNotExists(self.general)

  def testGetBuildrootState(self):
    """Test GetBuildrootState."""
    # No root dir.
    results = cbuildbot_launch.GetBuildrootState(self.root)
    self.assertEqual(results, (0, ''))

    # Empty root dir.
    osutils.SafeMakedirs(self.root)
    results = cbuildbot_launch.GetBuildrootState(self.root)
    self.assertEqual(results, (0, ''))

    # Empty Contents
    osutils.WriteFile(self.state, '')
    results = cbuildbot_launch.GetBuildrootState(self.root)
    self.assertEqual(results, (0, ''))

    # Old Format Contents
    osutils.WriteFile(self.state, 'happy-branch')
    results = cbuildbot_launch.GetBuildrootState(self.root)
    self.assertEqual(results, (0, ''))

    # Expected Contents
    osutils.WriteFile(self.state, '1 happy-branch')
    results = cbuildbot_launch.GetBuildrootState(self.root)
    self.assertEqual(results, (1, 'happy-branch'))

    # Future Contents
    osutils.WriteFile(self.state, '22 master')
    results = cbuildbot_launch.GetBuildrootState(self.root)
    self.assertEqual(results, (22, 'master'))

    # Read Write
    cbuildbot_launch.SetBuildrootState('happy-branch', self.root)
    results = cbuildbot_launch.GetBuildrootState(self.root)
    self.assertEqual(results, (1, 'happy-branch'))

  def testSetBuildrootState(self):
    """Test SetBuildrootState."""
    # Write out a state file.
    osutils.SafeMakedirs(self.root)
    cbuildbot_launch.SetBuildrootState('happy-branch', self.root)
    self.assertEqual(osutils.ReadFile(self.state), '1 happy-branch')

    # Change to a future version.
    self.PatchObject(cbuildbot_launch, 'BUILDROOT_BUILDROOT_LAYOUT', 22)
    cbuildbot_launch.SetBuildrootState('happy-branch', self.root)
    self.assertEqual(osutils.ReadFile(self.state), '22 happy-branch')
