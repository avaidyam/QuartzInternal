/* CoreAnimation - CACFAnimation.h

   Copyright (c) 2007 Apple Inc.
   All rights reserved. */

#ifndef CACFANIMATION_H
#define CACFANIMATION_H

#include <QuartzCore/CACFBase.h>

CA_EXTERN_C_BEGIN

/** Animation classes. **/

CA_EXTERN const CFStringRef kCACFBasicAnimation;
CA_EXTERN const CFStringRef kCACFSpringAnimation;
CA_EXTERN const CFStringRef kCACFKeyframeAnimation;
CA_EXTERN const CFStringRef kCACFTransition;
CA_EXTERN const CFStringRef kCACFAnimationGroup;

/** Animation creation. **/

CA_EXTERN CACFAnimationRef CACFAnimationCreate (CFStringRef class_name);

CA_EXTERN CFStringRef CACFAnimationGetClass (CACFAnimationRef anim);

/** Animation properties. **/

CA_EXTERN void *CACFAnimationGetUserData (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetUserData (CACFAnimationRef anim, void *data);

CA_EXTERN bool CACFAnimationIsEnabled (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetEnabled (CACFAnimationRef anim, bool flag);

CA_EXTERN CFTimeInterval CACFAnimationGetBeginTime (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetBeginTime (CACFAnimationRef anim,
    CFTimeInterval t);

CA_EXTERN CFTimeInterval CACFAnimationGetDuration (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetDuration (CACFAnimationRef anim,
    CFTimeInterval dur);

CA_EXTERN float CACFAnimationGetSpeed (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetSpeed (CACFAnimationRef anim, float s);

CA_EXTERN CFTimeInterval CACFAnimationGetTimeOffset (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetTimeOffset (CACFAnimationRef anim,
    CFTimeInterval t);

CA_EXTERN float CACFAnimationGetRepeatCount (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetRepeatCount (CACFAnimationRef anim,
    float count);

CA_EXTERN CFTimeInterval CACFAnimationGetRepeatDuration
    (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetRepeatDuration (CACFAnimationRef anim,
    CFTimeInterval dur);

CA_EXTERN bool CACFAnimationGetAutoreverses (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetAutoreverses (CACFAnimationRef anim,
    bool state);

CA_EXTERN CFStringRef CACFAnimationGetFillMode (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetFillMode (CACFAnimationRef anim,
    CFStringRef str);

CA_EXTERN CACFTimingFunctionRef CACFAnimationGetTimingFunction
    (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetTimingFunction (CACFAnimationRef anim,
    CACFTimingFunctionRef fun);

CA_EXTERN bool CACFAnimationIsRemovedOnCompletion (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetRemovedOnCompletion (CACFAnimationRef anim,
    bool state);

CA_EXTERN CFTimeInterval CACFAnimationGetFrameInterval (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetFrameInterval (CACFAnimationRef anim,
    CFTimeInterval t);

/** Property-animation properties. **/

CA_EXTERN CFStringRef CACFAnimationGetKeyPath (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetKeyPath (CACFAnimationRef anim,
    CFStringRef str);

CA_EXTERN bool CACFAnimationIsAdditive (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetAdditive (CACFAnimationRef anim, bool state);

CA_EXTERN bool CACFAnimationIsCumulative (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetCumulative (CACFAnimationRef anim, bool state);

CA_EXTERN CACFValueFunctionRef CACFAnimationGetValueFunction (CACFAnimationRef
    anim);
CA_EXTERN void CACFAnimationSetValueFunction (CACFAnimationRef anim,
    CACFValueFunctionRef fun);

/** Basic-animation properties. **/

CA_EXTERN CFTypeRef CACFAnimationGetFromValue (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetFromValue (CACFAnimationRef anim,
    CFTypeRef obj);

CA_EXTERN CFTypeRef CACFAnimationGetToValue (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetToValue (CACFAnimationRef anim, CFTypeRef obj);

CA_EXTERN CFTypeRef CACFAnimationGetByValue (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetByValue (CACFAnimationRef anim, CFTypeRef obj);

CA_EXTERN bool CACFAnimationGetRoundsToInteger (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetRoundsToInteger (CACFAnimationRef anim,
    bool state);

CA_EXTERN CGFloat CACFAnimationGetStartAngle (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetStartAngle (CACFAnimationRef anim, CGFloat ang);

CA_EXTERN CGFloat CACFAnimationGetEndAngle (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetEndAngle (CACFAnimationRef anim, CGFloat ang);

/** Spring-animation properties. **/

CA_EXTERN CGFloat CACFAnimationGetMass (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetMass (CACFAnimationRef anim,
                                     CGFloat mass);

CA_EXTERN CGFloat CACFAnimationGetStiffness (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetStiffness (CACFAnimationRef anim, CGFloat stiffness);

CA_EXTERN CGFloat CACFAnimationGetDamping (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetDamping (CACFAnimationRef anim, CGFloat damping);

/** Keyframe-animation properties. **/

CA_EXTERN CFArrayRef CACFAnimationGetValues (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetValues (CACFAnimationRef anim,
    CFArrayRef array);

CA_EXTERN CGPathRef CACFAnimationGetPath (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetPath (CACFAnimationRef anim, CGPathRef path);

CA_EXTERN CFArrayRef CACFAnimationGetKeyTimes (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetKeyTimes (CACFAnimationRef anim,
    CFArrayRef array);

CA_EXTERN CFArrayRef CACFAnimationGetTimingFunctions (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetTimingFunctions (CACFAnimationRef anim,
    CFArrayRef array);

CA_EXTERN CFStringRef CACFAnimationGetCalculationMode (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetCalculationMode (CACFAnimationRef anim,
    CFStringRef str);

CA_EXTERN CFArrayRef CACFAnimationGetTensionValues (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetTensionValues (CACFAnimationRef anim,
                                              CFArrayRef array);

CA_EXTERN CFArrayRef CACFAnimationGetContinuityValues (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetContinuityValues (CACFAnimationRef anim,
                                                CFArrayRef array);

CA_EXTERN CFArrayRef CACFAnimationGetBiasValues (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetBiasValues (CACFAnimationRef anim,
                                           CFArrayRef array);

CA_EXTERN CFStringRef CACFAnimationGetRotationMode (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetRotationMode (CACFAnimationRef anim,
    CFStringRef str);

/** Transition properties. **/

CA_EXTERN CFStringRef CACFAnimationGetType (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetType (CACFAnimationRef anim, CFStringRef str);

CA_EXTERN CFStringRef CACFAnimationGetSubtype (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetSubtype (CACFAnimationRef anim,
    CFStringRef str);

CA_EXTERN float CACFAnimationGetStartProgress (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetStartProgress (CACFAnimationRef anim, float x);

CA_EXTERN float CACFAnimationGetEndProgress (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetEndProgress (CACFAnimationRef anim, float x);

CA_EXTERN CACFFilterRef CACFAnimationGetFilter (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetFilter (CACFAnimationRef anim,
    CACFFilterRef filter);

/** Animation-group properties. **/

CA_EXTERN CFArrayRef CACFAnimationGetAnimations (CACFAnimationRef anim);
CA_EXTERN void CACFAnimationSetAnimations (CACFAnimationRef anim,
    CFArrayRef array);

/** Animation type. **/

CA_EXTERN CFTypeID CACFAnimationGetTypeID (void);

/* `calculationMode' strings. */

CA_EXTERN const CFStringRef kCACFAnimationLinear;
CA_EXTERN const CFStringRef kCACFAnimationDiscrete;
CA_EXTERN const CFStringRef kCACFAnimationPaced;
CA_EXTERN const CFStringRef kCACFAnimationCubic;
CA_EXTERN const CFStringRef kCACFAnimationCubicPaced;

/* `rotationMode' strings. */

CA_EXTERN const CFStringRef kCACFAnimationRotateAuto;
CA_EXTERN const CFStringRef kCACFAnimationRotateAutoReverse;

/* Common transition types. */

CA_EXTERN const CFStringRef kCACFTransitionFade;
CA_EXTERN const CFStringRef kCACFTransitionMoveIn;
CA_EXTERN const CFStringRef kCACFTransitionPush;
CA_EXTERN const CFStringRef kCACFTransitionReveal;

/* Common transition subtypes. */

CA_EXTERN const CFStringRef kCACFTransitionFromRight;
CA_EXTERN const CFStringRef kCACFTransitionFromLeft;
CA_EXTERN const CFStringRef kCACFTransitionFromTop;
CA_EXTERN const CFStringRef kCACFTransitionFromBottom;

CA_EXTERN_C_END

#endif /* CACFANIMATION_H */
