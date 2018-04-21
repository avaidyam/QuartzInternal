/* CoreAnimation - CAAnimationPrivate.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAANIMATIONPRIVATE_H
#define CAANIMATIONPRIVATE_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@class CAAnimation, CALayer;

typedef NS_OPTIONS(uint32_t, CATransitionFlags) {
    CATransitionFlagUnknown1 = 0x1,
    CATransitionFlagUnknown2 = 0x2
};

@interface CAAnimation ()

/* Apply the animation to the `presentationObject` at the given time.
 * The `modelObject` is provided as a frame of reference. */
- (void)applyForTime:(CGFloat)time presentationObject:(id)presentationObject
         modelObject:(id)modelObject;

@end

@interface CALayer (ImplicitAnimation)

/* Provide an implicit animation generated for the `keyPath`. */
- (CAAnimation *)implicitAnimationForKeyPath:(NSString *)keyPath;

@end

@interface CAMediaTimingFunction ()

- (float)_solveForInput:(float)value;

@end

@interface CAAnimationGroup ()

/* Determines the default `duration` for sub-animations that do not declare
 * a `duration` themselves. */
- (void)setDefaultDuration:(CFTimeInterval)duration;

@end

@interface CABasicAnimation ()

/* Used in interpolation if the type of the `keyPath` is a `CGPoint`. */
@property CGFloat startAngle;

/* Used in interpolation if the type of the `keyPath` is a `CGPoint`. */
@property CGFloat endAngle;

/* Whether, if applicable by the type of the `keyPath`, the value applied
 * to the layer should be rounded to the nearest integer. */
@property BOOL roundsToInteger;

/* Solve the animation's time function for the provided time interval. Only useful
 * in `CASpringAnimation`. `CABasicAnimation` simply returns `interval`. */
- (CFTimeInterval)_timeFunction:(CFTimeInterval)interval;

@end

@interface CASpringAnimation ()

@property double velocity;

- (double)durationForEpsilon:(double)epsilon;

/* Calls -[CASpringAnimation _timeFunction:]. */
- (float)_solveForInput:(float)value;

@end

@interface CATransition ()

/* Transition flags. Currently unknown, but usually set to 0x3. */
@property CATransitionFlags transitionFlags;

@property (copy) NSDictionary *options;

@end

@interface CATransaction (ImplicitAnimation)

/* Requests `layer` to provide an implicit animation generated for the `keyPath`. */
+ (CAAnimation *)_implicitAnimationForLayer:(CALayer *)layer keyPath:(NSString *)keyPath;

@end

@interface CAMatchMoveAnimation: CAAnimation

@property (getter=isAdditive) BOOL additive;
@property BOOL appliesRotation;
@property BOOL appliesScale;
@property BOOL appliesY;
@property BOOL appliesX;
@property BOOL targetsSuperlayer;
@property (copy) NSString *keyPath;
@property (copy) NSArray *sourcePoints;
@property uint32_t sourceContextId;
@property uint64_t sourceLayerRenderId;
@property (weak) CALayer *sourceLayer;

@end

/** Animation fill modes. **/

CA_EXTERN NSString * const kCAFillModeFrozen;

/** Animation property settings. **/

CA_EXTERN NSString * const kCAAnimationNonZero;
CA_EXTERN NSString * const kCAAnimationAbsolute;
CA_EXTERN NSString * const kCAAnimationRelative;

CA_EXTERN_C_END

#endif // CAANIMATIONPRIVATE_H
