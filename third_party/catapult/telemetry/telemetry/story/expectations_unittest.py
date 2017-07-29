# Copyright 2017 The Chromium Authors. All rights reserved.
# Use of this source code is governed by a BSD-style license that can be
# found in the LICENSE file.

import unittest

from telemetry.story import expectations
from telemetry.testing import fakes


class MockState(object):
  def __init__(self):
    self.platform = fakes.FakePlatform()


class MockStory(object):
  def __init__(self, name):
    self._name = name

  @property
  def display_name(self):
    return self._name


class MockStorySet(object):
  def __init__(self, stories):
    self._stories = stories

  @property
  def stories(self):
    return self._stories


class TestConditionTest(unittest.TestCase):
  def setUp(self):
    self._platform = fakes.FakePlatform()

  def testAllAlwaysReturnsTrue(self):
    self.assertTrue(expectations.ALL.ShouldDisable(self._platform))

  def testAllWinReturnsTrueOnWindows(self):
    self._platform.SetOSName('win')
    self.assertTrue(expectations.ALL_WIN.ShouldDisable(self._platform))

  def testAllWinReturnsFalseOnOthers(self):
    self._platform.SetOSName('not_windows')
    self.assertFalse(expectations.ALL_WIN.ShouldDisable(self._platform))

  def testAllLinuxReturnsTrueOnLinux(self):
    self._platform.SetOSName('linux')
    self.assertTrue(expectations.ALL_LINUX.ShouldDisable(self._platform))

  def testAllLinuxReturnsFalseOnOthers(self):
    self._platform.SetOSName('not_linux')
    self.assertFalse(expectations.ALL_LINUX.ShouldDisable(self._platform))

  def testAllMacReturnsTrueOnMac(self):
    self._platform.SetOSName('mac')
    self.assertTrue(expectations.ALL_MAC.ShouldDisable(self._platform))

  def testAllMacReturnsFalseOnOthers(self):
    self._platform.SetOSName('not_mac')
    self.assertFalse(expectations.ALL_MAC.ShouldDisable(self._platform))

  def testAllAndroidReturnsTrueOnAndroid(self):
    self._platform.SetOSName('android')
    self.assertTrue(expectations.ALL_ANDROID.ShouldDisable(self._platform))

  def testAllAndroidReturnsFalseOnOthers(self):
    self._platform.SetOSName('not_android')
    self.assertFalse(expectations.ALL_ANDROID.ShouldDisable(self._platform))

  def testAllDesktopReturnsFalseOnNonDesktop(self):
    false_platforms = ['android']
    for plat in false_platforms:
      self._platform.SetOSName(plat)
      self.assertFalse(expectations.ALL_DESKTOP.ShouldDisable(self._platform))

  def testAllDesktopReturnsTrueOnDesktop(self):
    true_platforms = ['win', 'mac', 'linux']
    for plat in true_platforms:
      self._platform.SetOSName(plat)
      self.assertTrue(expectations.ALL_DESKTOP.ShouldDisable(self._platform))

  def testAllMobileReturnsFalseOnNonMobile(self):
    false_platforms = ['win', 'mac', 'linux']
    for plat in false_platforms:
      self._platform.SetOSName(plat)
      self.assertFalse(expectations.ALL_MOBILE.ShouldDisable(self._platform))

  def testAllMobileReturnsTrueOnMobile(self):
    true_platforms = ['android']
    for plat in true_platforms:
      self._platform.SetOSName(plat)
      self.assertTrue(expectations.ALL_MOBILE.ShouldDisable(self._platform))

  def testAndroidNexus5ReturnsFalseOnNotAndroid(self):
    self._platform.SetOSName('not_android')
    self.assertFalse(expectations.ANDROID_NEXUS5.ShouldDisable(self._platform))

  def testAndroidNexus5XReturnsFalseOnNotAndroid(self):
    self._platform.SetOSName('not_android')
    self.assertFalse(expectations.ANDROID_NEXUS5X.ShouldDisable(self._platform))

  def testAndroidNexus6ReturnsFalseOnNotAndroid(self):
    self._platform.SetOSName('not_android')
    self.assertFalse(expectations.ANDROID_NEXUS6.ShouldDisable(self._platform))

  def testAndroidNexus6PReturnsFalseOnNotAndroid(self):
    self._platform.SetOSName('not_android')
    self.assertFalse(expectations.ANDROID_NEXUS6.ShouldDisable(self._platform))

  def testAndroidNexus7ReturnsFalseOnNotAndroid(self):
    self._platform.SetOSName('not_android')
    self.assertFalse(expectations.ANDROID_NEXUS7.ShouldDisable(self._platform))

  def testAndroidCherryMobileReturnsFalseOnNotAndroid(self):
    self._platform.SetOSName('not_android')
    self.assertFalse(
        expectations.ANDROID_ONE.ShouldDisable(self._platform))

  def testAndroidSvelteReturnsFalseOnNotAndroid(self):
    self._platform.SetOSName('not_android')
    self.assertFalse(expectations.ANDROID_SVELTE.ShouldDisable(self._platform))

  def testAndroidNexus5ReturnsFalseOnAndroidNotNexus5(self):
    self._platform.SetOSName('android')
    self.assertFalse(expectations.ANDROID_NEXUS5.ShouldDisable(self._platform))

  def testAndroidNexus5XReturnsFalseOnAndroidNotNexus5X(self):
    self._platform.SetOSName('android')
    self.assertFalse(expectations.ANDROID_NEXUS5X.ShouldDisable(self._platform))

  def testAndroidNexus6ReturnsFalseOnAndroidNotNexus6(self):
    self._platform.SetOSName('android')
    self.assertFalse(expectations.ANDROID_NEXUS6.ShouldDisable(self._platform))

  def testAndroidNexus6PReturnsFalseOnAndroidNotNexus6P(self):
    self._platform.SetOSName('android')
    self.assertFalse(expectations.ANDROID_NEXUS6.ShouldDisable(self._platform))

  def testAndroidNexus7ReturnsFalseOnAndroidNotNexus7(self):
    self._platform.SetOSName('android')
    self.assertFalse(expectations.ANDROID_NEXUS7.ShouldDisable(self._platform))

  def testAndroidCherryMobileReturnsFalseOnAndroidNotCherryMobile(self):
    self._platform.SetOSName('android')
    self.assertFalse(
        expectations.ANDROID_ONE.ShouldDisable(self._platform))

  def testAndroidSvelteReturnsFalseOnAndroidNotSvelte(self):
    self._platform.SetOSName('android')
    self.assertFalse(expectations.ANDROID_SVELTE.ShouldDisable(self._platform))

  def testAndroidNexus5ReturnsTrueOnAndroidNexus5(self):
    self._platform.SetOSName('android')
    self._platform.SetDeviceTypeName('Nexus 5')
    self.assertTrue(expectations.ANDROID_NEXUS5.ShouldDisable(self._platform))

  def testAndroidNexus5XReturnsTrueOnAndroidNexus5X(self):
    self._platform.SetOSName('android')
    self._platform.SetDeviceTypeName('Nexus 5X')
    self.assertTrue(expectations.ANDROID_NEXUS5X.ShouldDisable(self._platform))

  def testAndroidNexus6ReturnsTrueOnAndroidNexus6(self):
    self._platform.SetOSName('android')
    self._platform.SetDeviceTypeName('Nexus 6')
    self.assertTrue(expectations.ANDROID_NEXUS6.ShouldDisable(self._platform))

  def testAndroidNexus6PReturnsTrueOnAndroidNexus6P(self):
    self._platform.SetOSName('android')
    self._platform.SetDeviceTypeName('Nexus 6P')
    self.assertTrue(expectations.ANDROID_NEXUS6.ShouldDisable(self._platform))

  def testAndroidNexus7ReturnsTrueOnAndroidNexus7(self):
    self._platform.SetOSName('android')
    self._platform.SetDeviceTypeName('Nexus 7')
    self.assertTrue(expectations.ANDROID_NEXUS7.ShouldDisable(self._platform))

  def testAndroidCherryMobileReturnsTrueOnAndroidCherryMobile(self):
    self._platform.SetOSName('android')
    self._platform.SetDeviceTypeName('W6210')
    self.assertTrue(
        expectations.ANDROID_ONE.ShouldDisable(self._platform))

  def testAndroidSvelteReturnsTrueOnAndroidSvelte(self):
    self._platform.SetOSName('android')
    self._platform.SetIsSvelte(True)
    self.assertTrue(expectations.ANDROID_SVELTE.ShouldDisable(self._platform))


