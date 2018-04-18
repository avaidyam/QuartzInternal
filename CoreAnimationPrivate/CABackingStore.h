/* CoreAnimation - CABackingStore.h

   Copyright (c) 2006-2007 Apple Inc.
   All rights reserved. */

#ifndef CABACKINGSTORE_H
#define CABACKINGSTORE_H

#include "CARender.h"

CA_EXTERN_C_BEGIN
#include "CGSRegion.h"
CA_EXTERN_C_END

typedef struct _CABackingStore *CABackingStoreRef;

typedef NS_OPTIONS(uint32_t, CABackingStoreFlags) {
  kCABackingStoreOpaque     = 1U << 0,
  kCABackingStoreCleared    = 1U << 1,
  kCABackingStoreMipmap     = 1U << 2,
  kCABackingStoreAutoMipmap = 1U << 3,
};

CA_EXTERN_C_BEGIN

CA_EXTERN CABackingStoreRef CABackingStoreCreate (void);

/* Sets the colorspace of the backing store. Returns true if it
 * actually changed. */

CA_EXTERN bool CABackingStoreSetColorSpace (CABackingStoreRef b,
    CGColorSpaceRef colorspace);

/* Invalidates 'r' in the back buffer of 'b'. Passing a null rect
 * dirties the whole backing store. */

CA_EXTERN void CABackingStoreInvalidate (CABackingStoreRef b, const CGRect *r);

/* If 'state' is true attempts to mark the front buffer of 'b' volatile,
 * i.e. available for reclamation by the VM system when needed, returns
 * true if successful. If 'state' is false attemps to mark 'b' nonvolatile,
 * if the contents of the buffer are still valid returns true, else
 * returns false. */

CA_EXTERN bool CABackingStoreSetVolatile (CABackingStoreRef b, bool state);
CA_EXTERN bool CABackingStoreIsVolatile (CABackingStoreRef b);

CA_EXTERN void CABackingStoreCollect (CFTimeInterval now);

CA_EXTERN void CABackingStoreCollectBlocking (void);

/* Calls 'callback' to update any dirtied regions into the back buffer,
 * then swaps back and front buffers. */

CA_EXTERN void CABackingStoreUpdate (CABackingStoreRef b, size_t width,
    size_t height, CABackingStoreFlags flags, void (*callback) (CGContextRef ctx,
    void *info), void *callback_info);

/* Returns the dirty region for the backing store from the last time
 * that CABackingStoreCreateContext () was called. Returns a null region
 * if the entire buffer is dirty. */

CA_EXTERN CGSRegionObj CABackingStoreGetUpdateRegion (CABackingStoreRef b);

/* Returns image for front buffer. */

CA_EXTERN CARenderImage *CABackingStoreGetRenderImage (CABackingStoreRef b);

CA_EXTERN CGImageRef CABackingStoreGetCGImage (CABackingStoreRef b);

CA_EXTERN CFTypeID CABackingStoreGetTypeID (void);

CA_EXTERN_C_END

#endif /* CABACKINGSTORE_H */
