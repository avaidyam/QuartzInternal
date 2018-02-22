/* CoreAnimation - CALight.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CALIGHT_H
#define CALIGHT_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@interface CALight: NSObject

+ (instancetype)lightWithType:(NSString *)type;

@property CAPoint3D position;
@property double specularIntensity;
@property (copy) NSString *name;

- (instancetype)initWithType:(NSString *)type;

@end

@interface CALayer (Lights)

@property (copy) NSArray *lights;

@end

/** Light types. **/

CA_EXTERN NSString * const kCALightTypeAmbient;
CA_EXTERN NSString * const kCALightTypeDirectional;
CA_EXTERN NSString * const kCALightTypePoint;
CA_EXTERN NSString * const kCALightTypeSpot;

CA_EXTERN_C_END

#endif // CALIGHT_H
