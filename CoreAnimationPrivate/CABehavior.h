/* CoreAnimation - CABehavior.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CABEHAVIOR_H
#define CABEHAVIOR_H

#include <QuartzCore/CABase.h>
#include "CAPropertyInfo.h"

CA_EXTERN_C_BEGIN

@class CABehavior;

@protocol CABehaviorDelegate <NSObject>

@optional

- (void)behaviorDidStop:(CABehavior *)behavior;

@end

@interface CABehavior: NSObject <NSSecureCoding, NSCopying, CAPropertyInfo>

+ (instancetype)behavior;

@property (copy) NSDictionary *style;
@property (weak) id <CABehaviorDelegate> delegate;
@property (getter=isEnabled) BOOL enabled;
@property (copy) NSString *name;

@end

@interface CADynamicsBehavior: CABehavior

@property BOOL reactsToCollisions;
@property double angularDrag;
@property double drag;
@property double springScale;
@property double collisionInterval;
@property double stoppedAngularVelocity;
@property double stoppedVelocity;
@property double minimumTimeStep;
@property double timeStep;
@property (copy) NSArray *forceFields;
@property (copy) NSArray *springs;

@end

@interface CALayer (Behaviors)

@property (copy) NSArray *behaviors;

@end

CA_EXTERN_C_END

#endif // CABEHAVIOR_H
