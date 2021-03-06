// Copyright 2018 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_BROWSER_SWITCHER_IEEM_SITELIST_PARSER_H_
#define CHROME_BROWSER_BROWSER_SWITCHER_IEEM_SITELIST_PARSER_H_

#include "base/callback.h"
#include "base/macros.h"
#include "base/optional.h"

namespace browser_switcher {

// State of a completed/failed |ParseIeemXml()| call.
class ParsedXml {
 public:
  ParsedXml();
  ParsedXml(ParsedXml&&);
  ParsedXml(std::vector<std::string>&& sitelist,
            std::vector<std::string>&& greylist,
            base::Optional<std::string>&& error);
  ~ParsedXml();

  std::vector<std::string> sitelist;
  std::vector<std::string> greylist;
  base::Optional<std::string> error;

 private:
  DISALLOW_COPY_AND_ASSIGN(ParsedXml);
};

// Callback type for the |ParseIeemXml()| method.
using ParseIeemXmlCallback = base::OnceCallback<void(ParsedXml)>;

// Parses the XML contained in |xml|, and calls |callback| with the parsed XML
// result.
void ParseIeemXml(const std::string& xml, ParseIeemXmlCallback callback);

}  // namespace browser_switcher

#endif  // CHROME_BROWSER_BROWSER_SWITCHER_IEEM_SITELIST_PARSER_H_
