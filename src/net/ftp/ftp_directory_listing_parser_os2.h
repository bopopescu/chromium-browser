// Copyright (c) 2011 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_FTP_FTP_DIRECTORY_LISTING_PARSER_OS2_H_
#define NET_FTP_FTP_DIRECTORY_LISTING_PARSER_OS2_H_

#include <vector>

#include "base/string16.h"
#include "net/base/net_export.h"

namespace net {

struct FtpDirectoryListingEntry;

// Parses OS/2 FTP directory listing. Returns true on success.
NET_EXPORT_PRIVATE bool ParseFtpDirectoryListingOS2(
    const std::vector<string16>& lines,
    std::vector<FtpDirectoryListingEntry>* entries);

}  // namespace net

#endif  // NET_FTP_FTP_DIRECTORY_LISTING_PARSER_OS2_H_
