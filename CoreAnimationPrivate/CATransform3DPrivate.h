/* CoreAnimation - CATransform3DPrivate.h

   Copyright (c) 2006-2007 Apple Inc.
   All rights reserved. */

#ifndef CATRANSFORMPRIVATE_H
#define CATRANSFORMPRIVATE_H

#include <QuartzCore/CATransform3D.h>

CA_EXTERN_C_BEGIN

/* Multiply 't' by the translation matrix '(tx, ty, tz)' and return the
 * result: t' = t * translate(tx, ty, tz). */

CA_EXTERN CATransform3D CATransform3DTranslateRight (CATransform3D t,
    CGFloat tx, CGFloat ty, CGFloat tz)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Concatenate 'b' to 'a' and return the result: t' = transform(a) * b. */

CA_EXTERN CATransform3D CATransform3DConcatAffineTransform (CGAffineTransform
    a, CATransform3D b)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Multiply '(p.x, p.y, 0, 1)' by 't', homogenize the result and return
 * the x and y components. */

CA_EXTERN CGPoint CA_CGPointApplyTransform (CGPoint p, CATransform3D t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Assuming that transforming a point '(q.x, q.y, 0, 1)' by 't' gave
 * the point '(p.x, p.y, p.z, 1)', solve for p.z and return q.x and
 * q.y. Note that the input matrix 't_inv' is the inverse of 't'. */

CA_EXTERN CGPoint CA_CGPointUnapplyInverseTransform (CGPoint p,
    CATransform3D t_inv)
    __OSX_AVAILABLE_STARTING (__MAC_10_6, __IPHONE_2_0);

/* Multiply the point at each corner of 'r' by 't' and return the
 * smallest rectangle containing all four points. */

CA_EXTERN CGRect CA_CGRectApplyTransform (CGRect r, CATransform3D t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN CGRect CA_CGRectUnapplyInverseTransform (CGRect r,
    CATransform3D t_inv)
    __OSX_AVAILABLE_STARTING (__MAC_10_6, __IPHONE_2_0);

/* More efficient matrix operators that work in place. */

CA_EXTERN bool CATransform3DIsIdentity_ (const CATransform3D *t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);
CA_EXTERN bool CATransform3DEqualToTransform_ (const CATransform3D *a,
    const CATransform3D *b)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DMakeTranslation_ (CATransform3D *t, CGFloat tx,
    CGFloat ty, CGFloat tz)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DMakeScale_ (CATransform3D *t, CGFloat sx,
    CGFloat sy, CGFloat sz)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DMakeRotation_ (CATransform3D *t, double angle,
    CGFloat x, CGFloat y, CGFloat z)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DTranslate_ (CATransform3D *t, CGFloat tx,
    CGFloat ty, CGFloat tz)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DTranslateRight_ (CATransform3D *t, CGFloat tx,
    CGFloat ty, CGFloat tz)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DScale_ (CATransform3D *t, CGFloat sx, CGFloat sy,
    CGFloat sz)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DRotate_ (CATransform3D *t, double angle,
    CGFloat x, CGFloat y, CGFloat z)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DConcat_ (CATransform3D *c, const CATransform3D *a,
    const CATransform3D *b)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN bool CATransform3DIsAffine_ (const CATransform3D *t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DGetAffineTransform_ (CGAffineTransform *m,
    const CATransform3D *t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DMakeAffineTransform_ (CATransform3D *t,
    const CGAffineTransform *m)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CATransform3DConcatAffineTransform_ (CATransform3D *c,
    const CGAffineTransform *a, const CATransform3D *b)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN bool CATransform3DInvert_ (CATransform3D *inv,
    const CATransform3D *t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CA_CGPointApplyTransform_ (CGPoint *p, const CATransform3D *t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CA_CGPointUnapplyInverseTransform_ (CGPoint *p,
    const CATransform3D *t_inv)
    __OSX_AVAILABLE_STARTING (__MAC_10_6, __IPHONE_2_0);

CA_EXTERN void CA_CGRectApplyTransform_ (CGRect *r, const CATransform3D *t)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CA_CGRectUnapplyInverseTransform_ (CGRect *r,
    const CATransform3D *t_inv)
    __OSX_AVAILABLE_STARTING (__MAC_10_6, __IPHONE_2_0);

CA_EXTERN_C_END

#endif /* CATRANSFORMPRIVATE_H */
