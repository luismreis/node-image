/*
** This file contains proprietary software owned by Motorola Mobility, Inc. **
** No rights, expressed or implied, whatsoever to this software are provided by Motorola Mobility, Inc. hereunder. **
**
** (c) Copyright 2011 Motorola Mobility, Inc.  All Rights Reserved.  **
*/


#ifndef COMMON_H_
#define COMMON_H_

#include <node.h>
#include <v8.h>
#include "nan.h"

#define REQ_ARGS(N)                                                     \
  if (args.Length() < (N))                                              \
    NanThrowTypeError("Expected " #N "arguments");

#define REQ_STR_ARG(I, VAR)                                             \
  if (args.Length() <= (I) || !args[I]->IsString())                     \
    NanThrowTypeError("Argument " #I " must be a string");              \
  String::Utf8Value VAR(args[I]->ToString());

#define REQ_EXT_ARG(I, VAR)                                             \
  if (args.Length() <= (I) || !args[I]->IsExternal())                   \
    NanThrowTypeError("Argument " #I " invalid");                       \
  Local<External> VAR = Local<External>::Cast(args[I]);

#define REQ_FUN_ARG(I, VAR)                                             \
  if (args.Length() <= (I) || !args[I]->IsFunction())                   \
    NanThrowTypeError("Argument " #I " must be a function");            \
  Local<Function> VAR = Local<Function>::Cast(args[I]);

#define REQ_ERROR_THROW(error) if (ret == error) return JS_EXCEPTION(#error);

template <typename T>
static T* UnwrapThis(_NAN_METHOD_ARGS) {
  return node::ObjectWrap::Unwrap<T>(args.This());
}

template <typename T>
static T* UnwrapThis(_NAN_GETTER_ARGS) {
  return node::ObjectWrap::Unwrap<T>(args.This());
}



#endif /* COMMON_H_ */
