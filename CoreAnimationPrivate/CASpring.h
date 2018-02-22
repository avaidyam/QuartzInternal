/* CoreAnimation - CASpring.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CASPRING_H
#define CASPRING_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@protocol CASpringDelegate <NSObject>
@end

@interface CASpring : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>

+ (instancetype)spring;

@property (weak) id <CASpringDelegate> delegate;
@property (retain) CAValueFunction *function;
@property double restLength;
@property double damping;
@property double stiffness;
@property CGPoint attachmentPointB;
@property CGPoint attachmentPointA;
@property (retain) CALayer *layerB;
@property (retain) CALayer *layerA;
@property (getter=isEnabled) BOOL enabled;
@property (copy) NSString *name;

@end

@interface CASpringAnimation ()

@property double velocity;

- (double)durationForEpsilon:(double)epsilon;

@end

CA_EXTERN_C_END

#endif // CASPRING_H
