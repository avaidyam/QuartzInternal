/* CoreAnimation - CAForceField.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAFORCEFIELD_H
#define CAFORCEFIELD_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@class CALayer;

@interface CAForceField: NSObject <NSCopying, NSMutableCopying, NSSecureCoding, CAPropertyInfo>

+ (instancetype)forceField;

@property (strong) CAValueFunction *function;
@property (strong) CALayer *layer;
@property (getter=isEnabled) BOOL enabled;
@property (copy) NSString *name;

@end

CA_EXTERN_C_END

#endif // CAFORCEFIELD_H
