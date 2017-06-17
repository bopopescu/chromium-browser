# Copyright 2016 The Chromium OS Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

"""Bootstrap for cbuildbot.

This script is intended to checkout chromite on the branch specified by -b or
--branch (as normally accepted by cbuildbot), and then invoke cbuildbot. Most
arguments are not parsed, only passed along. If a branch is not specified, this
script will use 'master'.

Among other things, this allows us to invoke build configs that exist on a given
branch, but not on TOT.
"""

from __future__ import print_function

import os

from chromite.cbuildbot import repository
from chromite.cbuildbot.stages import sync_stages
from chromite.lib import config_lib
from chromite.lib import cros_build_lib
from chromite.lib import cros_logging as logging
from chromite.lib import osutils
from chromite.scripts import cbuildbot


def PreParseArguments(argv):
  """Extract the branch name from cbuildbot command line arguments.

  Ignores all arguments, other than the branch name.

  Args:
    argv: The command line arguments to parse.

  Returns:
    Branch as a string ('master' if nothing is specified).
  """
  parser = cbuildbot.CreateParser()
  options, args = cbuildbot.ParseCommandLine(parser, argv)

  # This option isn't required for cbuildbot, but is for us.
  if not options.buildroot:
    cros_build_lib.Die('--buildroot is a required option.')

  # Save off the build targets, in a mirror of cbuildbot code.
  options.build_targets = args
  options.Freeze()

  return options


def CleanBuildroot(branchname, buildroot):
  """Some kinds of branch transitions break builds.

  This method tries to detect cases where that can happen, and clobber what's
  needed to succeed. However, the clobbers are costly, and should be avoided
  if necessary.

  Currently, we only check to see if we are moving between branches, but
  other checks can be added, as needed.

  Args:
    branchname: Name of branch to checkout. None for no branch.
    buildroot: Directory with old buildroot to clean as needed.
  """
  # Cleanups to consider, in order of severity.
  #   1) osutils.RmDir('chroot')
  #   2) osutils.RmDir('.cache')
  #   3) EmptyDir(buildroot, excludes=['.repo'])
  #   4) EmptyDir(buildroot)

  state_file = os.path.join(buildroot, '.cbuildbot_launch_state')
  new_state = branchname or 'TOT'

  try:
    old_state = osutils.ReadFile(state_file)
  except IOError:
    old_state = None

  if old_state != new_state:
    # If we are changing branches, clobber the chroot. Note that this chroot
    # clobber is unsafe if the chroot is in use, but since no build is in
    # progress (and we don't use chroot the), this should be okay.
    logging.info(
        'Unmatched buildroot state, wipe chroot/Chrome Checkout: %s -> %s',
        old_state, new_state)

    # Wipe chroot.
    osutils.RmDir(os.path.join(buildroot, 'chroot'),
                  ignore_missing=True, sudo=True)

    # Wipe Chrome build related files.
    osutils.RmDir(os.path.join(buildroot, '.cache', 'distfiles'),
                  ignore_missing=True, sudo=True)

  # Finished!
  osutils.WriteFile(state_file, new_state)


def InitialCheckout(branchname, buildroot, git_cache_dir):
  """Preliminary ChromeOS checkout.

  Perform a complete checkout of ChromeOS on the specified branch. This does NOT
  match what the build needs, but ensures the buildroot both has a 'hot'
  checkout, and is close enough that the branched cbuildbot can successfully get
  the right checkout.

  This checks out full ChromeOS, even if a ChromiumOS build is going to be
  performed. This is because we have no knowledge of the build config to be
  used.

  Args:
    branchname: Name of branch to checkout. None for no branch.
    buildroot: Directory to checkout into.
    git_cache_dir: Directory to use for git cache. None to not use it.
  """
  logging.info('Bootstrap script starting initial sync on branch: %s',
               branchname)

  site_config = config_lib.GetConfig()
  manifest_url = site_config.params['MANIFEST_INT_URL']

  repo = repository.RepoRepository(manifest_url, buildroot,
                                   branch=branchname,
                                   git_cache_dir=git_cache_dir)
  repo.Sync()


def RunCbuildbot(options):
  """Start cbuildbot in specified directory with all arguments.

  Args:
    options: Parse command line options.

  Returns:
    Return code of cbuildbot as an integer.
  """
  logging.info('Bootstrap cbuildbot in: %s', options.buildroot)
  cbuildbot_path = os.path.join(
      options.buildroot, 'chromite', 'bin', 'cbuildbot')

  cmd = sync_stages.BootstrapStage.FilterArgsForTargetCbuildbot(
      options.buildroot, cbuildbot_path, options)

  result = cros_build_lib.RunCommand(
      cmd, error_code_ok=True, cwd=options.buildroot)

  logging.debug('cbuildbot result is: %s', result.returncode)
  return result.returncode


def main(argv):
  """main method of script.

  Args:
    argv: All command line arguments to pass as list of strings.

  Returns:
    Return code of cbuildbot as an integer.
  """
  # Specified branch, or 'master'
  options = PreParseArguments(argv)

  branchname = options.branch
  buildroot = options.buildroot
  git_cache_dir = options.git_cache_dir

  # Ensure buildroot exists.
  osutils.SafeMakedirs(buildroot)

  # Sometimes, we have to cleanup things that can break cbuildbot, especially
  # on the branch.
  CleanBuildroot(branchname, buildroot)

  # Get a checkout close enough the branched cbuildbot can handle it.
  InitialCheckout(branchname, buildroot, git_cache_dir)

  # Run cbuildbot inside the full ChromeOS checkout, on the specified branch.
  return RunCbuildbot(options)
