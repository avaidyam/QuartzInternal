/* CoreAnimation - CAMiscLayersPrivate.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAMISCLAYERSPRIVATE_H
#define CAMISCLAYERSPRIVATE_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

typedef void *CALinearMaskContextRef;

@interface CALinearMaskLayer : CALayer

@property CGColorRef foregroundColor;

- (void)drawInLinearMaskContext:(CALinearMaskContextRef)context;

@end

@interface CATextLayer ()

@property (readonly, getter=isTruncated) BOOL truncated;
@property (copy) id truncationString;

@end

@interface CASmoothedTextLayer : CATextLayer

@property uint32_t fontSmoothingStyle;

@end

@interface CAGradientLayer ()

@property (strong) id colorMap;

@end

@interface CAMetalDrawable: NSObject <CAMetalDrawable>

@property (nonatomic) uint32_t presentScheduledInsertSeed;

- (void)presentAtTime:(CFTimeInterval)time;
- (void)present;
- (void)didScheduledPresent;
- (void)addPresentScheduledHandler:(id/*block*/)handler;

@end

@interface CAMetalLayer ()

@property BOOL serverSyncEnabled;
@property BOOL fenceEnabled;
@property BOOL nonDefaultColorspace;

- (id)newDrawable;
- (void)setColorspace:(CGColorSpaceRef)colorspace nonDefault:(BOOL)nonDefault;
- (void)discardContents;
- (BOOL)isDrawableAvailable;

@end

@interface CAOpenGLLayer ()

+ (BOOL)shouldRenderOnBackgroundThread;

@property uint64_t maximumDrawableCount;
@property float maximumFrameRate;

- (void)invalidateContents;

@end

@interface CATiledLayer ()

+ (uint32_t)prefetchedTiles;
+ (BOOL)shouldDrawOnMainThread;

@property (getter=isDrawingEnabled) BOOL drawingEnabled;
@property double maximumTileScale;
@property CGColorRef fillColor;

- (void)invalidateContents;
- (void)displayInRect:(CGRect)arg1 levelOfDetail:(int)arg2 options:(id)arg3;
- (BOOL)canDrawRect:(CGRect)arg1 levelOfDetail:(int)arg2;
- (void)setNeedsDisplayInRect:(CGRect)arg1 levelOfDetail:(int)arg2;
- (void)setNeedsDisplayInRect:(CGRect)arg1 levelOfDetail:(int)arg2 options:(id)arg3;

@end

/** Tiled layer properties. **/

CA_EXTERN NSString * const kCATiledLayerUncollectable;
CA_EXTERN NSString * const kCATiledLayerDisableFade;
CA_EXTERN NSString * const kCATiledLayerOnlyIfNull;
CA_EXTERN NSString * const kCATiledLayerRemoveImmediately;

/** Gradient layer types. **/

CA_EXTERN NSString * const kCAGradientLayerRadial;

CA_EXTERN_C_END

#endif // CAMISCLAYERSPRIVATE_H
