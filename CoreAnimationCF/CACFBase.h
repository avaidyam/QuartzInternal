/* CoreAnimation - CACFBase.h

   Copyright (c) 2007 Apple Inc.
   All rights reserved. */

#ifndef CACFBASE_H
#define CACFBASE_H

#include <QuartzCore/CABase.h>

typedef struct _CACFAnimation *CACFAnimationRef;
typedef struct _CACFCAMLParser *CACFCAMLParserRef;
typedef struct _CACFContext *CACFContextRef;
typedef struct _CACFFilter *CACFFilterRef;
typedef struct _CACFLayer *CACFLayerRef;
typedef struct _CACFMeshTransform *CACFMeshTransformRef;
typedef struct _CACFTimingFunction *CACFTimingFunctionRef;
typedef struct _CACFValueFunction *CACFValueFunctionRef;
typedef struct _CACFVector *CACFVectorRef;
typedef struct _CACFView *CACFViewRef;

/* A recursive mutex that clients can use to synchronize API use. The
   mutex state is never changed by CACF itself.

   CACF is fundamentally a single-threaded API: each CACFContextRef
   (including all the objects reachable from the context - layers,
   filters, animations, etc) may only be accessed by a single thread at
   once. For example one thread may not use a layer attached to a
   context while another thread uses a different layer attached to the
   same context. In the case that a layer is not attached to a context
   the same rules apply for the whole layer tree that it is part of.

   Clients that require access to a layer tree from a background thread
   should first consider moving this work to the main thread. If that
   is impossible these functions may be useful to enforce the API
   restrictions. For that to work correctly, all callers of the CACF
   APIs in the process must agree to call CACFLock() before using the
   APIs and CACFUnlock() afterwards. */

CA_EXTERN_C_BEGIN

CA_EXTERN void CACFLock (void);
CA_EXTERN void CACFUnlock (void);

CA_EXTERN_C_END

#endif /* CACFBASE_H */
