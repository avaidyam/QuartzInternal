/* CoreAnimation - CAAnimationPrivate.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAANIMATIONPRIVATE_H
#define CAANIMATIONPRIVATE_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@class CAAnimation, CALayer;

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

@interface CABasicAnimation ()

@property CGFloat endAngle;
@property CGFloat startAngle;
@property BOOL roundsToInteger;

- (CFTimeInterval)_timeFunction:(CFTimeInterval)interval;

@end

@interface CAAnimationGroup ()

- (void)setDefaultDuration:(CFTimeInterval)duration;

@end

@interface CATransition ()

@property uint32_t transitionFlags;
@property (copy) NSDictionary *options;

@end

@interface CAMediaTimingFunction ()

- (float)_solveForInput:(float)value;

@end

@interface CATransaction (ImplicitAnimation)

+ (CAAnimation *)_implicitAnimationForLayer:(CALayer *)layer keyPath:(NSString *)keyPath;

@end

@interface CALayer (ImplicitAnimation)

- (id)implicitAnimationForKeyPath:(NSString *)keyPath;

@end

/** Animation fill modes. **/

CA_EXTERN NSString * const kCAFillModeFrozen;

/** Animation property settings. **/

CA_EXTERN NSString * const kCAAnimationNonZero;
CA_EXTERN NSString * const kCAAnimationAbsolute;
CA_EXTERN NSString * const kCAAnimationRelative;

CA_EXTERN_C_END

#endif // CAANIMATIONPRIVATE_H
