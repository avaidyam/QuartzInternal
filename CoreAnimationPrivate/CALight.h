/* CoreAnimation - CALight.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CALIGHT_H
#define CALIGHT_H

#include <QuartzCore/CABase.h>
#include "CAPoint.h"

#define CA_LIGHT_UNAVAILABLE __attribute__((unavailable("CALight has been removed from CoreAnimation.")))

CA_EXTERN_C_BEGIN

@interface CALight: NSObject

+ (instancetype)lightWithType:(NSString *)type CA_LIGHT_UNAVAILABLE;

@property CAPoint3D position CA_LIGHT_UNAVAILABLE;
@property double specularIntensity CA_LIGHT_UNAVAILABLE;
@property (copy) NSString *name CA_LIGHT_UNAVAILABLE;

- (instancetype)initWithType:(NSString *)type CA_LIGHT_UNAVAILABLE;

@end

@interface CALayer (Lights)

@property (copy) NSArray<CALight *> *lights CA_LIGHT_UNAVAILABLE;

@end

/** Light types. **/

CA_EXTERN NSString * const kCALightTypeAmbient;
CA_EXTERN NSString * const kCALightTypeDirectional;
CA_EXTERN NSString * const kCALightTypePoint;
CA_EXTERN NSString * const kCALightTypeSpot;

CA_EXTERN_C_END

#endif // CALIGHT_H
