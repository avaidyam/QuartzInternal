/* CoreAnimation - CAProxyLayer.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAPROXYLAYER_H
static NSString *CAPROXYLAYER_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

/* The CAProxyLayer is used by the WindowServer on macOS to dynamically insert
 * a CGS Window Backdrop at the level of the layer in its layer tree. */
@interface CAProxyLayer: CALayer

/* The properties that should be used in creating the CGS Window Backdrop.
 * See below for valid input keys.
 *
 * Note that passing unrecognized or out-of-bounds values *will* cause
 * WindowServer to crash. */
@property (copy) NSDictionary *proxyProperties;

@end

/** Proxy layer property keys. **/

/* Must be one of the below kCAProxyLayerMaterials. String. */
CA_EXTERN NSString * const kCAProxyLayerMaterial;

/* Must be one of the below kCAProxyLayerBlendModes. String. */
CA_EXTERN NSString * const kCAProxyLayerBlendMode;

/* The level at which the new CGS Window Backdrop should be inserted in the
 * layer hierarchy. Integer. */
CA_EXTERN NSString * const kCAProxyLayerLevel;

/* Whether to draw the material as active or inactive. Boolean. */
CA_EXTERN NSString * const kCAProxyLayerActive;

/* The saturation factor of the CGS Window Backdrop. Float between [0.0, 1.0]. */
CA_EXTERN NSString * const kCAProxyLayerSaturation;

/* Proxy layer and CGS Backdrop blend modes. */

static NSString *kCAProxyLayerBlendModePlus = @"Plus"; // raw value = 0x3
static NSString *kCAProxyLayerBlendModeSover = @"Sover"; // raw value = 0x0
static NSString *kCAProxyLayerBlendModePlusD = @"PlusD"; // raw value = 0x1
static NSString *kCAProxyLayerBlendModePlusL = @"PlusL"; // raw value = 0x2

/* Synonyms for existing Proxy layer and CGS Backdrop blend modes. */

static NSString *kCAProxyLayerBlendModeP = @"P"; // synonym for "Plus"
static NSString *kCAProxyLayerBlendModeS = @"S"; // synonym for "Sover"

/* Proxy layer and CGS Backdrop materials. */

static NSString *kCAProxyLayerMaterialLight = @"Light"; // raw value = 0x0
static NSString *kCAProxyLayerMaterialHybridLight = @"HybridLight"; // raw value = 0x1
static NSString *kCAProxyLayerMaterialUltraLight = @"UltraLight"; // raw value = 0x2
static NSString *kCAProxyLayerMaterialHybridUltraLight = @"HybridUltraLight"; // raw value = 0x3
static NSString *kCAProxyLayerMaterialDark = @"Dark"; // raw value = 0x4
static NSString *kCAProxyLayerMaterialHybridDark = @"HybridDark"; // raw value = 0x6

static NSString *kCAProxyLayerMaterialMacMediumDark = @"MacMediumDark"; // raw value = 0x5

static NSString *kCAProxyLayerMaterialSelectionUnfocused = @"SelectionUnfocused"; // raw value = 0x7
static NSString *kCAProxyLayerMaterialSelectionBlue = @"SelectionBlue"; // raw value = 0x8
static NSString *kCAProxyLayerMaterialSelectionGraphite = @"SelectionGraphite"; // raw value = 0x9
static NSString *kCAProxyLayerMaterialSelectionDark = @"SelectionDark"; // raw value = 0xa
static NSString *kCAProxyLayerMaterialSelectionUnfocusedDark = @"SelectionUnfocusedDark"; // raw value = 0xb
static NSString *kCAProxyLayerMaterialSelectionBlueAlternative = @"SelectionBlueAlternative"; // raw value = 0xc
static NSString *kCAProxyLayerMaterialSelectionGraphiteAlternative = @"SelectionGraphiteAlternative"; // raw value = 0xd
static NSString *kCAProxyLayerMaterialSelectionDarkAlternative = @"SelectionDarkAlternative"; // raw value = 0xe

static NSString *kCAProxyLayerMaterialToolbar = @"Toolbar"; // raw value = 0xf
static NSString *kCAProxyLayerMaterialClear = @"Clear"; // raw value = 0x10
static NSString *kCAProxyLayerMaterialMimic = @"Mimic"; // raw value = 0x11

/* Synonyms for existing Proxy layer and CGS Backdrop materials. */

static NSString *kCAProxyLayerMaterialMacLight = @"MacLight"; // synonym for "HybridLight"
static NSString *kCAProxyLayerMaterialUltralight = @"Ultralight"; // synonym for "UltraLight"
static NSString *kCAProxyLayerMaterialMacUltralight = @"MacUltralight"; // synonym for "HybridUltraLight"
static NSString *kCAProxyLayerMaterialMacUltradark = @"MacUltradark"; // synonym for "Dark"
static NSString *kCAProxyLayerMaterialMacDark = @"MacDark"; // synonym for "HybridDark"

static NSString *kCAProxyLayerMaterialL = @"L"; // synonym for "Light"
static NSString *kCAProxyLayerMaterialHL = @"HL"; // synonym for "HybridLight"
static NSString *kCAProxyLayerMaterialUL = @"UL"; // synonym for "UltraLight"
static NSString *kCAProxyLayerMaterialHUL = @"HUL"; // synonym for "HybridUltraLight"
static NSString *kCAProxyLayerMaterialD = @"D"; // synonym for "Dark"
static NSString *kCAProxyLayerMaterialHD = @"HD"; // synonym for "HybridDark"

static NSString *kCAProxyLayerMaterialUnfocused = @"Unfocused"; // synonym for "SelectionUnfocused"
static NSString *kCAProxyLayerMaterialBlue = @"Blue"; // synonym for "SelectionBlue"
static NSString *kCAProxyLayerMaterialGraphite = @"Graphite"; // synonym for "SelectionGraphite"

CA_EXTERN_C_END

#endif // CAPROXYLAYER_H
