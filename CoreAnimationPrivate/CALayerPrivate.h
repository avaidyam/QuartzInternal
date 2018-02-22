/* CoreAnimation - CALayerPrivate.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CALAYERPRIVATE_H
#define CALAYERPRIVATE_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@interface CALayer ()

@property BOOL rasterizationPrefersDisplayCompositing;
@property CGColorRef contentsMultiplyColor;
@property BOOL contentsContainsSubtitles;
@property BOOL cornerContentsMasksEdges;
@property BOOL continuousCorners;
@property CGRect cornerContentsCenter;
@property (strong) id cornerContents;
@property uint32_t disableUpdateMask;
@property BOOL acceleratesDrawing;
@property CGSize backgroundColorPhase;
@property CGSize sizeRequisition;
@property (getter=isFloating) BOOL floating;
@property BOOL allowsGroupBlending;
@property BOOL allowsDisplayCompositing;
@property BOOL preloadsCache;
@property double motionBlurAmount;
@property BOOL inheritsTiming;
@property BOOL contentsOpaque;
@property BOOL contentsDither;
@property CGAffineTransform contentsTransform;
@property BOOL shadowPathIsBounds;
@property BOOL invertsShadow;
@property BOOL flipsHorizontalAxis;
@property BOOL sortsSublayers;
@property BOOL needsLayoutOnGeometryChange;
@property (getter=isFrozen) BOOL frozen;
@property (getter=isFlipped) BOOL flipped;
@property BOOL clearsContext;
@property BOOL canDrawConcurrently;
@property BOOL literalContentsCenter;
@property BOOL hitTestsAsOpaque;
@property BOOL allowsHitTesting;
@property BOOL allowsGroupOpacity;
@property BOOL allowsEdgeAntialiasing;
@property BOOL allowsContentsRectCornerMasking;
@property double velocityStretch;
@property double coefficientOfRestitution;
@property double momentOfInertia;
@property double mass;
@property uint32_t layoutFlags;
@property BOOL wantsExtendedDynamicRangeContent;
@property (readonly) CGSize size;
@property (readonly) CGSize preferredFrameSize;

- (instancetype)_initWithReference:(CALayer *)layer;

- (CGRect)_visibleRectOfLayer:(CALayer *)layer;
- (void)scrollRectToVisible:(CGRect)rect;
- (void)_scrollRect:(CGRect)rect fromLayer:(CALayer *)layer;
- (void)scrollPoint:(CGPoint)point;
- (void)_scrollPoint:(CGPoint)point fromLayer:(CALayer *)layer;

- (void)layerDidChangeDisplay:(uint32_t)display;
- (void)layerDidBecomeVisible:(BOOL)visible;
- (void)reloadValueForKeyPath:(NSString *)keyPath;

- (id)sublayerEnumerator;
- (id)ancestorSharedWithLayer:(CALayer *)layer;
- (BOOL)isDescendantOf:(CALayer *)layer;

- (void)_contentsFormatDidChange:(id)arg1;
- (void)_cancelAnimationTimer;
- (BOOL)_scheduleAnimationTimer;
- (BOOL)_defersDidBecomeVisiblePostCommit;
- (id)layerBeingDrawn;
- (BOOL)ignoresHitTesting;
- (void)layoutBelowIfNeeded;
- (BOOL)layoutIsActive;
- (void)setContentsChanged;
- (void)invalidateContents;
- (void)clearHasBeenCommitted;
- (BOOL)hasBeenCommitted;
- (BOOL)drawsMipmapLevels;

@end

/** Layer contents formats. **/

CA_EXTERN NSString * const kCAContentsFormatRGBA8;
CA_EXTERN NSString * const kCAContentsFormatRGBAh;
CA_EXTERN NSString * const kCAContentsFormatRGBA10XR;
CA_EXTERN NSString * const kCAContentsFormatRGBA16Uint;
CA_EXTERN NSString * const kCAContentsFormatA8;
CA_EXTERN NSString * const kCAContentsFormatRGBA8ColorRGBA8LinearGlyphMask;
CA_EXTERN NSString * const kCAContentsFormatRGBA8ColorA8LinearGlyphMask;

/** Scaling filter types. **/

CA_EXTERN NSString * const kCAFilterCubic;
CA_EXTERN NSString * const kCAFilterLanczos;

/** Layer contents scaling types. **/

CA_EXTERN NSString * const kCAContentsScalingStretch;
CA_EXTERN NSString * const kCAContentsScalingRepeat;

CA_EXTERN_C_END

#endif // CALAYERPRIVATE_H
