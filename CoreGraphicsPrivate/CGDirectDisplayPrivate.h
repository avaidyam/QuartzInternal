/* CoreGraphics - CGDirectDisplayPrivate.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGDIRECTDISPLAYPRIVATE_H_
#define CGDIRECTDISPLAYPRIVATE_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>
#include <SkyLight/CGSConnection.h>

CG_EXTERN CGContextRef CGDisplayGetDrawingContext(CGDirectDisplayID display);

CG_EXTERN CGContextRef CGWindowContextCreate(CGSConnection cid, CGWindowID wid, CFDictionaryRef theDict);

#endif	/* CGDIRECTDISPLAYPRIVATE_H_ */
