/* CoreGraphics - CGAccessSession.h
 * Copyright (c) 2000-2005 Apple Computer, Inc.
 * All rights reserved.
 */

#ifndef CGACCESS_SESSION_H_
#define CGACCESS_SESSION_H_

#include <CoreGraphics/CGBase.h>
#include <stdlib.h>

typedef struct CGAccessSession *CGAccessSessionRef;

CGAccessSessionRef CGAccessSessionCreate(CGDataProviderRef provider);

CGAccessSessionRef CGAccessSessionSkipForward(CGAccessSessionRef session, size_t value);

CGAccessSessionRef CGAccessSessionRewind(CGAccessSessionRef session);

CGAccessSessionRef CGAccessSessionSkipBytes(CGAccessSessionRef session, size_t bytes);

// TODO: Elucidate arg0-5.
void * CGAccessSessionGetChunks(void *arg0, void *arg1, void *arg2, void *arg3, void *arg4, void *arg5);

void * CGAccessSessionGetBytePointer(CGAccessSessionRef session);

size_t CGAccessSessionGetBytes(CGAccessSessionRef session, void *buffer, size_t bytes);

void CGAccessSessionRelease(CGAccessSessionRef session);

#endif	/* CGACCESS_SESSION_H_ */
