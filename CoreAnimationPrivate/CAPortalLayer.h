/* CoreAnimation - CAPortalLayer.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAPORTALLAYER_H
#define CAPORTALLAYER_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@interface CAPortalLayer : CALayer

@property BOOL matchesTransform;
@property BOOL matchesPosition;
@property BOOL matchesOpacity;
@property BOOL hidesSourceLayer;
@property uint32_t sourceContextId;
@property uint64_t sourceLayerRenderId;
@property (weak) CALayer *sourceLayer;

@end

CA_EXTERN_C_END

#endif // CAPORTALLAYER_H
