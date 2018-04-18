/* CoreAnimation - CALayoutManagerPrivate.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CALAYOUTMANAGERPRIVATE_H
#define CALAYOUTMANAGERPRIVATE_H

#include <QuartzCore/CABase.h>
#include <QuartzCore/CAConstraintLayoutManager.h>

CA_EXTERN_C_BEGIN

@interface CABoxLayoutManager: NSObject <NSSecureCoding, CALayoutManager>

+ (instancetype)layoutManager;

@end

@interface CAScrollLayoutManager : NSObject <NSSecureCoding, CALayoutManager>

+ (instancetype)layoutManager;

@end

@interface CATableLayoutManager : NSObject <NSSecureCoding, CALayoutManager>

+ (instancetype)layoutManager;

@end

@interface CAWrappedLayoutManager : NSObject <NSSecureCoding, CALayoutManager>

+ (instancetype)layoutManager;

@end

@interface CALayer (TableAndWrappedLayout)

@property CGSize margin;
@property CGSize spacing;

@property uint32_t tableColumn;
@property uint32_t tableColumns;
@property uint32_t tableRow;
@property uint32_t tableRows;

@property (copy) NSString *wrappedDirection;
@property (copy) NSString *wrappedOrigin;

@end

CA_EXTERN_C_END

#endif // CALAYOUTMANAGERPRIVATE_H
