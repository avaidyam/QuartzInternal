/* CoreGraphics - CGRenderingState.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGRENDERINGSTATE_H_
#define CGRENDERINGSTATE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

typedef struct CGRenderingState *CGRenderingStateRef;

CGRenderingStateRef CGRenderingStateCreate();

CGRenderingStateRef CGRenderingStateCreateCopy(CGRenderingStateRef rendering);

void CGRenderingStateRelease(CGRenderingStateRef rendering);

void CGRenderingStateReset(CGRenderingStateRef rendering);

void CGRenderingStateSetRenderingResolution(CGRenderingStateRef rendering,
                                            CGFloat hRes, CGFloat vRes);

CF_EXTERN_C_END

#endif /* CGRENDERINGSTATE_H_ */


