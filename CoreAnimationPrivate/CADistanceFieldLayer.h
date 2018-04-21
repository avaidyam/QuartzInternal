/* CoreAnimation - CADistanceFieldLayer.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CADISTANCEFIELDLAYER_H
#define CADISTANCEFIELDLAYER_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@class CALayer;

@interface CADistanceFieldLayer : CALayer

@property CGColorRef foregroundColor;
@property double sharpness;
@property double offset;
@property double lineWidth;
@property BOOL invertsShape;
@property (copy) NSString *renderMode;

@end

/** Distance field layer properties. **/

CA_EXTERN NSString * const kCADistanceFieldLayerFill;
CA_EXTERN NSString * const kCADistanceFieldLayerStroke;
CA_EXTERN NSString * const kCADistanceFieldLayerInnerStroke;
CA_EXTERN NSString * const kCADistanceFieldLayerOuterStroke;

CA_EXTERN_C_END

#endif // CADISTANCEFIELDLAYER_H
