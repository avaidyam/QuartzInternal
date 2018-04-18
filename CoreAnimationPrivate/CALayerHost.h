/* CoreAnimation - CALayerHost.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CALAYERHOST_H
#define CALAYERHOST_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

/* Displays the root layer of another layer tree (through its `CAContext`).
 * Requires the layer tree to be hosted in the WindowServer. */
@interface CALayerHost: CALayer

/* The context id of the `CAContext` whose root layer should be displayed. */
@property uint32_t contextId;

@end

CA_EXTERN_C_END

#endif // CALAYERHOST_H
