/* CoreAnimation - CAEmitterLayerPrivate.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAEMITTERLAYERPRIVATE_H
#define CAEMITTERLAYERPRIVATE_H

#include <QuartzCore/CABase.h>
#include <QuartzCore/CAEmitterLayer.h>

CA_EXTERN_C_BEGIN

@interface CAEmitterCell ()

+ (instancetype)emitterCell;

@property double rotationRange;
@property double rotation;
@property double orientationRange;
@property double orientationLongitude;
@property double orientationLatitude;
@property float contentsFramesPerSecond;
@property uint32_t contentsFramesPerRow;
@property uint32_t contentsFrameCount;
@property (copy) NSString *contentsFrameMode;
@property (copy) NSArray *emitterBehaviors;
@property float massRange;
@property float mass;
@property (copy) NSString *particleType;

@end

@interface CAEmitterLayer ()

@property double cullMaxZ;
@property double cullMinZ;
@property CGRect cullRect;
@property float spinBias;
@property double updateInterval;
@property float emitterDuration;
@property (copy) NSArray *emitterBehaviors;
@property (copy) NSArray *emitterRects;
@property CGPathRef emitterPath;

@end

/** Emitter cell types. **/

CA_EXTERN NSString * const kCAEmitterCellSprite;
CA_EXTERN NSString * const kCAEmitterCellPlane;
CA_EXTERN NSString * const kCAEmitterCellPoint;
CA_EXTERN NSString * const kCAEmitterCellSingle;
CA_EXTERN NSString * const kCAEmitterCellRandom;
CA_EXTERN NSString * const kCAEmitterCellSequential;

/** Emitter layer properties. **/

CA_EXTERN NSString * const kCAEmitterLayerUnordered;
CA_EXTERN NSString * const kCAEmitterLayerOldestFirst;
CA_EXTERN NSString * const kCAEmitterLayerOldestLast;
CA_EXTERN NSString * const kCAEmitterLayerBackToFront;
CA_EXTERN NSString * const kCAEmitterLayerAdditive;
CA_EXTERN NSString * const kCAEmitterLayerScreen;
CA_EXTERN NSString * const kCAEmitterLayerMaximum;
CA_EXTERN NSString * const kCAEmitterLayerCheapColorDodge;
CA_EXTERN NSString * const kCAEmitterLayerPoint;
CA_EXTERN NSString * const kCAEmitterLayerLine;
CA_EXTERN NSString * const kCAEmitterLayerRectangle;
CA_EXTERN NSString * const kCAEmitterLayerCuboid;
CA_EXTERN NSString * const kCAEmitterLayerCircle;
CA_EXTERN NSString * const kCAEmitterLayerSphere;
CA_EXTERN NSString * const kCAEmitterLayerPath;
CA_EXTERN NSString * const kCAEmitterLayerRectangles;
CA_EXTERN NSString * const kCAEmitterLayerPoints;
CA_EXTERN NSString * const kCAEmitterLayerOutline;
CA_EXTERN NSString * const kCAEmitterLayerSurface;
CA_EXTERN NSString * const kCAEmitterLayerVolume;
CA_EXTERN NSString * const kCAEmitterLayerSequential;

CA_EXTERN_C_END

#endif // CAEMITTERLAYERPRIVATE_H
