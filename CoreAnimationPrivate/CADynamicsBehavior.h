/* CoreAnimation - CADynamicsBehavior.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CADYNAMICSBEHAVIOR_H
#define CADYNAMICSBEHAVIOR_H

#include <QuartzCore/CABase.h>
#include "CABehavior.h"

CA_EXTERN_C_BEGIN

@class CABehavior, CAForceField, CASpring;

@interface CADynamicsBehavior: CABehavior

@property BOOL reactsToCollisions;
@property double angularDrag;
@property double drag;
@property double springScale;
@property double collisionInterval;
@property double stoppedAngularVelocity;
@property double stoppedVelocity;
@property double minimumTimeStep;
@property double timeStep;

@property (copy) NSArray<CAForceField *> *forceFields;
@property (copy) NSArray<CASpring *> *springs;

@end

@interface CALayer (CADynamicsBehavior)

@property double coefficientOfRestitution;
@property double momentOfInertia;
@property double mass;

@end

CA_EXTERN_C_END

#endif // CADYNAMICSBEHAVIOR_H
