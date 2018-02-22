/* CoreGraphics - CGStyle.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGSTYLE_H_
#define CGSTYLE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef struct CGStyle *CGStyleRef;

CG_EXTERN CGStyleRef CGStyleRetain(CGStyleRef style);

CG_EXTERN void CGStyleRelease(CGStyleRef style);

CG_EXTERN CFTypeID CGStyleGetTypeID(void);

CF_EXTERN_C_END

#endif /* CGSTYLE_H_ */
