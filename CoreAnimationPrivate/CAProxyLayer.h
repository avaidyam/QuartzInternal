/* CoreAnimation - CAProxyLayer.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAPROXYLAYER_H
#define CAPROXYLAYER_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@interface CAProxyLayer : CALayer

@property (copy) NSDictionary *proxyProperties;

@end

/** Proxy layer properties. **/

CA_EXTERN NSString * const kCAProxyLayerMaterial;
CA_EXTERN NSString * const kCAProxyLayerBlendMode;
CA_EXTERN NSString * const kCAProxyLayerLevel;
CA_EXTERN NSString * const kCAProxyLayerActive;
CA_EXTERN NSString * const kCAProxyLayerSaturation;

CA_EXTERN_C_END

#endif // CAPROXYLAYER_H
