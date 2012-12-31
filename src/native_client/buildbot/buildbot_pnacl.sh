#!/bin/bash
# Copyright (c) 2012 The Native Client Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

set -o xtrace
set -o nounset
set -o errexit

# Tell build.sh and test.sh that we're a bot.
export PNACL_BUILDBOT=true
# Make TC bots print all log output to console (this variable only affects
# build.sh output)
export PNACL_VERBOSE=true

# This affects trusted components of gyp and scons builds.
# The setting OPT reuslts in optimized/release trusted executables,
# the setting DEBUG results in unoptimized/debug trusted executables
BUILD_MODE_HOST=OPT
# If true, terminate script when first scons error is encountered.
FAIL_FAST=${FAIL_FAST:-true}
# This remembers when any build steps failed, but we ended up continuing.
RETCODE=0
# for scons builds an empty target indicates all targets should be build
# this does not run any tests, though
readonly SCONS_EVERYTHING=""
readonly SCONS_S_M_L="small_tests medium_tests large_tests"
# subset of tests used on toolchain builders
readonly SCONS_TC_TESTS="small_tests medium_tests large_tests"

readonly SCONS_COMMON="./scons --verbose bitcode=1"
readonly UP_DOWN_LOAD="buildbot/file_up_down_load.sh"
# This script is used by toolchain bots (i.e. tc-xxx functions)
readonly PNACL_BUILD="pnacl/build.sh"
readonly ACCEPTABLE_TOOLCHAIN_SIZE_MB=50

tc-clobber() {
  local label=$1
  local clobber_translators=$2

  echo @@@BUILD_STEP tc_clobber@@@
  rm -rf toolchain/${label}
  rm -rf toolchain/test-log
  rm -rf pnacl*.tgz pnacl/pnacl*.tgz
  if ${clobber_translators} ; then
      rm -rf toolchain/pnacl_translator
  fi
}

tc-show-config() {
  echo @@@BUILD_STEP show_config@@@
  ${PNACL_BUILD} show-config
}

tc-compile-toolchain() {
  echo @@@BUILD_STEP compile_toolchain@@@
  ${PNACL_BUILD} clean
  ${PNACL_BUILD} everything
  ${PNACL_BUILD} tarball pnacl-toolchain.tgz
  chmod a+r pnacl-toolchain.tgz

  # Size sanity check
  local byte_size=$(wc -c < pnacl-toolchain.tgz)
  local max_size=$((1024 * 1024 * ${ACCEPTABLE_TOOLCHAIN_SIZE_MB}))
  if [[ ${byte_size} -gt ${max_size} ]] ; then
      echo "ERROR: toolchain tarball is too large: ${byte_size} > ${max_size}"
      handle-error
  fi
}

tc-untar-toolchain() {
  local label=$1
  echo @@@BUILD_STEP untar_toolchain@@@
  # Untar to ensure we can and to place the toolchain where the main build
  # expects it to be.
  rm -rf toolchain/${label}
  mkdir -p toolchain/${label}
  pushd toolchain/${label}
  tar xfz ../../pnacl-toolchain.tgz
  popd
}

tc-build-translator() {
  echo @@@BUILD_STEP compile_translator@@@
  ${PNACL_BUILD} translator-clean-all
  ${PNACL_BUILD} translator-all
}

tc-add-glibc-support() {
  echo @@@BUILD_STEP add_glibc_support@@@
  ${PNACL_BUILD} glibc-all
}

tc-archive() {
  local label=$1
  echo @@@BUILD_STEP archive_toolchain@@@
  ${UP_DOWN_LOAD} UploadArmUntrustedToolchains ${BUILDBOT_GOT_REVISION} \
    ${label} pnacl-toolchain.tgz
}

tc-archive-translator-pexes() {
  echo @@@BUILD_STEP archive_translator_pexe@@@
  # NOTE: the build script needs an absolute pathname
  local tarball="$(pwd)/pnacl-translator-pexe.tar.bz2"
  ${PNACL_BUILD} translator-archive-universal-pexes ${tarball}
  ${UP_DOWN_LOAD} UploadArchivedPexesTranslator \
      ${BUILDBOT_GOT_REVISION} ${tarball}
}

