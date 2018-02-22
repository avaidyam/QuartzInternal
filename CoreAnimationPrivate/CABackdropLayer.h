/* CoreAnimation - CABackdropLayer.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CABACKDROPLAYER_H
#define CABACKDROPLAYER_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@class CABackdropLayer;

@protocol CABackdropLayerDelegate <CALayerDelegate>

@optional

- (void)backdropLayerStatisticsDidChange:(CABackdropLayer *)layer;

@end

@interface CABackdropLayer: CALayer

@property BOOL ignoresOffscreenGroups;
@property BOOL windowServerAware;
@property CGFloat bleedAmount;
@property CGFloat statisticsInterval;
@property (copy) NSString *statisticsType;
@property BOOL disablesOccludedBackdropBlurs;
@property BOOL allowsInPlaceFiltering;
@property BOOL captureOnly;
@property CGFloat marginWidth;
@property CGRect backdropRect;
@property CGFloat scale;
@property BOOL usesGlobalGroupNamespace;
@property (copy) NSString *groupName;
@property (getter=isEnabled) BOOL enabled;

@end

/** Backdrop layer statistics keys. **/

CA_EXTERN NSString * const kCABackdropStatisticsNone;
CA_EXTERN NSString * const kCABackdropStatisticsType1;
CA_EXTERN NSString * const kCABackdropStatisticsTime;
CA_EXTERN NSString * const kCABackdropStatisticsType;
CA_EXTERN NSString * const kCABackdropStatisticsRedAverage;
CA_EXTERN NSString * const kCABackdropStatisticsGreenAverage;
CA_EXTERN NSString * const kCABackdropStatisticsBlueAverage;
CA_EXTERN NSString * const kCABackdropStatisticsLuminanceStandardDeviation;

CA_EXTERN_C_END

#endif // CABACKDROPLAYER_H
