/* CoreAnimation - CAPortalLayer.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAPORTALLAYER_H
#define CAPORTALLAYER_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

/* The `CAPortalLayer` mirrors a layer within the same, or different, layer tree,
 * optionally matching its transform, position, and opacity. */
@interface CAPortalLayer : CALayer

/* The layer to mirror, if within the same layer tree (same `CAContext`).
 * If not set, `sourceContextId` and `sourceLayerRenderId` must be set. */
@property (weak) CALayer *sourceLayer;

/* The context (layer tree) of the source layer to mirror from.
 * Requires `sourceLayerRenderId`. If not set, `sourceLayer` must be set. */
@property uint32_t sourceContextId;

/* The layer render id of the source layer within the `sourceContextId` to mirror.
 * Requires `sourceContextId`. If not set, `sourceLayer` must be set. */
@property uint64_t sourceLayerRenderId;

/* The portal layer's transform is set to the source layer's transform. */
@property BOOL matchesTransform;

/* The portal layer's position is set to the source layer's position. */
@property BOOL matchesPosition;

/* The portal layer's opacity is set to the source layer's opacity. */
@property BOOL matchesOpacity;

/* The source layer is hidden; only the portal layer is visible, mirroring it. */
@property BOOL hidesSourceLayer;

@end

/* Returns the layer's render ID (used by the render context). */
CA_EXTERN uint64_t CALayerGetRenderId(CALayer *layer);

CA_EXTERN_C_END

#endif // CAPORTALLAYER_H