class StoryExpectationsTest(unittest.TestCase):
  def setUp(self):
    self.platform = fakes.FakePlatform()

  def testCantDisableAfterInit(self):
    e = expectations.StoryExpectations()
    with self.assertRaises(AssertionError):
      e.PermanentlyDisableBenchmark(['test'], 'test')
    with self.assertRaises(AssertionError):
      e.DisableStory('story', ['platform'], 'reason')

  def testPermanentlyDisableBenchmark(self):
    class FooExpectations(expectations.StoryExpectations):
      def SetExpectations(self):
        self.PermanentlyDisableBenchmark(
            [expectations.ALL_WIN], 'crbug.com/123')

    e = FooExpectations()
    self.platform.SetOSName('win')

    reason = e.IsBenchmarkDisabled(self.platform)
    self.assertEqual(reason, 'crbug.com/123')

    self.platform.SetOSName('android')
    reason = e.IsBenchmarkDisabled(self.platform)
    self.assertIsNone(reason)

  def testDisableStoryMultipleConditions(self):
    class FooExpectations(expectations.StoryExpectations):
      def SetExpectations(self):
        self.DisableStory(
            'multi', [expectations.ALL_WIN], 'crbug.com/123')
        self.DisableStory(
            'multi', [expectations.ALL_MAC], 'crbug.com/456')

    e = FooExpectations()

    self.platform.SetOSName('mac')
    reason = e.IsStoryDisabled(
        MockStory('multi'), self.platform)
    self.assertEqual(reason, 'crbug.com/456')

  def testDisableStoryOneCondition(self):
    class FooExpectations(expectations.StoryExpectations):
      def SetExpectations(self):
        self.DisableStory(
            'disable', [expectations.ALL_WIN], 'crbug.com/123')

    e = FooExpectations()

    self.platform.SetOSName('win')
    reason = e.IsStoryDisabled(
        MockStory('disable'), self.platform)
    self.assertEqual(reason, 'crbug.com/123')
    self.platform.SetOSName('mac')
    reason = e.IsStoryDisabled(
        MockStory('disabled'), self.platform)
    self.assertFalse(reason)
    self.assertIsNone(reason)

  def testDisableStoryWithLongName(self):
    class FooExpectations(expectations.StoryExpectations):
      def SetExpectations(self):
        self.DisableStory(
            '123456789012345678901234567890123456789012345678901',
            [expectations.ALL], 'Too Long')

    with self.assertRaises(AssertionError):
      FooExpectations()

  def testGetBrokenExpectationsNotMatching(self):
    class FooExpectations(expectations.StoryExpectations):
      def SetExpectations(self):
        self.DisableStory('bad_name', [expectations.ALL], 'crbug.com/123')

    e = FooExpectations()
    s = MockStorySet([MockStory('good_name')])
    self.assertEqual(e.GetBrokenExpectations(s), ['bad_name'])

  def testGetBrokenExpectationsMatching(self):
    class FooExpectations(expectations.StoryExpectations):
      def SetExpectations(self):
        self.DisableStory('good_name', [expectations.ALL], 'crbug.com/123')

    e = FooExpectations()
    s = MockStorySet([MockStory('good_name')])
    self.assertEqual(e.GetBrokenExpectations(s), [])
