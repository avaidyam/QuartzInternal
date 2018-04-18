/* CoreGraphics - CGStyle.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGSTYLE_H_
#define CGSTYLE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef CF_ENUM (int32_t, CGStyleDrawOrdering) {
    kCGStyleDrawOrderingStyleOnly = 0,
    kCGStyleDrawOrderingBelow = 1,
    kCGStyleDrawOrderingAbove = 2,
};

typedef CF_ENUM (int32_t, CGFocusRingOrdering) {
    kCGFocusRingOrderingNone = kCGStyleDrawOrderingStyleOnly,
    kCGFocusRingOrderingBelow = kCGStyleDrawOrderingBelow,
    kCGFocusRingOrderingAbove = kCGStyleDrawOrderingAbove,
};

typedef CF_ENUM (int32_t, CGFocusRingTint) {
    kCGFocusRingTintBlue = 0,
    kCGFocusRingTintGraphite = 1,
};

struct CGFocusRingStyle {
    unsigned int version;
    CGFocusRingTint tint;
    CGFocusRingOrdering ordering;
    CGFloat alpha;
    CGFloat radius;
    CGFloat threshold;
    CGRect bounds;
    int accumulate;
};
typedef struct CGFocusRingStyle CGFocusRingStyle;

typedef struct CGStyle *CGStyleRef;

CG_EXTERN CGStyleRef CGStyleRetain(CGStyleRef style);

CG_EXTERN void CGStyleRelease(CGStyleRef style);

CG_EXTERN CGStyleRef CGStyleCreateFocusRingWithColor(const CGFocusRingStyle*, CGColorRef);

CG_EXTERN void CGContextSetStyle(CGContextRef, CGStyleRef);

CG_EXTERN CFTypeID CGStyleGetTypeID(void);

CF_EXTERN_C_END

#endif /* CGSTYLE_H_ */
