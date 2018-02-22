/* CoreGraphics - CGSoftMask.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGSOFTMASK_H_
#define CGSOFTMASK_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef struct CGSoftMask *CGSoftMaskRef;

CG_EXTERN CGSoftMaskRef CGSoftMaskRetain(CGSoftMaskRef softMask);

CG_EXTERN void CGSoftMaskRelease(CGSoftMaskRef softMask);

CG_EXTERN CFTypeID CGSoftMaskGetTypeID(void);

CF_EXTERN_C_END

#endif /* CGSOFTMASK_H_ */
