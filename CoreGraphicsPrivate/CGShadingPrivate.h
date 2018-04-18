/* CoreGraphics - CGShadingPrivate.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGSHADINGPRIVATE_H_
#define CGSHADINGPRIVATE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

#include <CoreGraphics/CGShading.h>
#include <CoreGraphics/CGAffineTransform.h>
#include <CoreGraphics/CGContext.h>
#include <CoreGraphics/CGNotificationCenter.h>

/* The type of a shading. */ 

enum CGShadingType {
    kCGShadingNone,
    kCGShadingProcedural = kCGShadingNone,
    kCGShadingAxial,
    kCGShadingRadial,
    kCGShadingCustom,
    kCGShadingCoreImage
};
typedef enum CGShadingType CGShadingType;

/* The name of the notification posted when a shading is going away. */

CG_EXTERN const CFStringRef kCGShadingWillDeallocate;

/* Data for a axial shading. */

struct CGShadingAxialInfo {
    CGPoint start;
    bool extendStart;
    CGPoint end;
    bool extendEnd;
    CGFloat domain[2];
    CGFunctionRef function;
};
typedef struct CGShadingAxialInfo CGShadingAxialInfo;

/* Data for a radial shading. */

struct CGShadingRadialInfo {
    CGPoint start;
    CGFloat startRadius;
    bool extendStart;
    CGPoint end;
    CGFloat endRadius;
    bool extendEnd;
    CGFloat domain[2];
    CGFunctionRef function;
};
typedef struct CGShadingRadialInfo CGShadingRadialInfo;

/* Data for a custom shading. */

struct CGShadingCustomInfo {
    CGFloat domain[4];
    CGFunctionRef function;
    CGAffineTransform matrix;
};
typedef struct CGShadingCustomInfo CGShadingCustomInfo;

/* Data for a core image shading. */

struct CGShadingCoreImageInfo {
    CFTypeRef image;
    CFDictionaryRef options;
};
typedef struct CGShadingCoreImageInfo CGShadingCoreImageInfo;

/* Data for a shading. */

union CGShadingDescriptor {
    CGShadingAxialInfo axial;
    CGShadingRadialInfo radial;
    CGShadingCustomInfo custom;
    CGShadingCoreImageInfo coreimage;
};
typedef union CGShadingDescriptor CGShadingDescriptor;

/* Return the shading notification center */

CG_EXTERN CGNotificationCenterRef CGShadingNotificationCenter(void);

/* The drawing of the shading is delegated to the callbacks.
  
   `version' is the version number of the structure passed in as a parameter
   to the CGShading creation functions. The structure defined below is
   version 0.

   `drawShading' should draw the shading in the context `c'. `info' is the
   parameter originally passed to the CGCreate creation functions.

   `releaseInfo' is called when the shading is deallocated. */

typedef void (*CGShadingDrawShadingCallback)(void *info, CGContextRef c);
typedef void (*CGShadingReleaseInfoCallback)(void *info);

struct CGShadingCallbacks {
    unsigned int version;
    CGShadingDrawShadingCallback drawShading;
    CGShadingReleaseInfoCallback releaseInfo;
};
typedef struct CGShadingCallbacks CGShadingCallbacks;

/* Shading creation functions. */

CG_EXTERN CGShadingRef CGShadingCreateAxial2(CGColorSpaceRef space,
  const CGFloat *background, const CGRect *bbox, CGPoint start, CGPoint end,
  const CGFloat domain[], CGFunctionRef function, bool extendStart,
  bool extendEnd);

CG_EXTERN CGShadingRef CGShadingCreateRadial2(CGColorSpaceRef space,
  const CGFloat *background, const CGRect *bbox, CGPoint start,
  CGFloat startRadius, CGPoint end, CGFloat endRadius, const CGFloat domain[],
  CGFunctionRef function, bool extendStart, bool extendEnd);

CG_EXTERN CGShadingRef CGShadingCreateCustom(CGColorSpaceRef space,
  const CGFloat *background, const CGRect *bbox, const CGFloat domain[],
  CGAffineTransform matrix, CGFunctionRef function);

CG_EXTERN CGShadingRef CGShadingCreateWithCallbacks(CGColorSpaceRef space,
  const CGFloat *background, const CGRect *bbox, void *info,
  const CGShadingCallbacks *callbacks);

CG_EXTERN CGShadingRef CGShadingCreateWithCoreImage(CGColorSpaceRef space,
  const CGFloat *background, const CGRect *bbox, CFTypeRef image,
  CFDictionaryRef options);

CG_EXTERN CGShadingRef CGShadingCreateWithShading(CGShadingRef shading,
  CFDictionaryRef auxiliaryInfo);

/* Return the type of `shading'. */

CG_EXTERN CGShadingType CGShadingGetType(CGShadingRef shading);

/* Return the color space of `shading'. */

CG_EXTERN CGColorSpaceRef CGShadingGetColorSpace(CGShadingRef shading);

/* Return the backgound of `shading'. */

CG_EXTERN const CGFloat *CGShadingGetBackground(CGShadingRef shading);

/* Return the bounds of `shading'. */

CG_EXTERN CGRect CGShadingGetBounds(CGShadingRef shading);

/* Return the shading descriptor of `shading'. */

CG_EXTERN const CGShadingDescriptor *CGShadingGetDescriptor(CGShadingRef
  shading);

/* Return the auxiliary info of `shading'. */

CG_EXTERN CFDictionaryRef CGShadingGetAuxiliaryInfo(CGShadingRef shading);

CG_EXTERN CGPatternRef CGPatternCreateWithImage2(CGImageRef, CGAffineTransform, CGPatternTiling);

#endif /* CGSHADINGPRIVATE_H_ */
