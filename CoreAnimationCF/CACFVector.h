/* CoreAnimation - CACFVector.h

   Copyright (c) 2007 Apple Inc.
   All rights reserved. */

#ifndef CACFVECTOR_H
#define CACFVECTOR_H

#include <QuartzCore/CACFBase.h>
#include <QuartzCore/CATransform3D.h>

CA_EXTERN_C_BEGIN

CA_EXTERN CACFVectorRef CACFVectorCreate (size_t count, const CGFloat *values);

CA_INLINE CACFVectorRef CACFVectorCreatePoint (CGPoint p)
{
  return CACFVectorCreate (2, &p.x);
}

CA_INLINE CACFVectorRef CACFVectorCreateSize (CGSize s)
{
  return CACFVectorCreate (2, &s.width);
}

CA_EXTERN CACFVectorRef CACFVectorCreateRect (CGRect r);

CA_INLINE CACFVectorRef CACFVectorCreateAffineTransform (CGAffineTransform m)
{
  return CACFVectorCreate (6, &m.a);
}

CA_INLINE CACFVectorRef CACFVectorCreateTransform (CATransform3D m)
{
  return CACFVectorCreate (16, &m.m11);
}

CA_EXTERN size_t CACFVectorGetCount (CACFVectorRef v);

CA_EXTERN CGFloat CACFVectorGetValue (CACFVectorRef v, size_t idx);
CA_EXTERN void CACFVectorCopyValues (CACFVectorRef v, size_t count,
    CGFloat *values);

CA_INLINE CGPoint CACFVectorGetPoint (CACFVectorRef v)
{
  CGPoint p;
  CACFVectorCopyValues (v, 2, &p.x);
  return p;
}

CA_INLINE CGSize CACFVectorGetSize (CACFVectorRef v)
{
  CGSize s;
  CACFVectorCopyValues (v, 2, &s.width);
  return s;
}

CA_EXTERN CGRect CACFVectorGetRect (CACFVectorRef v);

CA_INLINE CGAffineTransform CACFVectorGetAffineTransform (CACFVectorRef v)
{
  CGAffineTransform m;
  CACFVectorCopyValues (v, 6, &m.a);
  return m;
}

CA_INLINE CATransform3D CACFVectorGetTransform (CACFVectorRef v)
{
  CATransform3D m;
  CACFVectorCopyValues (v, 16, &m.m11);
  return m;
}

CA_EXTERN CFTypeID CACFVectorGetTypeID (void);

CA_EXTERN_C_END

#endif /* CACFVECTOR_H */
