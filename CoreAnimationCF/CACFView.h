/* CoreAnimation - CACFView.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CACFVIEW_H
#define CACFVIEW_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

/* TODO: CACFViewRef might just be a CAViewRef... */

/* Creates a new view object. */
CA_EXTERN CACFViewRef CACFViewCreate();

/* Sets the root layer being displayed by the view. */
CA_EXTERN void CACFViewSetLayer(CACFViewRef view, CACFLayerRef layer);

/* Gets the root layer being displayed by the view. */
CA_EXTERN CACFLayerRef CACFViewGetLayer(CACFViewRef view);

/* Gets the context underlying the view object. */
CA_EXTERN CACFContextRef CACFViewGetContext(CACFViewRef view);

CA_EXTERN_C_END

#endif // CACFVIEW_H
