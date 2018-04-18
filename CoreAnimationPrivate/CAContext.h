/* CoreAnimation - CAContext.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CACONTEXT_H
#define CACONTEXT_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@interface CAContext : NSObject

@property (class) BOOL allowsCGSConnections;

+ (instancetype)contextWithCGSConnection:(CGSConnectionID)connectionId options:(NSDictionary *)options;
+ (instancetype)remoteContextWithOptions:(NSDictionary *)options;
+ (instancetype)remoteContext;
+ (instancetype)localContextWithOptions:(NSDictionary *)options;
+ (instancetype)localContext;
+ (instancetype)currentContext;

+ (NSArray<__kindof CAContext *> *)allContexts;
+ (CASlotProxy *)objectForSlot:(uint32_t)slot;
+ (void)setClientPort:(mach_port_t)port;

@property BOOL colorMatchUntaggedContent;
@property CGColorSpaceRef colorSpace;
@property uint32_t commitPriority;
@property (copy) NSString *contentsFormat;
@property (readonly) uint32_t contextId;
@property uint32_t displayMask;
@property uint32_t displayNumber;
@property uint32_t eventMask;
@property (strong) CALayer *layer;
@property (readonly) NSDictionary *options;
@property int restrictedHostProcessId;
@property (readonly) BOOL valid;

- (void)invalidate;

- (uint32_t)createSlot;
- (void)setObject:(id)object forSlot:(uint32_t)slot;
- (void)deleteSlot:(uint32_t)slot;

- (mach_port_t)createFencePort;
- (void)setFence:(uint32_t)fence count:(uint32_t)count;
- (void)setFencePort:(mach_port_t)port commitHandler:(void(^)(void))handler;
- (void)setFencePort:(mach_port_t)port;
- (void)invalidateFences;

@end

/* Can be used as the value of `CALayer.contents`. */
@interface CASlotProxy: NSObject

- (instancetype)initWithName:(uint32_t)slotName;

@end

@interface CARemoteLayerClient ()

- (CAContext *)context;

@end

@interface CALayer (CAContext)

@property (readonly) CAContext *context;

@end

/** Context properties. **/

CA_EXTERN NSString * const kCAContextPortName;
CA_EXTERN NSString * const kCAContextPortNumber;
CA_EXTERN NSString * const kCAContextClientPortNumber;
CA_EXTERN NSString * const kCAContextEnablePixelDoubling;
CA_EXTERN NSString * const kCAContextEnablePixelQuadrupling;
CA_EXTERN NSString * const kCAContextDisableGroupOpacity;
CA_EXTERN NSString * const kCAContextDisableEdgeAntialiasing;

/**
 Can be @"ignore", @"encode", or @"throw". Remaining options are unknown.
 **/
CA_EXTERN NSString * const kCAContextCIFilterBehavior;

CA_EXTERN NSString * const kCAContextCanBeObscured;
CA_EXTERN NSString * const kCAContextCanZombify;

CA_EXTERN_C_END

#endif // CACONTEXT_H
