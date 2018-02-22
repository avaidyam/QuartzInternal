/* CoreAnimation - CACFCAMLParser.h

   Copyright (c) 2007 Apple Inc.
   All rights reserved. */

#ifndef CACFCAMLPARSER_H
#define CACFCAMLPARSER_H

#include <QuartzCore/CACFBase.h>

#if QC_MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_4
# define CFErrorRef CFTypeRef
#endif

CA_EXTERN_C_BEGIN

CA_EXTERN CACFCAMLParserRef CACFCAMLParserCreate (void);

CA_EXTERN void CACFCAMLParserSetBaseURL (CACFCAMLParserRef p, CFURLRef url);
CA_EXTERN CFURLRef CACFCAMLParserGetBaseURL (CACFCAMLParserRef p);

CA_EXTERN bool CACFCAMLParserParseContentsOfURL (CACFCAMLParserRef p,
    CFURLRef url);

CA_EXTERN bool CACFCAMLParserParseData (CACFCAMLParserRef p, CFDataRef data);

CA_EXTERN bool CACFCAMLParserParseString (CACFCAMLParserRef p, CFStringRef s);

CA_EXTERN bool CACFCAMLParserParseBytes (CACFCAMLParserRef p,
    const char *data, size_t data_length);

CA_EXTERN CFErrorRef CACFCAMLParserGetError (CACFCAMLParserRef p);

CA_EXTERN CFTypeRef CACFCAMLParserGetResult (CACFCAMLParserRef p);

CA_EXTERN CFTypeRef CACFCAMLParserGetObject (CACFCAMLParserRef p,
    CFStringRef id_string);

CA_EXTERN CFTypeID CACFCAMLParserGetTypeID (void);

CA_EXTERN_C_END

#if QC_MAC_OS_X_VERSION_MAX_ALLOWED <= MAC_OS_X_VERSION_10_4
# undef CFErrorRef
#endif

#endif /* CACFCAMLPARSER_H */
