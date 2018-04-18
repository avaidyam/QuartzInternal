/* CoreGraphics - CGFontPrivate.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGFONTPRIVATE_H_
#define CGFONTPRIVATE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef struct CGFontCache CGFontCache;

struct CGFontHMetrics {
    int ascent;
    int descent;
    int lineGap;
    int maxAdvanceWidth;
    int minLeftSideBearing;
    int minRightSideBearing;
};

struct CGFontDescriptor {
    CGRect bbox;
    CGFloat ascent;
    CGFloat descent;
    CGFloat capHeight;
    CGFloat italicAngle;
    CGFloat stemV;
    CGFloat stemH;
    CGFloat avgWidth;
    CGFloat maxWidth;
    CGFloat missingWidth;
    CGFloat leading;
    CGFloat xHeight;
};

enum {
    kCGFontRenderingStyleAntialiasing = 1 << 0,
    kCGFontRenderingStyleSmoothing = 1 << 1,
    kCGFontRenderingStyleSubpixelPositioning = 1 << 2,
    kCGFontRenderingStyleSubpixelQuantization = 1 << 3,
    kCGFontRenderingStylePlatformNative = 1 << 9,
    kCGFontRenderingStyleMask = 0x20F,
};
typedef uint32_t CGFontRenderingStyle;

enum {
    kCGFontAntialiasingStyleUnfiltered = 0 << 7,
    kCGFontAntialiasingStyleFilterLight = 1 << 7,
#if PLATFORM(MAC) && __MAC_OS_X_VERSION_MIN_REQUIRED >= 101100
    kCGFontAntialiasingStyleUnfilteredCustomDilation = (8 << 7),
#endif
};
typedef uint32_t CGFontAntialiasingStyle;

/* Windows:
typedef struct CGFontCache CGFontCache;
typedef CGFontCache *CGFontCacheRef;
 
CG_EXTERN CGFontCacheRef CGFontCacheGetLocalCache();

CG_EXTERN void CGFontCacheSetShouldAutoExpire(CGFontCacheRef cache, bool shouldAutoExpire);

CG_EXTERN void CGFontCacheSetMaxSize(CGFontCacheRef cache, size_t size);
*/

CG_EXTERN CFStringRef CGFontCopyFamilyName(CGFontRef font);

CG_EXTERN bool CGFontGetDescriptor(CGFontRef font, CGFontDescriptor *outDescriptor);

CG_EXTERN bool CGFontGetGlyphAdvancesForStyle(CGFontRef font, const CGAffineTransform *transform,
                                              CGFontRenderingStyle style, const CGGlyph[] glyphs,
                                              size_t count, CGSize advances[]);

CG_EXTERN void CGFontGetGlyphsForUnichars(CGFontRef font, const UniChar[], CGGlyph[], size_t count);

CG_EXTERN const CGFontHMetrics* CGFontGetHMetrics(CGFontRef font);

CG_EXTERN const char *CGFontGetPostScriptName(CGFontRef font);

CG_EXTERN bool CGFontIsFixedPitch(CGFontRef font);

CG_EXTERN void CGFontSetShouldUseMulticache(bool shouldUseMulticache);

CF_EXTERN_C_END

#endif /* CGFONTPRIVATE_H_ */
