/* CoreGraphics - CGNotificationCenter.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGNOTIFICATIONCENTER_H_
#define CGNOTIFICATIONCENTER_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

CF_EXTERN_C_BEGIN
CF_IMPLICIT_BRIDGING_ENABLED
CF_ASSUME_NONNULL_BEGIN

///
typedef struct CGNotificationCenter *CGNotificationCenterRef;

///
typedef void (*CGNotificationCenterCallback)(CGNotificationCenterRef center,
                                             void *arg1,
                                             CFStringRef notification,
                                             void const *arg3,
                                             CFDictionaryRef arguments);

///
CG_EXTERN CFTypeID CGNotificationCenterGetTypeID(void);

///
CG_EXTERN CGNotificationCenterRef CGNotificationCenterCreate();

///
CG_EXTERN void CGNotificationCenterPostNotification(CGNotificationCenterRef center,
													_Nullable CFStringRef notification,
													_Nullable CFTypeRef sender);

///
CG_EXTERN void CGNotificationCenterAddCallback(CGNotificationCenterRef center,
                                               CGNotificationCenterCallback callback,
                                               _Nullable CFTypeRef userInfo,
                                               _Nullable CFStringRef notification,
                                               _Nullable CFTypeRef sender);

CG_EXTERN void CGNotificationCenterRemoveCallback(CGNotificationCenterRef center,
                                                  CGNotificationCenterCallback callback,
                                                  _Nullable CFStringRef notification,
                                                  _Nullable CFTypeRef sender);

///
CG_EXTERN CGNotificationCenterRef CGImageNotificationCenter();

///
CG_EXTERN CGNotificationCenterRef CGPatternNotificationCenter();

CF_ASSUME_NONNULL_END
CF_IMPLICIT_BRIDGING_DISABLED
CF_EXTERN_C_END

#endif /* CGNOTIFICATIONCENTER_H_ */
