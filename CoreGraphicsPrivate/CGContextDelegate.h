/* CoreGraphics - CGContextDelegate.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGCONTEXTDELEGATE_H_
#define CGCONTEXTDELEGATE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef struct CGContextDelegate *CGContextDelegateRef;

enum CGContextDelegateType {
    kCGContextDelegateFinalize = 0,
	kCGContextDelegateGetColorTransform,
	kCGContextDelegateGetBounds,
	kCGContextDelegateDrawLines,
	kCGContextDelegateDrawRects,
	kCGContextDelegateDrawPath,
	kCGContextDelegateDrawImage,
	kCGContextDelegateDrawGlyphs,
	kCGContextDelegateDrawShading,
	kCGContextDelegateDrawDisplayList,
	kCGContextDelegateDrawImages,
	kCGContextDelegateBeginPage,
	kCGContextDelegateEndPage,
	kCGContextDelegateOperation,
	kCGContextDelegateDrawWindowContents,
	kCGContextDelegateDirtyWindowContents,
	kCGContextDelegateBeginLayer,
	kCGContextDelegateEndLayer,
	kCGContextDelegateGetLayer,
	kCGContextDelegateDrawLayer
};
typedef enum CGContextDelegateType CGContextDelegateType;

typedef int (*CGFunctionPtr)();

typedef CGColorTransformRef (*CGCallbackGetColorTransform) (CGContextDelegateRef ctxDelegate, 
															CGRenderingStateRef rendering, 
															CGGStateRef state);

typedef CGError (*CGCallbackDrawPath) (CGContextDelegateRef ctxDelegate, 
									   CGRenderingStateRef rendering, 
									   CGGStateRef state, 
									   CGPathDrawingMode mode,
									   CGMutablePathRef path);

typedef CGError (*CGCallbackDrawLines) (CGContextDelegateRef ctxDelegate, 
										CGRenderingStateRef rendering, 
										CGGStateRef state,
										const CGPoint points[],
										size_t count);

typedef CGError (*CGCallbackDrawRects) (CGContextDelegateRef ctxDelegate, 
										CGRenderingStateRef rendering, 
										CGGStateRef state,
										const CGRect rects[],
										size_t count);

typedef CGError (*CGCallbackDrawImage) (CGContextDelegateRef ctxDelegate, 
										CGRenderingStateRef rendering, 
										CGGStateRef state,
										CGRect rect,
										CGImageRef image);

typedef CGError (*CGCallbackDrawGlyphs) (CGContextDelegateRef ctxDelegate,
										 CGRenderingStateRef rendering,
										 CGGStateRef state,
										 CGAffineTransform ctm);

typedef CGError (*CGCallbackOperation) (CGContextDelegateRef ctxDelegate,
										CGRenderingStateRef rendering,
										CGGStateRef state,
										CFStringRef op,
										void* tmp);

typedef CGError (*CGCallbackDrawShading) (CGContextDelegateRef ctxDelegate, 
										  CGRenderingStateRef rendering,
										  CGGStateRef state,
										  CGShadingRef shading);


typedef struct CGCallback *CGCallbackRef;

typedef struct CGContextDelegateInfo *CGContextDelegateInfoRef;

typedef struct CGContextDelegate *CGContextDelegateRef;

CG_EXTERN CGCallback _kCGCallbacks[];

CG_EXTERN CGContextDelegateRef CGContextDelegateCreate(void *info);

CG_EXTERN CGContextDelegateRef CGContextDelegateRetain(CGContextDelegateRef ctxDelegate);

CG_EXTERN void CGContextDelegateRelease(CGContextDelegateRef ctxDelegate);

CG_EXTERN void CGContextSetDelegate(CGContextRef c, CGContextDelegateRef ctxDelegate);

CG_EXTERN void CGContextDelegateSetCallbacks(CGContextDelegateRef ctxDelegate,
                                             const CGCallback* dlArray, int count);

CG_EXTERN void CGContextDelegateSetCallback(CGContextDelegateRef ctxDelegate,
                                            CGContextDelegateType type, void *callback);

CG_EXTERN void CGContextDelegateSetCallbacks(CGContextDelegateRef ctxDelegate,
                                             const CGCallback* dlArray, int count);

CG_EXTERN CGContextDelegateInfoRef CGContextDelegateGetInfo(CGContextDelegateRef ctxDelegate);

CG_EXTERN CGError CGContextDelegateOperation(CGContextDelegateRef ctxDelegate,
											 CGRenderingStateRef rendering,
											 CGGStateRef state,
											 CFStringRef op,
											 void *tmp);

CG_EXTERN CGError CGContextDelegateDrawPath(CGContextDelegateRef ctxDelegate, 
											CGRenderingStateRef rendering, 
											CGGStateRef state,
											CGPathDrawingMode mode,
											CGMutablePathRef path);


CG_EXTERN CGError CGContextDelegateDrawRects(CGContextDelegateRef ctxDelegate, 
											 CGRenderingStateRef rendering, 
											 CGGStateRef state,
											 const CGRect rects[],
											 size_t count);

CG_EXTERN CGError CGContextDelegateDrawImage(CGContextDelegateRef ctxDelegate, 
											 CGRenderingStateRef rendering,
											 CGGStateRef state,
											 CGRect rect,
											 CGImageRef image);

CG_EXTERN CGError CGContextDelegateDrawShading(CGContextDelegateRef ctxDelegate, 
											   CGRenderingStateRef rendering,
											   CGGStateRef state,
											   CGShadingRef shading);

CF_EXTERN_C_END

#endif /* CGCONTEXTDELEGATE_H_ */
