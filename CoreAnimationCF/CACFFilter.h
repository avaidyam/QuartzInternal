/* CoreAnimation - CACFFilter.h

   Copyright (c) 2007 Apple Inc.
   All rights reserved. */

#ifndef CACFFILTER_H
#define CACFFILTER_H

#include <QuartzCore/CACFBase.h>

CA_EXTERN_C_BEGIN

/** Filter creation. **/

CA_EXTERN CACFFilterRef CACFFilterCreate (CFStringRef type);

CA_EXTERN CFStringRef CACFFilterGetType (CACFFilterRef filter);

/** Filter properties. **/

CA_EXTERN void *CACFFilterGetUserData (CACFFilterRef filter);
CA_EXTERN void CACFFilterSetUserData (CACFFilterRef filter, void *data);

CA_EXTERN CFStringRef CACFFilterGetName (CACFFilterRef filter);
CA_EXTERN void CACFFilterSetName (CACFFilterRef filter, CFStringRef name);

CA_EXTERN bool CACFFilterIsEnabled (CACFFilterRef filter);
CA_EXTERN void CACFFilterSetEnabled (CACFFilterRef filter, bool state);

CA_EXTERN CFTypeRef CACFilterGetValue (CACFFilterRef filter, CFStringRef key);
CA_EXTERN void CACFFilterSetValue (CACFFilterRef filter, CFStringRef key,
    CFTypeRef value);

/** Filter type. **/

CA_EXTERN CFTypeID CACFFilterGetTypeID (void);

CA_EXTERN_C_END

#endif /* CACFFILTER_H */
