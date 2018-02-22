/* CoreAnimation - CARender.h

   Copyright (c) 2006-2007 Apple Inc.
   All rights reserved. */

/* The render tree data structures. These are internal to the framework,
   and totally separate from the layer tree, i.e. a render tree can live
   in a separate address space from the layer tree it was produced from.

   WARNING: Don't use these SPIs - anything prefixed by CARender is only
   designed to be used by CoreAnimation or the Window Server. We change
   these interfaces without considering binary compatibility. */

#ifndef CARENDER_H
#define CARENDER_H

#include <QuartzCore/CATransform3D.h>
#ifdef __OBJC__
#import <QuartzCore/CAContext.h>
#endif
#include <CoreVideo/CVBase.h>

/* Renderer features. */

enum CARenderFeatureFlags
{
  kCARenderFlippedGeometry		= 1U << 0,
  kCARenderFlippedImages		= 1U << 1,
  kCARenderDisableGroupOpacity		= 1U << 2,
  kCARenderDisableEdgeAA		= 1U << 3,
  kCARenderMinimizeScissorChanges	= 1U << 4,
  kCARenderDeviceDependentCoreImage	= 1U << 5,
  kCARenderDisableImageProviderFade	= 1U << 6,
  kCARenderDisableColorMatching		= 1U << 7,
  kCARenderDisableParametricColorMatching = 1U << 9,
};

/* We use ids to represent render objects in some places. */

typedef uintptr_t CARenderId;

/* A pointer to a render tree object. */

#ifndef CA_NO_RENDER_TYPES
typedef void *CARenderRef;
#endif

/* Type used to cache per-render iteration state. */

#ifndef CA_NO_RENDER_TYPES
typedef struct _CARenderUpdate CARenderUpdate;
#endif

/* Render object types. */

#ifndef CA_NO_RENDER_TYPES
typedef struct _CARenderContext CARenderContext;
typedef struct _CARenderImage CARenderImage;
typedef struct _CARenderLayer CARenderLayer;
typedef struct _CARenderSurface CARenderSurface;
#endif

CA_EXTERN_C_BEGIN

/** Render object functions. **/

/* Adds a reference to 'obj'. */

CA_EXTERN CARenderRef CARenderRetain (CARenderRef obj);

/* Removes a reference from 'obj'. */

CA_EXTERN void CARenderRelease (CARenderRef obj);

/* Prints a textual representation of 'obj' to stderr. */

CA_EXTERN void CARenderShow (CARenderRef obj);

/* Prints debugging info about render object allocations. */

CA_EXTERN void CARenderShowStatistics (void);

/** Render context functions. **/

/* Create a new render context. */

CA_EXTERN CARenderContext *CARenderContextNew (CFDictionaryRef options);

/* Destroys 'ctx' and all resources associated with it. */

CA_EXTERN void CARenderContextDestroy (CARenderContext *ctx);

/* Returns the render context whose unique identifier is 'id'. Caller is
 * responsible for releasing the returned object. */

CA_EXTERN CARenderContext *CARenderContextById (uint32_t id);

/* Returns the (possibly null) dictionary associated with 'ctx'. */

CA_EXTERN CFDictionaryRef CARenderContextGetOptions (CARenderContext *ctx);

/* Returns the unique identifier of 'ctx'. */

CA_EXTERN uint32_t CARenderContextGetId (CARenderContext *ctx);

/* The context's commit seed changes whenever the context has changes
 * committed into it. */

CA_EXTERN uint32_t CARenderContextGetCommitSeed (CARenderContext *ctx);

/* Locks and unlocks 'ctx'. Lock may be obtained multiple times
 * concurrently by the same thread. */

CA_EXTERN void CARenderContextLock (CARenderContext *ctx);
CA_EXTERN void CARenderContextUnlock (CARenderContext *ctx);

/* Adds the contents of 'rect' to the context's dirty region. */

CA_EXTERN void CARenderContextInvalidateRect (CARenderContext *ctx,
    const CGRect *rect);

/* 'ctx' should be locked. Returned layer should not be released by
 * caller when non-null. */

CA_EXTERN CARenderLayer *CARenderContextHitTest (CARenderContext *ctx,
     CGPoint p, uint32_t options);

