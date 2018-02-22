/* CoreGraphics - CGDisplayList.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGDISPLAYLIST_H_
#define CGDISPLAYLIST_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef struct CGDisplayListData *CGDisplayListDataRef;
typedef struct CGDisplayList *CGDisplayListRef;

CG_EXTERN CGDisplayListRef CGDisplayListCreateWithRect(CGRect rect);

CG_EXTERN CGContextRef CGDisplayListContextCreate(void *arg0);

CG_EXTERN CGContextDelegateRef CGDisplayListContextDelegateCreate(void *arg0);

CG_EXTERN CFTypeID CGDisplayListGetTypeID(void);

CF_EXTERN_C_END

#endif /* CGDISPLAYLIST_H_ */


