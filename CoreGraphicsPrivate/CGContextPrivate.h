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
    kCGContextTypeUnknown,
    kCGContextTypePDF,
    kCGContextTypePostScript,
    kCGContextTypeWindow,
    kCGContextTypeBitmap,
    kCGContextTypeGL,
    kCGContextTypeDisplayList,
    kCGContextTypeKSeparation,
    kCGContextTypeIOSurface,
    kCGContextTypeCount
} CGContextType;

typedef enum {
    kCGCompositeCopy = 1,
    kCGCompositeSover = 2,
} CGCompositeOperation;

enum {
    kCGImageCachingTransient = 1,
    kCGImageCachingTemporary = 3,
};
typedef uint32_t CGImageCachingFlags;

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

CG_EXTERN bool CGContextGetShouldAntialias(CGContextRef c);

CG_EXTERN void CGContextSetBaseCTM(CGContextRef c, CGAffineTransform baseCTM);

CG_EXTERN void CGContextSetCTM(CGContextRef c, CGAffineTransform ctm);

CG_EXTERN void CGContextSetCompositeOperation(CGContextRef c, CGCompositeOperation operation);

CG_EXTERN void CGContextSetShouldAntialiasFonts(CGContextRef c, bool shouldAntialiasFonts);

CG_EXTERN void CGContextResetClip(CGContextRef c);

CG_EXTERN CGContextType CGContextGetType(CGContextRef);

#if PLATFORM(MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 101100

CG_EXTERN void CGContextSetFontDilation(CGContextRef c, CGSize dilation);

CG_EXTERN void CGContextSetFontRenderingStyle(CGContextRef c, CGFontRenderingStyle style);
#endif

CG_EXTERN CGFontAntialiasingStyle CGContextGetFontAntialiasingStyle(CGContextRef c);

CG_EXTERN void CGContextSetFontAntialiasingStyle(CGContextRef c, CGFontAntialiasingStyle style);

CG_EXTERN bool CGContextGetAllowsFontSubpixelPositioning(CGContextRef c);

CG_EXTERN bool CGContextDrawsWithCorrectShadowOffsets(CGContextRef c);

CG_EXTERN bool CGColorSpaceUsesExtendedRange(CGColorSpaceRef c);

CG_EXTERN CGColorSpaceRef CGContextCopyDeviceColorSpace(CGContextRef c);

CG_EXTERN CFPropertyListRef CGColorSpaceCopyPropertyList(CGColorSpaceRef c);

CG_EXTERN void CGImageSetCachingFlags(CGImageRef, CGImageCachingFlags);

CG_EXTERN CGImageCachingFlags CGImageGetCachingFlags(CGImageRef);

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

CGDataProviderRef CGPDFDocumentGetDataProvider(CGPDFDocumentRef);

typedef struct CGPDFAnnotation *CGPDFAnnotationRef;
typedef bool (^CGPDFAnnotationDrawCallbackType)(CGContextRef context, CGPDFPageRef page, CGPDFAnnotationRef annotation);
void CGContextDrawPDFPageWithAnnotations(CGContextRef, CGPDFPageRef, CGPDFAnnotationDrawCallbackType);
void CGContextDrawPathDirect(CGContextRef, CGPathDrawingMode, CGPathRef, const CGRect* boundingBox);

CF_EXTERN_C_END

#endif /* CGCONTEXTPRIVATE_H_ */