/* Functions to query the current geometry of the layer tree hosted by
 * the specified context. The context's geometry seed is incremented
 * whenever either of the shapes changes. */

CA_EXTERN uint32_t CARenderContextGetGeometrySeed (CARenderContext *ctx);
CA_EXTERN void *CARenderContextCopyBoundsRegion (CARenderContext *ctx);
CA_EXTERN void *CARenderContextCopyOpaqueRegion (CARenderContext *ctx);

/** Updater functions. **/

/* Creates a new updater object. 'buffer' if non-null is space for the
 * updater to use, it contains 'size' bytes. 't' and 'ts' define the
 * update time. 'bounds' defines the bounds of the update. */

CA_EXTERN CARenderUpdate *CARenderUpdateBegin (void *buffer, size_t size,
    CFTimeInterval t, const CVTimeStamp *ts, uint32_t finished_seed,
    const CGRect *bounds);

/* Add 'ctx' to the update. */

CA_EXTERN void CARenderUpdateAddContext (CARenderUpdate *u,
    CARenderContext *ctx);

/* Add the specified rectangle to the dirty region of the update. */

CA_EXTERN void CARenderUpdateAddRect (CARenderUpdate *u, const CGRect *r);

/* Set the dirty region of the update to the specified rectangle. */

CA_EXTERN void CARenderUpdateSetRect (CARenderUpdate *u, const CGRect *r);

/* Add the specified region to the dirty region of the update. */

CA_EXTERN void CARenderUpdateAddRegion (CARenderUpdate *u, void *rgn);

/* Set the dirty region of the update to the specified region. */

CA_EXTERN void CARenderUpdateSetRegion (CARenderUpdate *u, void *rgn);

/* Returns the dirty region of the update, or null if nothing needs to
 * be redrawn. */

CA_EXTERN void *CARenderUpdateCopyRegion (CARenderUpdate *u);

/* Returns the bounds of the update object. */

CA_EXTERN CGRect CARenderUpdateGetBounds (CARenderUpdate *u);

/* Get the "seed" associated with the update. */

CA_EXTERN uint32_t CARenderUpdateGetSeed (CARenderUpdate *u);

/* Returns the time associated with the update object. */

CA_EXTERN CFTimeInterval CARenderUpdateGetTime (CARenderUpdate *u);

/* Returns the display timestamp associated with the update object. */

CA_EXTERN const CVTimeStamp *CARenderUpdateGetTimeStamp (CARenderUpdate *u);

/* Returns the time at which the next update needs to happen. If
 * infinite no update needs to be scheduled yet. If the current time, a
 * continuous animation is running and an update should be scheduled
 * for the next vbl. */

CA_EXTERN CFTimeInterval CARenderUpdateGetNextTime (CARenderUpdate *u);

/* Print all render trees contained by the update object to the
 * standard logging destination. */

CA_EXTERN void CARenderUpdatePrintTrees (CARenderUpdate *u);

/* Tear down the specified update object. */

CA_EXTERN void CARenderUpdateFinish (CARenderUpdate *u);

/** Image functions. **/

enum CARenderImageFormat
{
  kCARenderImageARGB8,
  kCARenderImageBGRA8,			/* i.e. little-endian ARGB */
  kCARenderImageXRGB8,
  kCARenderImageBGRX8,
  kCARenderImageRGB5,			/* RGB 555, no alpha */
  kCARenderImageBGR5,
  kCARenderImageCbYCrY8,		/* '2vuy' */
  kCARenderImageYCbYCr8,		/* 'yuvs' */
  kCARenderImageS8,			/* black with alpha */
  kCARenderImageA8,			/* white with alpha */
};

#if TARGET_RT_BIG_ENDIAN
# define kCARenderImageARGB8_Host kCARenderImageARGB8
# define kCARenderImageXRGB8_Host kCARenderImageXRGB8
# define kCARenderImageRGB5_Host  kCARenderImageRGB5
#else
# define kCARenderImageARGB8_Host kCARenderImageBGRA8
# define kCARenderImageXRGB8_Host kCARenderImageBGRX8
# define kCARenderImageRGB5_Host  kCARenderImageBGR5
#endif

/* Miscellaneous pixel format functions. */

