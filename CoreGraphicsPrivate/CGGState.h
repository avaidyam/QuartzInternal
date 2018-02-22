/* CoreGraphics - CGGState.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGGSTATE_H_
#define CGGSTATE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

enum CGCompositeMode {
	kCGCompositeSourceOver = 0,
	kCGCompositeSourceIn,
	kCGCompositeSourceOut,
	kCGCompositeSourceAtop,
	kCGCompositeCopy,
	kCGCompositeDestinationOver,
	kCGCompositeDestinationIn,
	kCGCompositeDestinationOut,
	kCGCompositeDestinationAtop, 
	kCGCompositeXOR,
	kCGCompositePlusLighter,
	kCGCompositePlusDarker,
};
typedef enum CGCompositeMode CGCompositeMode;

// TODO: Different than CGCompositeMode?
typedef enum {
    kCGCompositeCopy = 1,
    kCGCompositeSover = 2,
} CGCompositeOperation;

enum {
    kCGClipHasMask = 1
};
typedef uint32_t CGClipInfo;

typedef struct __CGClip *CGClipRef;

typedef struct CGDevice *CGDeviceRef;

typedef struct CGStateStroke *CGStateStrokeRef;

typedef struct CGStateText *CGStateTextRef;

typedef struct CGGStateRendering *CGGStateRenderingRef;

typedef struct CGClipStack *CGClipStackRef;

typedef struct CGGState *CGGStateRef;

typedef struct __CGGStack *CGGStackRef;

CG_EXTERN CGGStateRef push(CGGStackRef stack, CGGStateRef agState);

CG_EXTERN CGGStackRef CGGStackCreate();

CG_EXTERN CGGStackRef CGGStackCreateWithGState(CGGStateRef gstate);

CG_EXTERN CGGStateRef CGGStackGetGState(CGGStackRef stack);

CG_EXTERN CGGStateRef CGGStackSave(CGGStackRef stack);

CG_EXTERN CGGStateRef CGGStackRestore(CGGStackRef stack);

CG_EXTERN void CGGStackReset(CGGStackRef stack);

CG_EXTERN void CGGStackRelease(CGGStackRef stack);

CG_EXTERN CGGStateRef CGGStateCreate();

CG_EXTERN CGGStateRef CGGStateCreateCopy(CGGStateRef state);

CG_EXTERN void CGGStateClipCopy(CGGStateRef state, CGGStateRef stateSrc);

CG_EXTERN void CGGStateDeviceCopy(CGGStateRef state, CGGStateRef stateSrc);

CG_EXTERN void CGGStateRenderingCopy(CGGStateRef state, CGGStateRef stateSrc);

CG_EXTERN void CGGStateStrokeCopy(CGGStateRef state, CGGStateRef stateSrc);

CG_EXTERN void CGGStateTextCopy(CGGStateRef state, CGGStateRef stateSrc);

CG_EXTERN void CGGStateReset(CGGStateRef state);

CG_EXTERN void CGGStateClipReset(CGGStateRef state);

CG_EXTERN void CGGStateResetClip(CGGStateRef state);

CG_EXTERN CGAffineTransform CGGStateGetCTM(CGGStateRef state);

CG_EXTERN CGColorRef CGGStateGetFillColor(CGGStateRef state);

CG_EXTERN CGColorRef CGGStateGetStrokeColor(CGGStateRef state);

CG_EXTERN void CGGStateSetAlpha(CGGStateRef state, CGFloat alpha);

CG_EXTERN CGFloat CGGStateGetLineWidth(CGGStateRef state);

CG_EXTERN CGFloat CGGStateGetFlatness(CGGStateRef state);

CG_EXTERN void CGGStateSetCTM(CGGStateRef state, CGAffineTransform ctm);

CG_EXTERN void CGGStateSetCompositeOperation(CGGStateRef gstate, CGCompositeMode compositeMode);

CG_EXTERN void CGGStateSetLineWidth(CGGStateRef state, CGFloat width);

CG_EXTERN void CGGStateSetLineCap(CGGStateRef state, CGLineCap cap);

CG_EXTERN void CGGStateSetLineDash(CGGStateRef state, CGDashRef dash);

CG_EXTERN void CGGStateSetLineJoin(CGGStateRef state, CGLineJoin join);

CG_EXTERN void CGGStateSetMiterLimit(CGGStateRef state, CGFloat miter);

CG_EXTERN void CGGStateSetFlatness(CGGStateRef state, CGFloat flatness);

CG_EXTERN void CGGStateSetStrokeAdjust(CGGStateRef state, CGFloat strokeAdjust);

CG_EXTERN void CGGStateSetFillColor(CGGStateRef agstate, CGColorRef color);

CG_EXTERN void CGGStateSetFontSize(CGGStateRef agstate, CGFloat size);

CG_EXTERN void CGGStateSetBlackGeneration(CGGStateRef gstate, CGFunctionRef blackGeneration);

CG_EXTERN void CGGStateSetUndercolorRemoval(CGGStateRef gstate, CGFunctionRef underColorRemoval);

CG_EXTERN void CGGStateDeviceReset(CGGStateRef agstate);

CG_EXTERN void CGGStateTextReset(CGGStateRef agstate);

CG_EXTERN void CGGStateRenderingReset(CGGStateRef agstate);

CG_EXTERN void CGGStateStrokeReset(CGGStateRef agstate);

CG_EXTERN void CGGStateRelease(CGGStateRef state);

CG_EXTERN void CGGStateClipRelease(CGGStateRef state);

CG_EXTERN void CGGStateDeviceRelease(CGGStateRef state);

CG_EXTERN void CGGStateRenderingRelease(CGGStateRef state);

CG_EXTERN void CGGStateStrokeRelease(CGGStateRef state);

CG_EXTERN void CGGStateTextRelease(CGGStateRef state);

CG_EXTERN void CGClipRelease(CGClipRef clip);

CG_EXTERN CGClipStackRef CGClipStackCreateMutable();

CG_EXTERN void CGClipStackRelease(CGClipStackRef clipStack);

CG_EXTERN CGClipStackRef CGClipStackRetain(CGClipStackRef clipStack);

CG_EXTERN void CGGStateClipToPath(CGGStateRef state, CGPathRef path, CGPathDrawingMode mode);

CF_EXTERN_C_END

#endif /* CGGSTATE_H_ */


