/* CoreAnimation - CAPresentationModifier.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAPRESENTATIONMODIFIER_H
#define CAPRESENTATIONMODIFIER_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

@class CAPresentationModifierGroup;

@interface CAPresentationModifier : NSObject

@property (getter=isEnabled) BOOL enabled;
@property (strong) id value;
@property (readonly) CAPresentationModifierGroup *group;
@property (readonly, copy) NSString *keyPath;
@property (readonly) BOOL additive;

- (instancetype)initWithKeyPath:(NSString *)keyPath
                   initialValue:(id)value
                       additive:(BOOL)additive
                          group:(CAPresentationModifierGroup *)group;

- (instancetype)initWithKeyPath:(NSString *)keyPath
                   initialValue:(id)value
                       additive:(BOOL)additive;

- (void)write;

@end

@interface CAPresentationModifierGroup : NSObject

+ (instancetype)groupWithCapacity:(uint64_t)capacity;

@property (readonly) uint64_t count;
@property (readonly) uint64_t capacity;

- (instancetype)initWithCapacity:(uint64_t)capacity;

- (void)flush;
- (void *)shmem;
- (void)markWritten:(uint64_t)flag;
- (void)resetBitMask;
- (uint64_t)nextSlot;

@end

@interface CALayer (PresentationModifier)

@property (copy) NSArray *presentationModifiers;

- (void)addPresentationModifier:(CAPresentationModifier *)presentationModifier;
- (void)removePresentationModifier:(CAPresentationModifier *)presentationModifier;

@end

CA_EXTERN_C_END

#endif // CAPRESENTATIONMODIFIER_H
