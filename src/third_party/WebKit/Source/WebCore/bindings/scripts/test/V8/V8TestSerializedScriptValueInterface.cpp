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

#include "config.h"
#include "V8TestSerializedScriptValueInterface.h"

#if ENABLE(Condition1) || ENABLE(Condition2)

#include "BindingState.h"
#include "ContextFeatures.h"
#include "ExceptionCode.h"
#include "MessagePort.h"
#include "RuntimeEnabledFeatures.h"
#include "SerializedScriptValue.h"
#include "V8Binding.h"
#include "V8BindingMacros.h"
#include "V8DOMWrapper.h"
#include "V8IsolatedContext.h"
#include "V8MessagePort.h"
#include "V8Proxy.h"
#include <wtf/ArrayBuffer.h>
#include <wtf/UnusedParam.h>

namespace WebCore {

WrapperTypeInfo V8TestSerializedScriptValueInterface::info = { V8TestSerializedScriptValueInterface::GetTemplate, V8TestSerializedScriptValueInterface::derefObject, 0, 0, 0, WrapperTypeObjectPrototype };

namespace TestSerializedScriptValueInterfaceV8Internal {

template <typename T> void V8_USE(T) { }

static v8::Handle<v8::Value> valueAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.value._get");
    TestSerializedScriptValueInterface* imp = V8TestSerializedScriptValueInterface::toNative(info.Holder());
    return imp->value() ? imp->value()->deserialize() : v8::Handle<v8::Value>(v8::Null(info.GetIsolate()));
}

static void valueAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.value._set");
    TestSerializedScriptValueInterface* imp = V8TestSerializedScriptValueInterface::toNative(info.Holder());
    RefPtr<SerializedScriptValue> v = SerializedScriptValue::create(value, info.GetIsolate());
    imp->setValue(WTF::getPtr(v));
    return;
}

static v8::Handle<v8::Value> readonlyValueAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.readonlyValue._get");
    TestSerializedScriptValueInterface* imp = V8TestSerializedScriptValueInterface::toNative(info.Holder());
    return imp->readonlyValue() ? imp->readonlyValue()->deserialize() : v8::Handle<v8::Value>(v8::Null(info.GetIsolate()));
}

static v8::Handle<v8::Value> cachedValueAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.cachedValue._get");
    v8::Handle<v8::String> propertyName = v8::String::NewSymbol("cachedValue");
    v8::Handle<v8::Value> value = info.Holder()->GetHiddenValue(propertyName);
    if (!value.IsEmpty())
        return value;
    TestSerializedScriptValueInterface* imp = V8TestSerializedScriptValueInterface::toNative(info.Holder());
    SerializedScriptValue* serialized = imp->cachedValue();
    value = serialized ? serialized->deserialize() : v8::Handle<v8::Value>(v8::Null(info.GetIsolate()));
    info.Holder()->SetHiddenValue(propertyName, value);
    return value;
}

static void cachedValueAttrSetter(v8::Local<v8::String> name, v8::Local<v8::Value> value, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.cachedValue._set");
    TestSerializedScriptValueInterface* imp = V8TestSerializedScriptValueInterface::toNative(info.Holder());
    RefPtr<SerializedScriptValue> v = SerializedScriptValue::create(value, info.GetIsolate());
    imp->setCachedValue(WTF::getPtr(v));
    info.Holder()->DeleteHiddenValue(v8::String::NewSymbol("cachedValue")); // Invalidate the cached value.
    return;
}

static v8::Handle<v8::Value> portsAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.ports._get");
    TestSerializedScriptValueInterface* imp = V8TestSerializedScriptValueInterface::toNative(info.Holder());
    MessagePortArray* ports = imp->ports();
    if (!ports)
        return v8::Array::New(0);
    MessagePortArray portsCopy(*ports);
    v8::Local<v8::Array> portArray = v8::Array::New(portsCopy.size());
    for (size_t i = 0; i < portsCopy.size(); ++i)
        portArray->Set(v8Integer(i, info.GetIsolate()), toV8(portsCopy[i].get(), info.GetIsolate()));
    return portArray;
}

