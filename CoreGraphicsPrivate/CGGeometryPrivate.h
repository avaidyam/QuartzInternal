/* CoreGraphics - CGAccessSession.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGGEOMETRYPRIVATE_H_
#define CGGEOMETRYPRIVATE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

/* Return true if `rect' can be represented as an "integral" rect -- that
 * is, if its origin and size are representable exactly as integers. */

CG_EXTERN bool CGRectIsIntegral(CGRect rect);

#endif	/* CGGEOMETRYPRIVATE_H_ */
