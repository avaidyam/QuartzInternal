/* CoreAnimation - CAView.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAVIEW_H
#define CAVIEW_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

#define kCAViewCIFilterBehaviorUnknown0 0x0
#define kCAViewCIFilterBehaviorEncode 0x1
#define kCAViewCIFilterBehaviorIgnore 0x2
#define kCAViewCIFilterBehaviorUnknown3 0x3
#define kCAViewCIFilterBehaviorThrow 0x4

typedef struct _CAView *CAViewRef;

// CAViewInvalidateRect, CAViewBeginDraw, CAViewEndDraw, CAViewSetRendererFeaturers, CAViewGetRendererFeatures, CAViewSetGlobalFlags, CAViewGetGlobalFlags

CA_EXTERN CAViewRef CAViewCreate();

CA_EXTERN void CAViewDestroy(CAViewRef view);

CA_EXTERN CAContext *CAViewGetContext(CAViewRef view);

CA_EXTERN void CAViewEnableAsyncDrawing(CAViewRef view);

CA_EXTERN void CAViewDisableAsyncDrawing(CAViewRef view);

CA_EXTERN CALayer *CAViewGetLayer(CAViewRef view);

CA_EXTERN void CAViewSetLayer(CAViewRef view, CALayer *layer);

CA_EXTERN CGColorSpaceRef CAViewGetColorSpace(CAViewRef view);

CA_EXTERN void CAViewSetColorSpace(CAViewRef view, CGColorSpaceRef colorSpace);

CA_EXTERN uint32_t CAViewGetCIFilterBehavior(CAViewRef view);

CA_EXTERN void CAViewSetCIFilterBehavior(CAViewRef view, uint32_t behavior);

CA_EXTERN void CAViewDraw(CAViewRef view, uint32_t flags);

// flags = 1 << 0 // isOpaque
CA_EXTERN void CAViewUpdate(CAViewRef view, CGSConnectionID cid, CGWindowID wid,
                            CGSSurfaceID sid, CGFloat win_x, CGFloat win_y,
                            uint32_t unknown, uint32_t flags);

CA_EXTERN void CAViewUpdate2(CAViewRef view, CGSConnectionID cid, CGWindowID wid);

CA_EXTERN CFTypeID CAViewGetTypeID (void);

CA_EXTERN_C_END

#endif // CAVIEW_H
