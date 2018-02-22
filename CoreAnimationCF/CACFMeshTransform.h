/* CoreAnimation - CACFMeshTransform.h

   Copyright (c) 2007 Apple Inc.
   All rights reserved. */

#ifndef CACFMESHTRANSFORM_H
#define CACFMESHTRANSFORM_H

#include <QuartzCore/CACFBase.h>

CA_EXTERN_C_BEGIN

/** Mesh transform creation. **/

// TODO: Elucidate arg0-5.
CA_EXTERN CACFMeshTransformRef CACFMeshTransformCreate (void *arg0, void *arg1,
                                                        void *arg2, void *arg3,
                                                        void *arg4, void *arg5);

/** Mesh transform type. **/

CA_EXTERN CFTypeID CACFMeshTransformGetTypeID (void);

CA_EXTERN_C_END

#endif /* CACFMESHTRANSFORM_H */
