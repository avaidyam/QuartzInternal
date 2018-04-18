/* CoreAnimation - CARenderCG.h

   Copyright (c) 2006-2007 Apple Inc.
   All rights reserved. */

#ifndef CARENDERCG_H
#define CARENDERCG_H

#include "CARender.h"

typedef struct _CARenderCGContext CARenderCGContext;
typedef struct _CARenderCGCallbacks CARenderCGCallbacks;

CA_EXTERN_C_BEGIN

CA_EXTERN const CARenderCGCallbacks kCARenderCGLCallbacks;
CA_EXTERN const CARenderCGCallbacks kCARenderCGLSCallbacks;

/* Register a new context. */
CA_EXTERN CARenderCGContext *CARenderCGNew (uint32_t feature_flags);

CA_EXTERN uint32_t CARenderCGGetFeatureFlags (CARenderCGContext *ctx);
CA_EXTERN void CARenderCGSetFeatureFlags (CARenderCGContext *ctx,
    uint32_t flags);

CA_EXTERN void CARenderCGDestroy (CARenderCGContext *ctx);
CA_EXTERN void CARenderCGPurge (CARenderCGContext *ctx);
CA_EXTERN void CARenderCGCollect (CARenderCGContext *ctx, CARenderUpdate *u);

CA_EXTERN bool CARenderCGRender (CARenderCGContext *ctx, CARenderUpdate *u,
                                 CGContextRef contextRef);

CA_EXTERN void CARenderCGLSetScissorOffset (CARenderCGContext *ctx,
    int32_t x, int32_t y);

CA_EXTERN_C_END

#endif /* CARENDERCG_H */
