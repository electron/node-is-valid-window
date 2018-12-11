#include "impl.h"
#include "nan.h"

namespace {

void IsValidWindow(const Nan::FunctionCallbackInfo<v8::Value>& info) {
  if (!node::Buffer::HasInstance(info[0])) {
    Nan::ThrowTypeError("First argument must be Buffer");
    return;
  }

  info.GetReturnValue().Set(impl::IsValidWindow(node::Buffer::Data(info[0]),
                                                node::Buffer::Length(info[0])));
}

void Init(v8::Handle<v8::Object> exports) {
  Nan::SetMethod(exports, "isValidWindow", IsValidWindow);
}

}  // namespace

NODE_MODULE(is_valid_window, Init)
