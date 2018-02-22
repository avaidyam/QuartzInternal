/* CoreGraphics - CGContextPrivate.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGCONTEXTPRIVATE_H_
#define CGCONTEXTPRIVATE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef enum {
	kSolidPattern,
	kLinearGradientPattern,
	kRadialGradientPattern,
	kTexturePattern,
	/* handle dashed, dotted, etc... */
} CGBrushStyle;

typedef enum {
	kCGContextTypeGeneric		= 0,
	kCGContextTypePDF			= 1,
	kCGContextTypeBitmap		= 4,
	kCGContextTypeDisplayList	= 6
} CGContextType;

typedef struct CGBitmapContextInfo *CGBitmapContextInfoRef;

void CGContextCreatePaths(CGContextRef c);

CG_EXTERN CGContextRef CGContextCreate();

CG_EXTERN CGContextRef CGContextCreateWithDelegate(CGContextDelegateRef ctxDelegate, 
												   CGRenderingStateRef renderState,
												   CGGStateRef gState);

CG_EXTERN void CGContextSetDelegate(CGContextRef c, 
									CGContextDelegateRef ctxDelegate);

CG_EXTERN CGContextRef CGContextAddFilter(CGContextRef c, void *arg0, void *arg1);

CG_EXTERN void CGContextDestroy(CFTypeRef c);

CG_EXTERN void CGContextResetState(CGContextRef c);

CG_EXTERN void CGContextSetRenderingResolution(CGContextRef c);

CG_EXTERN void CGContextSetStrokeAdjust(CGContextRef c, CGFloat strokeAdjust);

CG_EXTERN void CGContextSetBlackGeneration(CGContextRef c, CGFunctionRef blackGeneration);

CG_EXTERN void CGContextSetUndercolorRemoval(CGContextRef c, CGFunctionRef underColorRemoval);

CG_EXTERN void CGContextSetCompositeOperation(CGContextRef c, int arg1);

CG_EXTERN CGAffineTransform CGContextGetBaseCTM(CGContextRef c);

CG_EXTERN CGCompositeOperation CGContextGetCompositeOperation(CGContextRef c);

CG_EXTERN CGColorRef CGContextGetFillColorAsColor(CGContextRef c);

CG_EXTERN CGFloat CGContextGetLineWidth(CGContextRef c);

CG_EXTERN bool CGContextGetShouldSmoothFonts(CGContextRef c);

CG_EXTERN void CGContextSetBaseCTM(CGContextRef c, CGAffineTransform baseCTM);

CG_EXTERN void CGContextSetCTM(CGContextRef c, CGAffineTransform ctm);

CG_EXTERN void CGContextSetCompositeOperation(CGContextRef c, CGCompositeOperation operation);

CG_EXTERN void CGContextSetShouldAntialiasFonts(CGContextRef c, bool shouldAntialiasFonts);

CG_EXTERN void CGContextResetClip(CGContextRef c);

#if PLATFORM(MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 101100

CG_EXTERN void CGContextSetFontDilation(CGContextRef c, CGSize dilation);

CG_EXTERN void CGContextSetFontRenderingStyle(CGContextRef c, CGFontRenderingStyle style);
#endif

CG_EXTERN CGFontAntialiasingStyle CGContextGetFontAntialiasingStyle(CGContextRef c);

CG_EXTERN void CGContextSetFontAntialiasingStyle(CGContextRef c, CGFontAntialiasingStyle style);

CG_EXTERN const CFStringRef kCGContextDisplayList;
CG_EXTERN const CFStringRef kCGContextLog;
CG_EXTERN const CFStringRef kCGContextBackgroundColor;
CG_EXTERN const CFStringRef kCGContextBoundingBox;
CG_EXTERN const CFStringRef kCGContextColorSpace;
CG_EXTERN const CFStringRef kCGContextGroup;
CG_EXTERN const CFStringRef kCGContextResolution;
CG_EXTERN const CFStringRef kCGContextFilterInfo;
CG_EXTERN const CFStringRef kCGContextFilterOptionsData;
CG_EXTERN const CFStringRef kCGContextFilterOptionsURL;
CG_EXTERN const CFStringRef kCGContextFilterInfo;
CG_EXTERN const CFStringRef kCGContextFilterOptionsData;
CG_EXTERN const CFStringRef kCGContextFilterOptionsURL;
CG_EXTERN const CFStringRef kCGTransparencyLayerContentBounds;
CG_EXTERN const CFStringRef kCGContextErase;
CG_EXTERN const CFStringRef kCGContextClear;
CG_EXTERN const CFStringRef kCGContextWait;
CG_EXTERN const CFStringRef kCGContextSynchronize;
CG_EXTERN const CFStringRef kCGContextFlush;

CF_EXTERN_C_END

#endif /* CGCONTEXTPRIVATE_H_ */


