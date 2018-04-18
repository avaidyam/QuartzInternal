/* CoreAnimation - CATransactionPrivate.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CATRANSACTIONPRIVATE_H
#define CATRANSACTIONPRIVATE_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

typedef NS_ENUM(uint32_t, CATransactionPhase) {
    kCATransactionPhasePreLayout,
    kCATransactionPhasePreCommit,
    kCATransactionPhasePostCommit,
    kCATransactionPhaseNull = ~0u
};

typedef NS_OPTIONS(uint32_t, CATransactionState) {
    kCATransactionImplicit          = 1U << 0,
    kCATransactionExplicit          = 1U << 1,
    kCATransactionIsActive          = (kCATransactionImplicit | kCATransactionExplicit),
};

@interface CATransaction ()

@property (class) BOOL lowLatency;
@property (class) double inputTime;
@property (class) BOOL disableRunLoopObserverCommits;
@property (class) double earliestAutomaticCommitTime;
@property (class) double commitTime;
@property (class) BOOL animatesFromModelValues;

+ (uint32_t)generateSeed;
+ (CATransactionState)currentState;

+ (void)synchronize;
+ (void)activateBackground:(BOOL)background;
+ (void)activate;
+ (void)assertInactive;

+ (CATransactionPhase)currentPhase;
+ (void)addCommitHandler:(void(^)(void))handler forPhase:(CATransactionPhase)phase;
+ (void)setCommitHandler:(void(^)(void))handler;

+ (id/*block*/)animator;
+ (void)popAnimator;
+ (void)pushAnimator:(id/*block*/)animator;

@end

@interface CATransactionCompletionItem : NSObject

+ (instancetype)completionItem;

- (void)invalidate;

@end

/** Transaction properties. **/

CA_EXTERN NSString * const kCATransactionAnimationDelegate;
CA_EXTERN NSString * const kCATransactionCommitTime;
CA_EXTERN NSString * const kCATransactionAnimatesFromModelValues;
CA_EXTERN NSString * const kCATransactionInputTime;

CA_EXTERN_C_END

#endif // CATRANSACTIONPRIVATE_H
