/* CoreAnimation - CAPluginLayer.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAPLUGINLAYER_H
#define CAPLUGINLAYER_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

static NSString *kCAPluginTypeCGSWindow = @"com.apple.WindowServer.CGSWindow";

@interface CAPluginLayer : CALayer

@property (copy) NSString *pluginGravity;
@property uint32_t pluginFlags;
@property uint64_t pluginId;
@property (copy) NSString *pluginType;

@end

CA_EXTERN_C_END

#endif // CAPLUGINLAYER_H
