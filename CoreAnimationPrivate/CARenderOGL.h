/* CoreAnimation - CARenderOGL.h

   Copyright (c) 2006-2007 Apple Inc.
   All rights reserved. */

#ifndef CARENDEROGL_H
#define CARENDEROGL_H

#include <QuartzCore/CARender.h>
#include <CoreGraphics/CGSBounds.h>

typedef struct _CARenderOGLContext CARenderOGLContext;
typedef struct _CARenderOGLCallbacks CARenderOGLCallbacks;

CA_EXTERN_C_BEGIN

CA_EXTERN const CARenderOGLCallbacks kCARenderDX9Callbacks;
CA_EXTERN const CARenderOGLCallbacks kCARenderSoftwareCallbacks;

/* Register a new context. When flipped_coordinates is true, callers are
 * expected to have flipped rendering matrix via glOrtho () or similar. */

CA_EXTERN CARenderOGLContext *CARenderOGLNew (const CARenderOGLCallbacks
    *vtable, void *gl_context, uint32_t feature_flags);

CA_EXTERN CARenderOGLContext *CARenderOGLNew_ (const
    CARenderOGLCallbacks *vtable, void *gl_context, void *gl_pixel_format,
    uint32_t feature_flags);

CA_EXTERN void *CARenderOGLGetGLContext (CARenderOGLContext *ctx);
CA_EXTERN void CARenderOGLSetGLContext (CARenderOGLContext *ctx,
    void *gl_context);

CA_EXTERN uint32_t CARenderOGLGetFeatureFlags (CARenderOGLContext *ctx);
CA_EXTERN void CARenderOGLSetFeatureFlags (CARenderOGLContext *ctx,
    uint32_t flags);

CA_EXTERN void CARenderOGLDestroy (CARenderOGLContext *ctx);
CA_EXTERN void CARenderOGLPurge (CARenderOGLContext *ctx);
CA_EXTERN void CARenderOGLCollect (CARenderOGLContext *ctx, CARenderUpdate *u);

CA_EXTERN void CARenderOGLPrepareUpdateShape (CARenderOGLContext *c,
    CARenderUpdate *u);

CA_EXTERN bool CARenderOGLRender (CARenderOGLContext *ctx, CARenderUpdate *u);

CA_EXTERN void CARenderOGLSetColorSpace (CARenderOGLContext *ctx,
    CGColorSpaceRef colorspace);

/** Functions for software renderers. **/

CA_EXTERN bool CARenderSoftwareSetDestination (CARenderOGLContext *c,
    void *color_data, ptrdiff_t color_bpr, size_t color_bpp, void *alpha_data,
    ptrdiff_t alpha_bpr, int32_t x, int32_t y, int32_t w, int32_t h);

/** Internal functions. **/

extern void CARenderOGLInitializeFilters (void);
extern void CARenderOGLInitializeTransitions (void);

CA_EXTERN_C_END

#endif /* CARENDEROGL_H */
