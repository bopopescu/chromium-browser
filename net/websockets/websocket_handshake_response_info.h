// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef NET_WEBSOCKETS_WEBSOCKET_HANDSHAKE_RESPONSE_INFO_H_
#define NET_WEBSOCKETS_WEBSOCKET_HANDSHAKE_RESPONSE_INFO_H_

#include "base/macros.h"
#include "base/memory/scoped_refptr.h"
#include "base/time/time.h"
#include "net/base/host_port_pair.h"
#include "net/base/net_export.h"
#include "url/gurl.h"

namespace net {

class HttpResponseHeaders;

struct NET_EXPORT WebSocketHandshakeResponseInfo {
  WebSocketHandshakeResponseInfo(const GURL& url,
                                 scoped_refptr<HttpResponseHeaders> headers,
                                 const HostPortPair& socket_address,
                                 base::Time response_time);
  ~WebSocketHandshakeResponseInfo();
  // The request URL
  GURL url;
  // HTTP response headers
  scoped_refptr<HttpResponseHeaders> headers;
  // Remote address of the socket.
  HostPortPair socket_address;
  // The time that this response arrived
  base::Time response_time;

 private:
  DISALLOW_COPY_AND_ASSIGN(WebSocketHandshakeResponseInfo);
};

}  // namespace net

#endif  // NET_WEBSOCKETS_WEBSOCKET_HANDSHAKE_RESPONSE_INFO_H_
