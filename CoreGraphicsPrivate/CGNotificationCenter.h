/* CoreGraphics - CGNotificationCenter.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGNOTIFICATIONCENTER_H_
#define CGNOTIFICATIONCENTER_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN

typedef struct CGNotificationCenter *CGNotificationCenterRef;

CG_EXTERN CGNotificationCenterRef CGNotificationCenterCreate();

CG_EXTERN void CGNotificationCenterPostNotification(CGNotificationCenterRef notifCenter, 
													CFStringRef ref, 
													CFTypeRef cftype,
													bool isSingleton);

bool CGRegistryEntryRelease();

CG_EXTERN CFTypeID CGNotificationCenterGetTypeID(void);

CF_EXTERN_C_END

#endif /* CGNOTIFICATIONCENTER_H_ */
