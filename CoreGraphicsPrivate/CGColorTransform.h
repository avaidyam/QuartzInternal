/* CoreGraphics - CGColorTransform.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGCOLORTRANSFORMPRIV_H_
#define CGCOLORTRANSFORMPRIV_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef struct CGColorTransformBase *CGColorTransformBaseRef;

typedef struct CGColorTransform *CGColorTransformRef;

CG_EXTERN CGColorTransformBaseRef CGColorTransformBaseRetain(CGColorTransformBaseRef colorTransform);

CG_EXTERN void CGColorTransformBaseRelease(CGColorTransformBaseRef colorTransform);

CG_EXTERN CGColorTransformRef CGColorTransformCreate(CGColorSpaceRef space, CFDictionaryRef attributes);

CG_EXTERN CGColorTransformRef CGColorTransformRetain(CGColorTransformRef colorTransform);

CG_EXTERN void CGColorTransformRelease(CGColorTransformRef colorTransform);

CG_EXTERN CGColorRef CGColorTransformConvertColor(CGColorTransformRef colorTransform,
                                                  CGColorRef color, CGColorRenderingIntent intent);

CG_EXTERN int CGColorTransformGetIdentifier(CGColorTransformRef colorTransform);

CG_EXTERN CFTypeID CGColorTransformBaseGetTypeID(void);

CG_EXTERN CFTypeID CGColorTransformGetTypeID(void);

CF_EXTERN_C_END

#endif /* CGCOLORTRANSFORMPRIV_H_ */