static v8::Handle<v8::Value> cachedReadonlyValueAttrGetter(v8::Local<v8::String> name, const v8::AccessorInfo& info)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.cachedReadonlyValue._get");
    v8::Handle<v8::String> propertyName = v8::String::NewSymbol("cachedReadonlyValue");
    v8::Handle<v8::Value> value = info.Holder()->GetHiddenValue(propertyName);
    if (!value.IsEmpty())
        return value;
    TestSerializedScriptValueInterface* imp = V8TestSerializedScriptValueInterface::toNative(info.Holder());
    SerializedScriptValue* serialized = imp->cachedReadonlyValue();
    value = serialized ? serialized->deserialize() : v8::Handle<v8::Value>(v8::Null(info.GetIsolate()));
    info.Holder()->SetHiddenValue(propertyName, value);
    return value;
}

static v8::Handle<v8::Value> acceptTransferListCallback(const v8::Arguments& args)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.acceptTransferList");
    if (args.Length() < 1)
        return V8Proxy::throwNotEnoughArgumentsError(args.GetIsolate());
    TestSerializedScriptValueInterface* imp = V8TestSerializedScriptValueInterface::toNative(args.Holder());
    MessagePortArray messagePortArrayTransferList;
    ArrayBufferArray arrayBufferArrayTransferList;
    if (args.Length() > 1) {
        if (!extractTransferables(args[1], messagePortArrayTransferList, arrayBufferArrayTransferList))
            return V8Proxy::throwTypeError("Could not extract transferables");
    }
    bool dataDidThrow = false;
    RefPtr<SerializedScriptValue> data = SerializedScriptValue::create(args[0], &messagePortArrayTransferList, &arrayBufferArrayTransferList, dataDidThrow, args.GetIsolate());
    if (dataDidThrow)
        return v8Undefined();
    if (args.Length() <= 1) {
        imp->acceptTransferList(data);
        return v8Undefined();
    }
    imp->acceptTransferList(data, messagePortArrayTransferList);
    return v8Undefined();
}

static v8::Handle<v8::Value> multiTransferListCallback(const v8::Arguments& args)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.multiTransferList");
    TestSerializedScriptValueInterface* imp = V8TestSerializedScriptValueInterface::toNative(args.Holder());
    if (args.Length() <= 0) {
        imp->multiTransferList();
        return v8Undefined();
    }
    MessagePortArray messagePortArrayTx;
    ArrayBufferArray arrayBufferArrayTx;
    if (args.Length() > 1) {
        if (!extractTransferables(args[1], messagePortArrayTx, arrayBufferArrayTx))
            return V8Proxy::throwTypeError("Could not extract transferables");
    }
    bool firstDidThrow = false;
    RefPtr<SerializedScriptValue> first = SerializedScriptValue::create(args[0], &messagePortArrayTx, &arrayBufferArrayTx, firstDidThrow, args.GetIsolate());
    if (firstDidThrow)
        return v8Undefined();
    if (args.Length() <= 1) {
        imp->multiTransferList(first);
        return v8Undefined();
    }
    if (args.Length() <= 2) {
        imp->multiTransferList(first, messagePortArrayTx);
        return v8Undefined();
    }
    MessagePortArray messagePortArrayTxx;
    ArrayBufferArray arrayBufferArrayTxx;
    if (args.Length() > 3) {
        if (!extractTransferables(args[3], messagePortArrayTxx, arrayBufferArrayTxx))
            return V8Proxy::throwTypeError("Could not extract transferables");
    }
    bool secondDidThrow = false;
    RefPtr<SerializedScriptValue> second = SerializedScriptValue::create(args[2], &messagePortArrayTxx, &arrayBufferArrayTxx, secondDidThrow, args.GetIsolate());
    if (secondDidThrow)
        return v8Undefined();
    if (args.Length() <= 3) {
        imp->multiTransferList(first, messagePortArrayTx, second);
        return v8Undefined();
    }
    imp->multiTransferList(first, messagePortArrayTx, second, messagePortArrayTxx);
    return v8Undefined();
}

} // namespace TestSerializedScriptValueInterfaceV8Internal