CA_EXTERN size_t CARenderImageBitsPerPixel (unsigned int format);
CA_EXTERN size_t CARenderImageBitsPerComponent (unsigned int format);
CA_EXTERN bool CARenderImageHasAlpha (unsigned int format);
CA_EXTERN CGBitmapInfo CARenderImageCGBitmapInfo (unsigned int format);
CA_EXTERN bool CARenderImageIsNative (unsigned int format);
CA_EXTERN const char *CARenderImageFormatName (unsigned int format);

/* Returns the advised row alignment for an image of type 'format' with
 * 'width' pixels per row. */

CA_EXTERN size_t CARenderImageRowbytes (unsigned int format, uint32_t width);

/* Creates a new image object. */

CA_EXTERN CA_MALLOC CARenderImage *CARenderImageNew (unsigned int format,
    uint32_t width, uint32_t height, const void *data, size_t rowbytes,
    void (*release) (const void *data, void *releaseInfo), void *releaseInfo);

/* Similar, but the image may have multiple levels of detail. The first
 * level has dimensions 'width' by 'height' pixels. The second level has
 * dimensions 'max(1, width >> 1)' by 'max(1, height >> 1)' and so on.
 * The required data layout is 'height' rows of 'rowbytes[0]', followed by
 * 'max(1, height >> 1)' rows of 'rowbytes[1]', and so on. */

CA_EXTERN CA_MALLOC CARenderImage *CARenderImageNewMipmapped (unsigned int
    format, uint32_t width, uint32_t height, unsigned int levels,
    CGColorSpaceRef colorspace, const void *data, const size_t *rowbytes,
    void (*release) (const void *data, void *releaseInfo), void *releaseInfo);

/* Creates a new image object from the CoreGraphics image 'im'. Will
 * directly reference the bitmap of the passed in image when possible. */

CA_EXTERN CARenderImage *CARenderImageNewWithCGImage (CGImageRef im,
    CGColorSpaceRef dest_space, bool mipmapped);

/* Returns a CoreGraphics image referencing 'im'. Caller should release
 * the returned object. */

CA_EXTERN CGImageRef CARenderImageCopyCGImage (CARenderImage *bm);

/* Image accessors. */

CA_EXTERN CA_PURE uint32_t CARenderImageGetWidth (CARenderImage *b);
CA_EXTERN CA_PURE uint32_t CARenderImageGetHeight (CARenderImage *b);

/** Renderer features. **/

CA_EXTERN uint32_t CARenderGetGlobalFeatureFlags (void);
CA_EXTERN void CARenderSetGlobalFeatureFlags (uint32_t flags);

/** Notifications. **/

enum CARenderNotificationName
{
  /* Posted whenever the root layer has changed and needs to be redrawn. */

  kCARenderContextDidChange,

  /* Posted after creating a new render context. */

  kCARenderDidCreateContext,

  /* Posted before destroying a render context. */

  kCARenderWillDestroyContext,

  /* Posted when an "image-like" object is about to be deallocated. */

  kCARenderWillDeallocateImage,
};

typedef void (*CARenderNotificationCallback) (CARenderRef object, void *info,
    void *auxiliary_info);

CA_EXTERN void CARenderNotificationAddObserver (unsigned int name,
    CARenderRef object, CARenderNotificationCallback callback, void *info);

CA_EXTERN void CARenderNotificationRemoveObserver (unsigned int name,
    CARenderRef object, CARenderNotificationCallback callback, void *info);

CA_EXTERN void CARenderNotificationRemoveEveryObserver (void *info);

CA_EXTERN void CARenderNotificationPostNotification (unsigned int name,
    CARenderRef object, void *auxiliary_info, bool remove_observers);

/** Miscellaneous functions. **/

/* Attempt to reclaim memory. 'level' determines how strongly we try,
 * zero means anything that's idle, greater than zero means anything. */

CA_EXTERN void CARenderCollect (int level);

CA_EXTERN_C_END

#ifdef __OBJC__

/** ObjC render tree methods. **/

@interface NSObject (CARenderValue)

/* Returns a new render object representing the receiver, or a null
 * pointer if no such representation exists. */

- (CARenderRef)CA_copyRenderValue;

@end

#endif /* __OBJC__ */
#endif /* CARENDER_H */
