/* CoreGraphics - CGColorTransform.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGCOLORTRANSFORMPRIV_H_
#define CGCOLORTRANSFORMPRIV_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

///
typedef struct CGColorTransformBase *CGColorTransformBaseRef;

///
typedef struct CGColorTransform *CGColorTransformRef;

///
CG_EXTERN CFTypeID CGColorTransformBaseGetTypeID(void);

///
CG_EXTERN CFTypeID CGColorTransformGetTypeID(void);

///
CG_EXTERN void *CGColorTransformBaseGetCache(CGColorTransformBaseRef base);

///
CG_EXTERN CGColorSpaceRef CGColorTransformBaseGetColorSpace(CGColorTransformBaseRef base);

///
CG_EXTERN void *CGColorTransformBaseAcquire(void *arg0, void *arg1);

///
CG_EXTERN void *CGColorTransformBaseCacheRelease(void *arg0, void *arg1);

///
CG_EXTERN void *CGColorTransformBaseCacheRemoveColorSpace(void *arg0, void *arg1);

///
CG_EXTERN CGColorTransformRef CGColorTransformCreate(CGColorSpaceRef space, CFDictionaryRef attributes);

///
CG_EXTERN CGColorTransformRef CGColorTransformRetain(CGColorTransformRef colorTransform);

///
CG_EXTERN void CGColorTransformRelease(CGColorTransformRef colorTransform);

///
CG_EXTERN CGColorRef CGColorTransformConvertColor(CGColorTransformRef colorTransform,
                                                  CGColorRef color, CGColorRenderingIntent intent);

///
CG_EXTERN int CGColorTransformGetIdentifier(CGColorTransformRef colorTransform);

CF_EXTERN_C_END

#endif /* CGCOLORTRANSFORMPRIV_H_ */
