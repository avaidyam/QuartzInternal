/* CoreAnimation - CAColorMatrix.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CACOLORMATRIX_H
#define CACOLORMATRIX_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

/* Describes a color matrix used for blending transformations. */
typedef struct CAColorMatrix {
    float m11, m12, m13, m14, m15;
    float m21, m22, m23, m24, m25;
    float m31, m32, m33, m34, m35;
    float m41, m42, m43, m44, m45;
} CAColorMatrix;

@interface NSValue (ColorMatrix)

/* Construct an NSValue containing a `CAColorMatrix`. */
+ (NSValue *)valueWithCAColorMatrix:(CAColorMatrix)matrix;

/* Retrieves the contained `CAColorMatrix`, if any. */
- (CAColorMatrix)CAColorMatrixValue;

@end

CA_EXTERN_C_END

#endif // CACOLORMATRIX_H
