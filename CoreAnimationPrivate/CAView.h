/* CoreAnimation - CAView.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAVIEW_H
#define CAVIEW_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

typedef struct _CAView *CAViewRef;

// CAViewInvalidateRect, CAViewBeginDraw, CAViewEndDraw, CAViewSetRendererFeaturers, CAViewGetRendererFeatures, CAViewSetCIFilterBehavior, CAViewGetCIFilterBehavior, CAViewSetGlobalFlags, CAViewGetGlobalFlags

CA_EXTERN CAView *CAViewCreate();

CA_EXTERN void CAViewDestroy(CAView *view);

CA_EXTERN CAContext *CAViewGetContext(CAView *view);

CA_EXTERN void CAViewEnableAsyncDrawing(CAView *view);

CA_EXTERN void CAViewDisableAsyncDrawing(CAView *view);

CA_EXTERN CALayer *CAViewGetLayer(CAView *view);

CA_EXTERN void CAViewSetLayer(CAView *view, CALayer *layer);

CA_EXTERN CGColorSpaceRef CAViewGetColorSpace(CAView *view);

CA_EXTERN void CAViewSetColorSpace(CAView *view, CGColorSpaceRef colorSpace);

CA_EXTERN void CAViewDraw(CAView *view, uint32_t flags);

// flags = 1 << 0 // isOpaque
CA_EXTERN void CAViewUpdate(CAView *view, CGSConnectionID cid, CGWindowID wid,
                            CGSSurfaceID sid, CGFloat win_x, CGFloat win_y,
                            uint32_t unknown, uint32_t flags);

CA_TEXTERN void CAViewUpdate2(CAView *view, CGSConnectionID cid, CGWindowID wid);

CA_EXTERN CFTypeID CAViewGetTypeID (void);

CA_EXTERN_C_END

#endif // CAVIEW_H