static const BatchedAttribute TestSerializedScriptValueInterfaceAttrs[] = {
    // Attribute 'value' (Type: 'attribute' ExtAttr: '')
    {"value", TestSerializedScriptValueInterfaceV8Internal::valueAttrGetter, TestSerializedScriptValueInterfaceV8Internal::valueAttrSetter, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'readonlyValue' (Type: 'readonly attribute' ExtAttr: '')
    {"readonlyValue", TestSerializedScriptValueInterfaceV8Internal::readonlyValueAttrGetter, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'cachedValue' (Type: 'attribute' ExtAttr: 'CachedAttribute')
    {"cachedValue", TestSerializedScriptValueInterfaceV8Internal::cachedValueAttrGetter, TestSerializedScriptValueInterfaceV8Internal::cachedValueAttrSetter, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'ports' (Type: 'readonly attribute' ExtAttr: '')
    {"ports", TestSerializedScriptValueInterfaceV8Internal::portsAttrGetter, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
    // Attribute 'cachedReadonlyValue' (Type: 'readonly attribute' ExtAttr: 'CachedAttribute')
    {"cachedReadonlyValue", TestSerializedScriptValueInterfaceV8Internal::cachedReadonlyValueAttrGetter, 0, 0 /* no data */, static_cast<v8::AccessControl>(v8::DEFAULT), static_cast<v8::PropertyAttribute>(v8::None), 0 /* on instance */},
};

static const BatchedCallback TestSerializedScriptValueInterfaceCallbacks[] = {
    {"acceptTransferList", TestSerializedScriptValueInterfaceV8Internal::acceptTransferListCallback},
    {"multiTransferList", TestSerializedScriptValueInterfaceV8Internal::multiTransferListCallback},
};

v8::Handle<v8::Value> V8TestSerializedScriptValueInterface::constructorCallback(const v8::Arguments& args)
{
    INC_STATS("DOM.TestSerializedScriptValueInterface.Constructor");

    if (!args.IsConstructCall())
        return V8Proxy::throwTypeError("DOM object constructor cannot be called as a function.");

    if (ConstructorMode::current() == ConstructorMode::WrapExistingObject)
        return args.Holder();
    if (args.Length() < 2)
        return V8Proxy::throwNotEnoughArgumentsError(args.GetIsolate());
    STRING_TO_V8PARAMETER_EXCEPTION_BLOCK(V8Parameter<>, hello, MAYBE_MISSING_PARAMETER(args, 0, DefaultIsUndefined));
    MessagePortArray messagePortArrayTransferList;
    ArrayBufferArray arrayBufferArrayTransferList;
    if (args.Length() > 2) {
        if (!extractTransferables(args[2], messagePortArrayTransferList, arrayBufferArrayTransferList))
            return V8Proxy::throwTypeError("Could not extract transferables");
    }
    bool dataDidThrow = false;
    RefPtr<SerializedScriptValue> data = SerializedScriptValue::create(args[1], &messagePortArrayTransferList, &arrayBufferArrayTransferList, dataDidThrow, args.GetIsolate());
    if (dataDidThrow)
        return v8Undefined();

    RefPtr<TestSerializedScriptValueInterface> impl = TestSerializedScriptValueInterface::create(hello, data, messagePortArrayTransferList);
    v8::Handle<v8::Object> wrapper = args.Holder();

    V8DOMWrapper::setDOMWrapper(wrapper, &info, impl.get());
    V8DOMWrapper::setJSWrapperForDOMObject(impl.release(), v8::Persistent<v8::Object>::New(wrapper), args.GetIsolate());
    return args.Holder();
}

static v8::Persistent<v8::FunctionTemplate> ConfigureV8TestSerializedScriptValueInterfaceTemplate(v8::Persistent<v8::FunctionTemplate> desc)
{
    desc->ReadOnlyPrototype();

    v8::Local<v8::Signature> defaultSignature;
    defaultSignature = configureTemplate(desc, "TestSerializedScriptValueInterface", v8::Persistent<v8::FunctionTemplate>(), V8TestSerializedScriptValueInterface::internalFieldCount,
        TestSerializedScriptValueInterfaceAttrs, WTF_ARRAY_LENGTH(TestSerializedScriptValueInterfaceAttrs),
        TestSerializedScriptValueInterfaceCallbacks, WTF_ARRAY_LENGTH(TestSerializedScriptValueInterfaceCallbacks));
    UNUSED_PARAM(defaultSignature); // In some cases, it will not be used.
    desc->SetCallHandler(V8TestSerializedScriptValueInterface::constructorCallback);
    v8::Local<v8::ObjectTemplate> instance = desc->InstanceTemplate();
    v8::Local<v8::ObjectTemplate> proto = desc->PrototypeTemplate();
    UNUSED_PARAM(instance); // In some cases, it will not be used.
    UNUSED_PARAM(proto); // In some cases, it will not be used.
    

    // Custom toString template
    desc->Set(getToStringName(), getToStringTemplate());
    return desc;
}

v8::Persistent<v8::FunctionTemplate> V8TestSerializedScriptValueInterface::GetRawTemplate()
{
    V8BindingPerIsolateData* data = V8BindingPerIsolateData::current();
    V8BindingPerIsolateData::TemplateMap::iterator result = data->rawTemplateMap().find(&info);
    if (result != data->rawTemplateMap().end())
        return result->second;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ = createRawTemplate();
    data->rawTemplateMap().add(&info, templ);
    return templ;
}

v8::Persistent<v8::FunctionTemplate> V8TestSerializedScriptValueInterface::GetTemplate()
{
    V8BindingPerIsolateData* data = V8BindingPerIsolateData::current();
    V8BindingPerIsolateData::TemplateMap::iterator result = data->templateMap().find(&info);
    if (result != data->templateMap().end())
        return result->second;

    v8::HandleScope handleScope;
    v8::Persistent<v8::FunctionTemplate> templ =
        ConfigureV8TestSerializedScriptValueInterfaceTemplate(GetRawTemplate());
    data->templateMap().add(&info, templ);
    return templ;
}

bool V8TestSerializedScriptValueInterface::HasInstance(v8::Handle<v8::Value> value)
{
    return GetRawTemplate()->HasInstance(value);
}


v8::Handle<v8::Object> V8TestSerializedScriptValueInterface::wrapSlow(PassRefPtr<TestSerializedScriptValueInterface> impl, v8::Isolate* isolate)
{
    v8::Handle<v8::Object> wrapper;
    V8Proxy* proxy = 0;
    wrapper = V8DOMWrapper::instantiateV8Object(proxy, &info, impl.get());
    if (UNLIKELY(wrapper.IsEmpty()))
        return wrapper;

    v8::Persistent<v8::Object> wrapperHandle = v8::Persistent<v8::Object>::New(wrapper);

    if (!hasDependentLifetime)
        wrapperHandle.MarkIndependent();
    V8DOMWrapper::setJSWrapperForDOMObject(impl, wrapperHandle, isolate);
    return wrapper;
}

void V8TestSerializedScriptValueInterface::derefObject(void* object)
{
    static_cast<TestSerializedScriptValueInterface*>(object)->deref();
}

} // namespace WebCore

#endif // ENABLE(Condition1) || ENABLE(Condition2)
