/* CoreAnimation - CACFValueFunction.h

   Copyright (c) 2007 Apple Inc.
   All rights reserved. */

#ifndef CACFVALUEFUNCTION_H
#define CACFVALUEFUNCTION_H

#include <QuartzCore/CACFBase.h>

CA_EXTERN_C_BEGIN

CA_EXTERN CACFValueFunctionRef CACFValueFunctionGetFunctionWithName
    (CFStringRef name);

CA_EXTERN CFStringRef CACFValueFunctionGetName (CACFValueFunctionRef fun);

CA_EXTERN CFTypeID CACFValueFunctionGetTypeID (void);

/** Value function names. **/

CA_EXTERN const CFStringRef kCACFValueFunctionRotateX;
CA_EXTERN const CFStringRef kCACFValueFunctionRotateY;
CA_EXTERN const CFStringRef kCACFValueFunctionRotateZ;
CA_EXTERN const CFStringRef kCACFValueFunctionScale;
CA_EXTERN const CFStringRef kCACFValueFunctionScaleX;
CA_EXTERN const CFStringRef kCACFValueFunctionScaleY;
CA_EXTERN const CFStringRef kCACFValueFunctionScaleZ;
CA_EXTERN const CFStringRef kCACFValueFunctionTranslate;
CA_EXTERN const CFStringRef kCACFValueFunctionTranslateX;
CA_EXTERN const CFStringRef kCACFValueFunctionTranslateY;
CA_EXTERN const CFStringRef kCACFValueFunctionTranslateZ;

CA_EXTERN_C_END

#endif /* CACFVALUEFUNCTION_H */