tc-archive-translator() {
  echo @@@BUILD_STEP archive_translator@@@
  ${PNACL_BUILD} translator-tarball pnacl-translator.tgz
  ${UP_DOWN_LOAD} UploadArmUntrustedToolchains ${BUILDBOT_GOT_REVISION} \
      pnacl_translator pnacl-translator.tgz
}

tc-build-all() {
  local label=$1
  local is_try=$2
  local build_translator=$3
  local build_glibc=$3

  # Tell build.sh and test.sh that we're a bot.
  export PNACL_BUILDBOT=true
  # Tells build.sh to prune the install directory (for release).
  export PNACL_PRUNE=true

  clobber
  tc-clobber ${label} ${build_translator}
  tc-show-config
  tc-compile-toolchain
  tc-untar-toolchain ${label}
  if ! ${is_try} ; then
    tc-archive ${label}
  fi

  # NOTE: only one bot needs to do this
  if ${build_translator} ; then
    tc-build-translator
    if ! ${is_try} ; then
      tc-archive-translator-pexes
      tc-archive-translator
    fi
  fi

  if ${build_glibc} ; then
    tc-add-glibc-support
  fi

}


# extract the relevant scons flags for reporting
relevant() {
  for i in "$@" ; do
    case $i in
      nacl_pic=1)
        echo -n "pic "
        ;;
      use_sandboxed_translator=1)
        echo -n "sbtc "
        ;;
      do_not_run_tests=1)
        echo -n "no_tests "
        ;;
      pnacl_generate_pexe=0)
        echo -n "no_pexe "
        ;;
      --nacl_glibc)
        echo -n "glibc "
        ;;
    esac
  done
}

# called when a scons invocation fails
handle-error() {
  RETCODE=1
  echo "@@@STEP_FAILURE@@@"
  if ${FAIL_FAST} ; then
    echo "FAIL_FAST enabled"
    exit 1
  fi
}

clobber-chrome-tmp() {
  # Try to clobber /tmp/ contents to clear temporary chrome files.
  rm -rf /tmp/.org.chromium.Chromium.*

  # On Windows we may have additional files left by chrome/pepper's
  # StreamToFile-style url requests.  These are files with names like
  # 1AB9.tmp in the windows %TEMP% or %TMP%. Clobber these too.
  # See: http://code.google.com/p/nativeclient/issues/detail?id=1981
  #
  # Here, we assume that the buildbot script is running Cygwin...
  # In Cygwin, $TEMP is not equal to %TEMP%, because Cygwin overrides
  # $TEMP to be /tmp.  Meanwhile, windows chrome uses %TEMP%.
  # Long story short, we do a hack and check for for $LOCALAPPDATA\Temp\
  # which is the closest thing to %TEMP% (at least the default) that we can
  # access from within Cygwin.
  if [[ "$(uname -s)" =~ CYGWIN ]]; then
    find ${LOCALAPPDATA}/Temp -regex ".*[0-9a-fA-F]+\.tmp" -print0 | \
      xargs -0 rm -rf
  fi
}

# Clear out object, and temporary directories.
clobber() {
  echo "@@@BUILD_STEP clobber@@@"
  rm -rf scons-out ../xcodebuild ../sconsbuild ../out
}

# Generate filenames for arm bot uploads and downloads
NAME_ARM_UPLOAD() {
  echo -n "${BUILDBOT_BUILDERNAME}/${BUILDBOT_GOT_REVISION}"
}

NAME_ARM_DOWNLOAD() {
  echo -n "${BUILDBOT_TRIGGERED_BY_BUILDERNAME}/${BUILDBOT_GOT_REVISION}"
}

