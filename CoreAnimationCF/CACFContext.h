/* CoreAnimation - CACFContext.h

   Copyright (c) 2007 Apple Inc.
   All rights reserved. */

#ifndef CACFCONTEXT_H
#define CACFCONTEXT_H

#include <QuartzCore/CACFBase.h>

CA_EXTERN_C_BEGIN

/* Context creation options. */

CA_EXTERN const CFStringRef kCACFContextPortNumber;
CA_EXTERN const CFStringRef kCACFContextPortName;

/* Create a new layer context. */

CA_EXTERN CACFContextRef CACFContextCreate (CFDictionaryRef options);

/* Invalidates 'ctx', equivalent to what would otherwise happen on
 * finalization. */

CA_EXTERN void CACFContextInvalidate (CACFContextRef ctx);

/* Commit all changes made to 'ctx' and the layer tree it references to
 * the render tree (i.e. to the screen.) This function must be called
 * after modifying any layer properties or adding any animations to
 * have their effect be seen. */

CA_EXTERN void CACFContextFlush (CACFContextRef ctx);

/* Returns the default beginTime of animations added as part of the
 * previous transaction (i.e. the previous call to CACFContextFlush.) */

CA_EXTERN CFTimeInterval CACFContextGetLastCommitTime (CACFContextRef ctx);

/* The root layer associated with 'ctx' to 'layer'. The context will
 * retain the layer. */

CA_EXTERN void CACFContextSetLayer (CACFContextRef ctx, CACFLayerRef layer);
CA_EXTERN CACFLayerRef CACFContextGetLayer (CACFContextRef ctx);

/* The color space used by the context. */

CA_EXTERN void CACFContextSetColorSpace (CACFContextRef ctx,
    CGColorSpaceRef colorspace);
CA_EXTERN CGColorSpaceRef CACFContextGetColorSpace (CACFContextRef ctx);

/* Returns the render tree context associated with 'ctx'. */

CA_EXTERN void *CACFContextGetRenderContext (CACFContextRef ctx);

/* Allows for an arbitrary pointer to be associated with each context. */

CA_EXTERN void *CACFContextGetUserData (CACFContextRef ctx);
CA_EXTERN void CACFContextSetUserData (CACFContextRef ctx, void *data);

/* Returns the CF type identifier of CACF contexts. */

CA_EXTERN CFTypeID CACFContextGetTypeID (void);

CA_EXTERN_C_END

/** Context dictionary keys. **/


#endif /* CACFCONTEXT_H */
