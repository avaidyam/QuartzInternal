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

@interface CALayer (CABehavior)

@property (copy) NSArray *behaviors;
@property double velocityStretch;

@end

CA_EXTERN_C_END

#endif // CABEHAVIOR_H
