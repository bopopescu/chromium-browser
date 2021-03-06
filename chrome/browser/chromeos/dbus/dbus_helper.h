// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_CHROMEOS_DBUS_DBUS_HELPER_H_
#define CHROME_BROWSER_CHROMEOS_DBUS_DBUS_HELPER_H_

namespace chromeos {

// Creates state needed for field trials.
void PreEarlyInitDBus();

// Shutdowns things initialized in the PreEarlyInitDBus().
void ShutdownDBus();

}  // namespace chromeos

#endif  // CHROME_BROWSER_CHROMEOS_DBUS_DBUS_HELPER_H_
