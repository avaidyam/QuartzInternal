/* CoreGraphics - CGDash.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGDASHPRIV_H_
#define CGDASHPRIV_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef struct CGDash *CGDashRef;

CG_EXTERN CGDashRef CGDashCreate(CGFloat phase, const CGFloat lengths[], size_t count);

CG_EXTERN Boolean CGDashEqualToDash(CGDashRef dash1, CGDashRef dash2);

CG_EXTERN const CGFloat* CGDashGetPattern(CGDashRef dash, CGFloat *phase, size_t *count);

CG_EXTERN CGDashRef CGDashRetain(CGDashRef dash);

CG_EXTERN void CGDashRelease(CGDashRef dash);

CF_EXTERN_C_END

#endif /* CGDASHPRIV_H_ */


