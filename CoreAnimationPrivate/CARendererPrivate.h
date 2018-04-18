/* CoreAnimation - CARendererPrivate.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CARENDERERPRIVATE_H
#define CARENDERERPRIVATE_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@protocol CARendererDelegate <NSObject>
@end

@interface CARenderer ()

@property (weak) id <CARendererDelegate> delegate;
@property (strong) CAContext *context;

- (instancetype)_initWithOptions:(NSDictionary *)options;

- (BOOL)hasMissingContent;

@end

@interface CALayer (Rendering)

- (void)_prepareContext:(CGContextRef)context;
- (void)_renderBorderInContext:(CGContextRef)context;
- (void)_renderSublayersInContext:(CGContextRef)context;
- (void)_renderForegroundInContext:(CGContextRef)context;
- (void)_renderBackgroundInContext:(CGContextRef)context;

@end

/** Render callbacks. **/

CA_EXTERN NSString * const kCARenderMetalCallbacks;
CA_EXTERN NSString * const kCARenderMetalServerCallbacks;

/** Renderer properties. **/

CA_EXTERN NSString * const kCARendererDeepBuffers;

CA_EXTERN_C_END

#endif // CARENDERERPRIVATE_H
