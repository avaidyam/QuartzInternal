/* CoreAnimation - CASpring.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CASPRING_H
#define CASPRING_H

#include <QuartzCore/CABase.h>

NS_ASSUME_NONNULL_BEGIN

@protocol CASpringDelegate <NSObject>
@end

@interface CASpring : NSObject <NSCopying, NSMutableCopying, NSSecureCoding>

+ (instancetype)spring;

@property (weak, nullable) id <CASpringDelegate> delegate;
@property (strong, nullable) CAValueFunction *function;
@property double restLength;
@property double damping;
@property double stiffness;
@property CGPoint attachmentPointB;
@property CGPoint attachmentPointA;
@property (strong) CALayer *layerB;
@property (strong) CALayer *layerA;
@property (getter=isEnabled) BOOL enabled;
@property (copy) NSString *name;

@end

NS_ASSUME_NONNULL_END

#endif // CASPRING_H
