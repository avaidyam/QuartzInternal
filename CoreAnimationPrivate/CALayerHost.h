/* CoreAnimation - CALayerHost.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CALAYERHOST_H
#define CALAYERHOST_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@interface CALayerHost: CALayer

@property uint32_t contextId;

@end

CA_EXTERN_C_END

#endif // CALAYERHOST_H
