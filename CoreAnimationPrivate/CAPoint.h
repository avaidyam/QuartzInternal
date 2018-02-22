/* CoreAnimation - CAPoint.h

   Copyright (c) 2006-2007 Apple Inc.
   All rights reserved. */

#ifndef CAPOINT_H
#define CAPOINT_H

#include <QuartzCore/CATransform3D.h>

/* Three-dimensional homogeneous points. */

typedef struct CAPoint {
  CGFloat x, y, z, w;
} CAPoint;

typedef struct CAPoint3D {
    CGFloat x, y, z;
} CAPoint3D;

CA_EXTERN_C_BEGIN

/* The "zero" point -- equivalent to CAPointMake(0, 0, 0, 1). */ 

CA_EXTERN const CAPoint CAPointZero
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Returns a point '(x, y, z, w)'. */

CA_INLINE CAPoint CAPointMake (CGFloat x, CGFloat y, CGFloat z, CGFloat w);

/* Returns a point '(p.x, p.y, 0, 1)'. */

CA_INLINE CAPoint CAPointMakeWithCGPoint (CGPoint p);

/* Returns the CG point corresponding to 'p'. Optionally returns the z
 * component in '*ret_z'. */

CA_EXTERN CGPoint CAPointToCGPoint (CAPoint p, CGFloat *ret_z);

/* Returns true if point 'a' is equal to point 'b'. */

CA_EXTERN bool CAPointEqualToPoint (CAPoint a, CAPoint b)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Transform point 'p' by 't' and return the result: p' = p * t. */

CA_EXTERN CAPoint CAPointApplyTransform (CAPoint p, CATransform3D t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* In place versions of above. */

CA_EXTERN void CAPointApplyTransform_ (CAPoint *p, const CATransform3D *t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CAPointArrayApplyTransform (CAPoint *p, ptrdiff_t stride,
    size_t count, const CATransform3D *t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/** Inline function definitions. **/

CA_INLINE CAPoint
CAPointMake (CGFloat x, CGFloat y, CGFloat z, CGFloat w)
{
  CAPoint p;

  p.x = x;
  p.y = y;
  p.z = z;
  p.w = w;

  return p;
}

CA_INLINE CAPoint
CAPointMakeWithCGPoint (CGPoint a)
{
  CAPoint p;

  p.x = a.x;
  p.y = a.y;
  p.z = (CGFloat) 0.0;
  p.w = (CGFloat) 1.0;

  return p;
}

CA_EXTERN_C_END

#endif /* CAPOINT_H */
