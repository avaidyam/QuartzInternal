/* CoreAnimation - CARenderServer.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CARENDERSERVER_H
#define CARENDERSERVER_H

#include <QuartzCore/CABase.h>

// CARenderServerGetServerPort, CARenderServerGetDebugOption, CARenderServerSetDebugOption, CARenderServerClearDebugOptions, CARenderServerGetDebugFlags, CARenderServerSetDebugFlags, CARenderServerGetDebugValue, CARenderServerSetDebugValue, CARenderServerSetMessageFile, CARenderServerSetDebugMessage, CARenderServerGetInfo, CARenderServerCopyUpdateHistograms, CARenderServerGetNeededAlignment, CARenderServerGetFrameCounter, CARenderServerGetFrameCounterByIndex, CARenderServerGetClientPort, CARenderServerIsRunning, CARenderServerRegister, CARenderServerShutdown

bool CARenderServerStart();
mach_port_t CARenderServerGetPort();

#define IOSURFACE_DEFINED // TODO: HAVE(IOSURFACE)
#ifdef IOSURFACE_DEFINED

void CARenderServerCaptureLayerWithTransform(mach_port_t, uint32_t clientId, uint64_t layerId, uint32_t slotId, int32_t ox, int32_t oy, const CATransform3D*);
void CARenderServerRenderLayerWithTransform(mach_port_t server_port, uint32_t client_id, uint64_t layer_id, IOSurfaceRef, int32_t ox, int32_t oy, const CATransform3D*);
void CARenderServerRenderDisplayLayerWithTransformAndTimeOffset(mach_port_t, CFStringRef display_name, uint32_t client_id, uint64_t layer_id, IOSurfaceRef, int32_t ox, int32_t oy, const CATransform3D*, CFTimeInterval);

#else

typedef struct CARenderServerBuffer* CARenderServerBufferRef;

CARenderServerBufferRef CARenderServerCreateBuffer(size_t, size_t);
void CARenderServerDestroyBuffer(CARenderServerBufferRef);
size_t CARenderServerGetBufferWidth(CARenderServerBufferRef);
size_t CARenderServerGetBufferHeight(CARenderServerBufferRef);
size_t CARenderServerGetBufferRowBytes(CARenderServerBufferRef);
uint8_t* CARenderServerGetBufferData(CARenderServerBufferRef);
size_t CARenderServerGetBufferDataSize(CARenderServerBufferRef);

bool CARenderServerRenderLayerWithTransform(mach_port_t, uint32_t client_id, uint64_t layer_id, CARenderServerBufferRef, int32_t ox, int32_t oy, const CATransform3D*);

#endif

#endif // CARENDERSERVER_H
