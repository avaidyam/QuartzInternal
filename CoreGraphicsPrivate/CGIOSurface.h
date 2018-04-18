/* CoreGraphics - CGIOSurface.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGIOSURFACE_H_
#define CGIOSURFACE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

CG_EXTERN CGContextRef CGIOSurfaceContextCreate(IOSurfaceRef, size_t, size_t, size_t, size_t, CGColorSpaceRef, CGBitmapInfo);
CG_EXTERN CGImageRef CGIOSurfaceContextCreateImage(CGContextRef);
CG_EXTERN CGImageRef CGIOSurfaceContextCreateImageReference(CGContextRef);
CG_EXTERN CGColorSpaceRef CGIOSurfaceContextGetColorSpace(CGContextRef);

CF_EXTERN_C_END

#endif /* CGIOSURFACE_H_ */