NAME_ARM_TRY_UPLOAD() {
  echo -n "${BUILDBOT_BUILDERNAME}/"
  echo -n "${BUILDBOT_SLAVENAME}/"
  echo -n "${BUILDBOT_BUILDNUMBER}"
}
NAME_ARM_TRY_DOWNLOAD() {
  echo -n "${BUILDBOT_TRIGGERED_BY_BUILDERNAME}/"
  echo -n "${BUILDBOT_TRIGGERED_BY_SLAVENAME}/"
  echo -n "${BUILDBOT_TRIGGERED_BY_BUILDNUMBER}"
}


prune-scons-out() {
  find scons-out/ \
    \( -name '*.o' -o -name '*.bc' -o -name 'test_results' \) \
    -print0 | xargs -0 rm -rf
}

# Tar up the executables which are shipped to the arm HW bots
archive-for-hw-bots() {
  local name=$1
  local try=$2

  echo "@@@BUILD_STEP tar_generated_binaries@@@"
  prune-scons-out

  # delete nexes from pexe mode directories to force translation
  # TODO(dschuff) enable this once we can translate on the hw bots
  #find scons-out/*pexe*/ -name '*.nexe' -print0 | xargs -0 rm -f
  tar cvfz arm-scons.tgz scons-out/*arm*

  echo "@@@BUILD_STEP archive_binaries@@@"
  if [[ ${try} == "try" ]] ; then
    ${UP_DOWN_LOAD} UploadArmBinariesForHWBotsTry ${name} arm-scons.tgz
  else
    ${UP_DOWN_LOAD} UploadArmBinariesForHWBots ${name} arm-scons.tgz
  fi
}

# Untar archived executables for HW bots
unarchive-for-hw-bots() {
  local name=$1
  local try=$2

  echo "@@@BUILD_STEP fetch_binaries@@@"
  if [[ ${try} == "try" ]] ; then
    ${UP_DOWN_LOAD} DownloadArmBinariesForHWBotsTry ${name} arm-scons.tgz
  else
    ${UP_DOWN_LOAD} DownloadArmBinariesForHWBots ${name} arm-scons.tgz
  fi

  echo "@@@BUILD_STEP untar_binaries@@@"
  rm -rf scons-out/
  tar xvfz arm-scons.tgz --no-same-owner
}

# Build with gyp - this only exercises the trusted TC and hence this only
# makes sense to run for ARM.
gyp-arm-build() {
  local gypmode="Release"
  if [ "${BUILD_MODE_HOST}" = "DEBUG" ] ; then
      gypmode="Debug"
  fi
  local toolchain_dir=native_client/toolchain/linux_arm-trusted
  local extra="-isystem ${toolchain_dir}/usr/include \
               -Wl,-rpath-link=${toolchain_dir}/lib/arm-linux-gnueabi \
               -L${toolchain_dir}/lib \
               -L${toolchain_dir}/lib/arm-linux-gnueabi \
               -L${toolchain_dir}/usr/lib \
               -L${toolchain_dir}/usr/lib/arm-linux-gnueabi"
  # Setup environment for arm.

  export AR=arm-linux-gnueabi-ar
  export AS=arm-linux-gnueabi-as
  export CC="arm-linux-gnueabi-gcc-4.5 ${extra} "
  export CXX="arm-linux-gnueabi-g++-4.5 ${extra} "
  export LD=arm-linux-gnueabi-ld
  export RANLIB=arm-linux-gnueabi-ranlib
  export SYSROOT
  export GYP_DEFINES="target_arch=arm \
    sysroot=${toolchain_dir} \
    linux_use_tcmalloc=0 armv7=1 arm_thumb=1"
  export GYP_GENERATOR=make

  # NOTE: this step is also run implicitly as part of
  #        gclient runhooks --force
  #       it uses the exported env vars so we have to run it again
  #
  echo "@@@BUILD_STEP gyp_configure [${gypmode}]@@@"
  cd ..
  native_client/build/gyp_nacl native_client/build/all.gyp
  cd native_client

  echo "@@@BUILD_STEP gyp_compile [${gypmode}]@@@"
  make -C .. -k -j8 V=1 BUILDTYPE=${gypmode}
}

build-sbtc-prerequisites() {
  local platform=$1
  # Sandboxed translators currently only require irt_core since they do not
  # use PPAPI.
  ${SCONS_COMMON} platform=${platform} sel_ldr sel_universal irt_core
}

# Run a single invocation of scons as its own buildbot stage and handle errors
scons-stage-irt() {
  local platform=$1
  local extra=$2
  local test=$3
  local info="$(relevant ${extra})"
  # TODO(robertm): do we really need both nacl and nacl_irt_test
  local mode="--mode=opt-host,nacl,nacl_irt_test"
  if [ "${BUILD_MODE_HOST}" = "DEBUG" ] ; then
      mode="--mode=dbg-host,nacl,nacl_irt_test"
  fi

  echo "@@@BUILD_STEP scons-irt [${platform}] [${test}] [${info}]@@@"
  ${SCONS_COMMON} ${extra} ${mode} platform=${platform} ${test} || handle-error
}

# Run a single invocation of scons as its own buildbot stage and handle errors
scons-stage-noirt() {
  local platform=$1
  local extra=$2
  local test=$3
  local info="$(relevant ${extra})"
  local mode="--mode=opt-host,nacl"
  if [ "${BUILD_MODE_HOST}" = "DEBUG" ] ; then
      mode="--mode=dbg-host,nacl"
  fi

  echo "@@@BUILD_STEP scons [${platform}] [${test}] [${info}]@@@"
  ${SCONS_COMMON} ${extra} ${mode} platform=${platform} ${test} || handle-error
}

single-browser-test() {
  local platform=$1
  local extra=$2
  local test=$3

  # if we run mulitple browser test (e.g. on toolchain bots) we
  # may run out of quota without this
  clobber-chrome-tmp

  # Build in parallel (assume -jN specified in extra), but run sequentially.
  # If we do not run tests sequentially, some may fail. E.g.,
  # http://code.google.com/p/nativeclient/issues/detail?id=2019
  scons-stage-irt ${platform} \
    "${extra} browser_headless=1 SILENT=1 do_not_run_tests=1" ${test}

  #TODO(dschuff): remove this when streaming is the default
  export NACL_STREAMING_TRANSLATION=true
  scons-stage-irt ${platform} "${extra} browser_headless=1 SILENT=1 -j1" \
      ${test}
}

browser-tests() {
  local platform=$1
  local extra=$2
  if [[ "${extra}" =~ --nacl_glibc ]]; then
    # For glibc, only non-pexe mode works for now.
    # We need to ensure psos are translated before running.
    # E.g., run_pm_manifest_file_chrome_browser_test relies on
    # libimc, libweak_ref, etc.
    single-browser-test ${platform} "${extra} pnacl_generate_pexe=0" \
        "chrome_browser_tests"
  else
    # Otherwise, try pexe mode.
    # Use streaming translator. TODO(dschuff): remove this when env var
    # goes away in Chrome and we use it by default
    # BUG=http://code.google.com/p/nativeclient/issues/detail?id=2195
    export NACL_STREAMING_TRANSLATION
    single-browser-test ${platform} "${extra}" "chrome_browser_tests"
  fi
}

# This function is shared between x86-32 and x86-64. All building and testing
# is done on the same bot. Try runs are identical to buildbot runs
#
# Note: unlike its arm counterparts we do not run trusted tests on these bots.
# Trusted tests get plenty of coverage by other bots, e.g. nacl-gcc bots.
# We make the assumption here that there are no "exotic tests" which
# are trusted in nature but are somehow depedent on the untrusted TC.
mode-buildbot-x86() {
  local arch="x86-$1"
  FAIL_FAST=false
  clobber

  local flags_build="skip_trusted_tests=1 -k -j8 do_not_run_tests=1"
  local flags_run="skip_trusted_tests=1 -k -j4"
  # Normal pexe tests. Build all targets, then run (-j4 is a compromise to try
  # to reduce cycle times without making output too difficult to follow)
  # We also intentionally build more than we run for "coverage".
  # specifying "" as the target which means "build everything"

  scons-stage-noirt "${arch}" "${flags_build}" "${SCONS_EVERYTHING}"
  scons-stage-noirt "${arch}" "${flags_run}"   "${SCONS_S_M_L}"

  # non-pexe tests (Do the build-everything step just to make sure it all still
  # builds as non-pexe)
  scons-stage-noirt "${arch}" "${flags_build} pnacl_generate_pexe=0" \
      "${SCONS_EVERYTHING}"
  scons-stage-noirt "${arch}" "${flags_run} pnacl_generate_pexe=0" \
      "nonpexe_tests"

  # also run some tests with the irt
  scons-stage-irt "${arch}" "${flags_run}" "small_tests_irt"

  # PIC
  scons-stage-noirt "${arch}" "${flags_build} nacl_pic=1 pnacl_generate_pexe=0" \
      "${SCONS_EVERYTHING}"
  scons-stage-noirt "${arch}" "${flags_run} nacl_pic=1 pnacl_generate_pexe=0" \
      "${SCONS_S_M_L}"

  # sandboxed translation
  build-sbtc-prerequisites ${arch}
  scons-stage-noirt "${arch}" "${flags_build} use_sandboxed_translator=1" \
      "${SCONS_EVERYTHING}"
  scons-stage-noirt "${arch}" "${flags_run} use_sandboxed_translator=1" \
      "${SCONS_S_M_L}"

  browser-tests "${arch}" "-j8 -k"
}

# QEMU upload bot runs this function, and the hardware download bot runs
# mode-buildbot-arm-hw
mode-buildbot-arm() {
  FAIL_FAST=false
  local qemuflags="-j8 -k do_not_run_tests=1"

  clobber

  gyp-arm-build

  # Sanity check
  scons-stage-noirt "arm" "" "run_hello_world_test"

  # Don't run the rest of the tests on qemu, only build them.
  # QEMU is too flaky for the main waterfall

  # Normal pexe mode tests
  scons-stage-noirt "arm" "${qemuflags}" "${SCONS_EVERYTHING}"
  # This extra step is required to translate the pexes (because translation
  # happens as part of CommandSelLdrTestNacl and not part of the
  # build-everything step)
  scons-stage-noirt "arm" "${qemuflags}" "${SCONS_S_M_L}"

  # also run some tests with the irt
  scons-stage-irt "arm" "${qemuflags}" "small_tests_irt"

  # PIC
  # Don't bother to build everything here, just the tests we want to run
  scons-stage-noirt "arm" "${qemuflags} nacl_pic=1 pnacl_generate_pexe=0" \
    "${SCONS_S_M_L}"

  # non-pexe-mode tests
  scons-stage-noirt "arm" "${qemuflags} pnacl_generate_pexe=0" "nonpexe_tests"

  build-sbtc-prerequisites "arm"

  scons-stage-noirt "arm" \
    "${qemuflags} use_sandboxed_translator=1 translate_in_build_step=0" \
    "toolchain_tests"

  browser-tests "arm" ""
}

mode-buildbot-arm-hw() {
  FAIL_FAST=false
  local hwflags="-j2 -k naclsdk_validate=0 built_elsewhere=1"

  scons-stage-noirt "arm" "${hwflags}" "${SCONS_S_M_L}"
  scons-stage-noirt "arm" "${hwflags} nacl_pic=1 pnacl_generate_pexe=0" \
    "${SCONS_S_M_L}"

  # also run some tests with the irt
  scons-stage-irt "arm" "${hwflags}" "small_tests_irt"

  scons-stage-noirt "arm" "${hwflags} pnacl_generate_pexe=0" "nonpexe_tests"
  scons-stage-noirt "arm" \
    "${hwflags} use_sandboxed_translator=1 translate_in_build_step=0" \
    "toolchain_tests"
  browser-tests "arm" "${hwflags}"
}

mode-trybot-qemu() {
  # Build and actually run the arm tests under qemu, except
  # sandboxed translation. Hopefully that's a good tradeoff between
  # flakiness and cycle time.
  FAIL_FAST=false
  local qemuflags="-j4 -k"
  clobber
  gyp-arm-build

  scons-stage-noirt "arm" "${qemuflags}" "${SCONS_EVERYTHING}"
  scons-stage-noirt "arm" "${qemuflags} -j1" "${SCONS_S_M_L}"

  # also run some tests with the irt
  scons-stage-irt "arm" "${qemuflags}" "small_tests_irt"

  scons-stage-noirt "arm" "${qemuflags} nacl_pic=1 pnacl_generate_pexe=0" \
      "${SCONS_EVERYTHING}"
  scons-stage-noirt "arm" "${qemuflags} -j1 nacl_pic=1 pnacl_generate_pexe=0" \
      "${SCONS_S_M_L}"

  # non-pexe tests
  scons-stage-noirt "arm" "${qemuflags} pnacl_generate_pexe=0" "nonpexe_tests"
}

mode-buildbot-arm-dbg() {
  BUILD_MODE_HOST=DEDUG
  mode-buildbot-arm
  archive-for-hw-bots $(NAME_ARM_UPLOAD) regular
}

mode-buildbot-arm-opt() {
  mode-buildbot-arm
  archive-for-hw-bots $(NAME_ARM_UPLOAD) regular
}

mode-buildbot-arm-try() {
  mode-buildbot-arm
  archive-for-hw-bots $(NAME_ARM_TRY_UPLOAD) try
}

# NOTE: the hw bots are too slow to build stuff on so we just
#       use pre-built executables
mode-buildbot-arm-hw-dbg() {
  BUILD_MODE_HOST=DEDUG
  unarchive-for-hw-bots $(NAME_ARM_DOWNLOAD)  regular
  mode-buildbot-arm-hw
}

mode-buildbot-arm-hw-opt() {
  unarchive-for-hw-bots $(NAME_ARM_DOWNLOAD)  regular
  mode-buildbot-arm-hw
}

mode-buildbot-arm-hw-try() {
  unarchive-for-hw-bots $(NAME_ARM_TRY_DOWNLOAD)  try
  mode-buildbot-arm-hw
}

# These are also suitable for local TC sanity testing
tc-tests-large() {
  local is_try=$1
  local scons_flags="-k skip_trusted_tests=1 -j8"

  # newlib
  scons-stage-noirt "x86-32" "${scons_flags}" "${SCONS_TC_TESTS}"
  scons-stage-noirt "x86-64" "${scons_flags}" "${SCONS_TC_TESTS}"
  scons-stage-noirt "arm"    "${scons_flags}" "${SCONS_TC_TESTS}"

  # glibc
  scons-stage-noirt "x86-32" "${scons_flags} --nacl_glibc pnacl_generate_pexe=0" \
              "${SCONS_TC_TESTS}"
  scons-stage-noirt "x86-64" "${scons_flags} --nacl_glibc pnacl_generate_pexe=0" \
              "${SCONS_TC_TESTS}"

  # we run the browser tests last since they tend to be flaky
  # and will terminate the testing unless  FAIL_FAST=false

  # newlib browser
  browser-tests "x86-32" "-j8 -k"
  browser-tests "x86-64" "-j8 -k"
  browser-tests "arm"    "-j8 -k"

  # glibc browser
  browser-tests "x86-32" "-j8 -k --nacl_glibc"
  browser-tests "x86-64" "-j8 -k --nacl_glibc"
}

tc-tests-small() {
  scons-stage-noirt "$1" "-j8 -k" "${SCONS_TC_TESTS}"
  browser-tests "$1" "-j8 -k"
}

mode-buildbot-tc-x8664-linux() {
  local is_try=$1
  FAIL_FAST=false
  TOOLCHAIN_LABEL=pnacl_linux_x86_64
  tc-build-all ${TOOLCHAIN_LABEL} ${is_try} true true
  tc-tests-large ${is_try}
}

mode-buildbot-tc-x8632-linux() {
  local is_try=$1
  FAIL_FAST=false
  TOOLCHAIN_LABEL=pnacl_linux_x86_32
  tc-build-all ${TOOLCHAIN_LABEL} ${is_try} false false
  tc-tests-small "x86-32"
}

mode-buildbot-tc-x8632-mac() {
  local is_try=$1
  FAIL_FAST=false
  TOOLCHAIN_LABEL=pnacl_mac_x86_32
  # We can't test ARM because we do not have QEMU for Mac.
  # We can't test X86-64 because NaCl X86-64 Mac support is not in good shape.
  tc-build-all ${TOOLCHAIN_LABEL} ${is_try} false false
  tc-tests-small "x86-32"
}

mode-buildbot-tc-x8664-win() {
  local is_try=$1
  FAIL_FAST=false
  # NOTE: this is a 64bit bot but the TC generated is 32bit
  TOOLCHAIN_LABEL=pnacl_win_x86_32
  tc-build-all ${TOOLCHAIN_LABEL} ${is_try} false false

  # On windows-chrome the plugin is always 32bit even though the nexe
  # might be 64bit
  echo @@@BUILD_STEP plugin compile 32@@@
  ./scons --verbose -k -j8 --mode=opt-host,nacl platform=x86-32 plugin

  # We can't test ARM because we do not have QEMU for Win.
  tc-tests-small "x86-64"
}



mode-test-all() {
  test-all-newlib "$@"
  test-all-glibc "$@"
}

# NOTE: clobber and toolchain setup to be done manually, since this is for
# testing a locally built toolchain.
# This runs tests concurrently, so may be more difficult to parse logs.
test-all-newlib() {
  local concur=$1

  # turn verbose mode off
  set +o xtrace

  # At least clobber scons-out before building and running the tests though.
  echo "@@@BUILD_STEP clobber@@@"
  rm -rf scons-out

  # First build everything.
  echo "@@@BUILD_STEP scons build @@@"
  local scons_flags="skip_trusted_tests=1 -j${concur}"
  scons-stage-noirt "arm"    "${scons_flags}" "${SCONS_EVERYTHING}"
  scons-stage-noirt "x86-32" "${scons_flags}" "${SCONS_EVERYTHING}"
  scons-stage-noirt "x86-64" "${scons_flags}" "${SCONS_EVERYTHING}"
  # Then run at least the smoke_tests
  echo "@@@BUILD_STEP scons smoke_tests @@@"
  scons-stage-noirt "arm"    "${scons_flags}" "smoke_tests"
  scons-stage-noirt "x86-32" "${scons_flags}" "smoke_tests"
  scons-stage-noirt "x86-64" "${scons_flags}" "smoke_tests"
  # browser tests.
  browser-tests "arm" "--verbose -j${concur}"
  browser-tests "x86-32" "--verbose -j${concur}"
  browser-tests "x86-64" "--verbose -j${concur}"
}

test-all-glibc() {
  echo "TODO(pdox): Add GlibC tests"
}

######################################################################
# On Windows, this script is invoked from a batch file.
# The inherited PWD environmental variable is a Windows-style path.
# This can cause problems with pwd and bash. This line fixes it.
cd -P .

# Script assumed to be run in native_client/
if [[ $(pwd) != */native_client ]]; then
  echo "ERROR: must be run in native_client!"
  exit 1
fi


if [[ $# -eq 0 ]] ; then
  echo "you must specify a mode on the commandline:"
  exit 1
fi

if [ "$(type -t $1)" != "function" ]; then
  Usage
  echo "ERROR: unknown mode '$1'." >&2
  exit 1
fi

"$@"

if [[ ${RETCODE} != 0 ]]; then
  echo "@@@BUILD_STEP summary@@@"
  echo There were failed stages.
  exit ${RETCODE}
fi
