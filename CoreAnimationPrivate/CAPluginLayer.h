/* CoreAnimation - CAPluginLayer.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAPLUGINLAYER_H
#define CAPLUGINLAYER_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

/* The `CAPluginLayer` supports WindowServer plugins; currently only one is
 * available. See below for details.
 *
 * The layer tree containing this layer must be hosted in the WindowServer.
 * See `-[NSWindow setCanHostLayersInWindowServer:]` and `-[NSView setLayerUsesCoreImageFilters:]`. */
@interface CAPluginLayer : CALayer

/* See `-[CALayer contentsGravity]`. The same values are accepted. */
@property (copy) NSString *pluginGravity;

/* The plugin type-dependent plugin flags. See below for available types. */
@property uint32_t pluginFlags;

/* The plugin type-depdent plugin id. See below for available types. */
@property uint64_t pluginId;

/* The WindowServer plugin to apply. See below for available types. */
@property (copy) NSString *pluginType;

@end

/** Plugin layer types (macOS only). **/

/* Currently the only supported plugin type, on macOS. Mirrors a CGSWindow into
 * the contents of the layer, if layers are hosted in the WindowServer.
 *
 * The mirrored window contents are not visible to the host application.
 *
 * `pluginId`: the CGSWindowID to mirror into the layer contents.
 * `pluginFlags`: (1 << 2): remove the window shadow when mirroring. */
static NSString *kCAPluginLayerTypeCGSWindow = @"com.apple.WindowServer.CGSWindow";

CA_EXTERN_C_END

#endif // CAPLUGINLAYER_H
