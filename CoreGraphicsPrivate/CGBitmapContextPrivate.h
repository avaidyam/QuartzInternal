/* CoreGraphics - CGBitmapContextPrivate.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGBITMAPCONTEXTPRIVATE_H_
#define CGBITMAPCONTEXTPRIVATE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CG_EXTERN_C_BEGIN

typedef CGContextDelegateRef  (*CGBitmapContextDelegateCreateCallback)(
	CGBitmapContextInfoRef bitmapContextInfo, 
	CFDictionaryRef theDict);

CG_EXTERN CGBitmapContextInfoRef CGBitmapContextInfoCreate(void *data, 
														   size_t width, size_t height,
														   size_t bitsPerComponent,
														   size_t bitsPerPixel,
														   size_t bytesPerRow,
														   CGColorSpaceRef colorspace, 
														   CGBitmapInfo bitmapInfo, 
														   void *alphaData,
														   Boolean b,
														   Boolean c,
														   Boolean d,
														   Boolean e,
														   CGFloat hRes,
														   CGFloat vRes);

CG_EXTERN void CGBitmapContextInfoRelease(CGBitmapContextInfoRef bitmapInfo);

CG_EXTERN CGContextRef
CGBitmapContextCreateWithData(void *data, size_t width,
							  size_t height, size_t bitsPerComponent,
							  size_t bytesPerRow,
							  CGColorSpaceRef colorspace, 
							  CGBitmapInfo bitmapInfo, 
							  CGFloat hRes, CGFloat vRes);

CG_EXTERN CGContextRef CGBitmapContextCreateWithDictionary(void *data, 
												 size_t width, size_t height,
												 size_t bitsPerComponent,
												 size_t bitsPerPixel,
												 size_t bytesPerRow,
												 CGColorSpaceRef colorspace, 
												 CGBitmapInfo bitmapInfo,
												 CGFloat hRes, 
												 CGFloat vRes, 
												 CFDictionaryRef theDict);

CG_EXTERN void *CGBitmapAllocateData(size_t len);

CG_EXTERN void CGBitmapFreeData(void *data);

CG_EXTERN_C_END

#endif /* CGBITMAPCONTEXTPRIVATE_H_ */


