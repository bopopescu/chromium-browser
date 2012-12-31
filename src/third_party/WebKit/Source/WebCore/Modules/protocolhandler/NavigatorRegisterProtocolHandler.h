/*
 * Copyright (C) 2011, Google Inc. All rights reserved.
 * Copyright (C) 2012, Samsung Electronics. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH
 * DAMAGE.
 */

#ifndef NavigatorRegisterProtocolHandler_h
#define NavigatorRegisterProtocolHandler_h

#if ENABLE(REGISTER_PROTOCOL_HANDLER) || ENABLE(CUSTOM_SCHEME_HANDLER)

#include "RefCountedSupplement.h"
#include "RegisterProtocolHandlerClient.h"
#include <wtf/PassRefPtr.h>
#include <wtf/text/WTFString.h>

namespace WebCore {

class Page;
class Navigator;

typedef int ExceptionCode;

class NavigatorRegisterProtocolHandler : public RefCountedSupplement<Page, NavigatorRegisterProtocolHandler> {
public:
    virtual ~NavigatorRegisterProtocolHandler();

    static const AtomicString& supplementName();
    static NavigatorRegisterProtocolHandler* from(Page*);

#if ENABLE(REGISTER_PROTOCOL_HANDLER)
    static void registerProtocolHandler(Navigator*, const String& scheme, const String& url, const String& title, ExceptionCode&);
#endif 

#if ENABLE(CUSTOM_SCHEME_HANDLER)
    static String isProtocolHandlerRegistered(Navigator*, const String& scheme, const String& url, ExceptionCode&);
    static void unregisterProtocolHandler(Navigator*, const String& scheme, const String& url, ExceptionCode&);
#endif

    static PassRefPtr<NavigatorRegisterProtocolHandler> create(RegisterProtocolHandlerClient*);

private:
    explicit NavigatorRegisterProtocolHandler(RegisterProtocolHandlerClient* client)
        : m_client(client)
    { }

    RegisterProtocolHandlerClient* client() { return m_client; }

    RegisterProtocolHandlerClient* m_client;
};

} // namespace WebCore

#endif // ENABLE(REGISTER_PROTOCOL_HANDLER) || ENABLE(CUSTOM_SCHEME_HANDLER)

#endif // NavigatorRegisterProtocolHandler_h
