/* CoreAnimation - CACFTimingFunction.h

   Copyright (c) 2007 Apple Inc.
   All rights reserved. */

#ifndef CACFTIMINGFUNCTION_H
#define CACFTIMINGFUNCTION_H

#include <QuartzCore/CACFBase.h>

CA_EXTERN_C_BEGIN

CA_EXTERN CACFTimingFunctionRef CACFTimingFunctionCreate (float c1x,
    float c1y, float c2x, float c2y);

CA_EXTERN CACFTimingFunctionRef CACFTimingFunctionGetFunctionWithName
    (CFStringRef name);

CA_EXTERN float CACFTimingFunctionGetControlPoint (CACFTimingFunctionRef
    timingFunction, size_t idx);

CA_EXTERN CFTypeID CACFTimingFunctionGetTypeID (void);

/** Timing function names. **/

CA_EXTERN const CFStringRef kCACFTimingFunctionDefault;
CA_EXTERN const CFStringRef kCACFTimingFunctionLinear;
CA_EXTERN const CFStringRef kCACFTimingFunctionEaseIn;
CA_EXTERN const CFStringRef kCACFTimingFunctionEaseOut;
CA_EXTERN const CFStringRef kCACFTimingFunctionEaseInEaseOut;

CA_EXTERN_C_END

#endif /* CACFTIMINGFUNCTION_H */
