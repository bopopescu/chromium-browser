/*
    This file is part of the WebKit open source project.
    This file has been generated by generate-bindings.pl. DO NOT MODIFY!

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Library General Public
    License as published by the Free Software Foundation; either
    version 2 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Library General Public License for more details.

    You should have received a copy of the GNU Library General Public License
    along with this library; see the file COPYING.LIB.  If not, write to
    the Free Software Foundation, Inc., 59 Temple Place - Suite 330,
    Boston, MA 02111-1307, USA.
*/

#ifndef V8Float64Array_h
#define V8Float64Array_h

#include "V8ArrayBufferView.h"
#include "V8Binding.h"
#include "V8DOMWrapper.h"
#include "WrapperTypeInfo.h"
#include <v8.h>
#include <wtf/Float64Array.h>
#include <wtf/HashMap.h>
#include <wtf/text/StringHash.h>

namespace WebCore {

class V8Float64Array {
public:
    static const bool hasDependentLifetime = V8ArrayBufferView::hasDependentLifetime;
    static bool HasInstance(v8::Handle<v8::Value>);
    static v8::Persistent<v8::FunctionTemplate> GetRawTemplate();
    static v8::Persistent<v8::FunctionTemplate> GetTemplate();
    static Float64Array* toNative(v8::Handle<v8::Object> object)
    {
        return reinterpret_cast<Float64Array*>(object->GetPointerFromInternalField(v8DOMWrapperObjectIndex));
    }
    inline static v8::Handle<v8::Object> wrap(Float64Array*, v8::Isolate* = 0);
    static void derefObject(void*);
    static void visitDOMWrapper(DOMDataStore*, void*, v8::Persistent<v8::Object>);
    static WrapperTypeInfo info;
    static v8::Handle<v8::Value> constructorCallback(const v8::Arguments&);
    static const int internalFieldCount = v8DefaultWrapperInternalFieldCount + 0;
private:
    static v8::Handle<v8::Object> wrapSlow(PassRefPtr<Float64Array>, v8::Isolate*);
};

v8::Handle<v8::Object> V8Float64Array::wrap(Float64Array* impl, v8::Isolate* isolate)
{
        v8::Handle<v8::Object> wrapper = getDOMObjectMap(isolate).get(impl);
        if (!wrapper.IsEmpty())
            return wrapper;
    return V8Float64Array::wrapSlow(impl, isolate);
}

v8::Handle<v8::Value> toV8(Float64Array*, v8::Isolate* = 0);
inline v8::Handle<v8::Value> toV8(PassRefPtr< Float64Array > impl, v8::Isolate* isolate = 0)
{
    return toV8(impl.get(), isolate);
}

}

#endif // V8Float64Array_h
