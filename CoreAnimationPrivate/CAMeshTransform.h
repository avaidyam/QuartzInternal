/* CoreAnimation - CAMeshTransform.h
 
 Copyright (c) 2006-2007 Apple Inc.
 All rights reserved. */

#ifndef CAMESHTRANSFORM_H
#define CAMESHTRANSFORM_H

#include <QuartzCore/CABase.h>

CA_EXTERN_C_BEGIN

typedef struct CAMeshVertex {
    CGPoint from;
    CAPoint3D to;
} CAMeshVertex;

typedef struct CAMeshFace {
    uint32_t indices[4];
    float w[4];
} CAMeshFace;

@interface CAMeshTransform: NSObject <NSSecureCoding, NSCopying, NSMutableCopying>

+ (instancetype)meshTransformWithVertexCount:(uint64_t)vertexCount
                                    vertices:(CAMeshVertex *)vertices
                                   faceCount:(uint64_t)faceCount
                                       faces:(CAMeshFace *)faces
                          depthNormalization:(NSString *)type;

@property (readonly) int subdivisionSteps;
@property (readonly, copy) NSString *depthNormalization;
@property (readonly) uint64_t faceCount;
@property (readonly) uint64_t vertexCount;

- (instancetype)_initWithMeshTransform:(CAMeshTransform *)transform;
- (instancetype)initWithVertexCount:(uint64_t)vertexCount
                           vertices:(CAMeshVertex *)vertices
                          faceCount:(uint64_t)faceCount
                              faces:(CAMeshFace *)faces
                 depthNormalization:(NSString *)type;

- (instancetype)meshTransformForLayer:(CALayer *)layer;

- (id)_subdivideToDepth:(NSInteger)depth;
- (id)_data;
- (BOOL)_constructWithData:(id)data;

- (CAMeshFace)faceAtIndex:(uint64_t)idx;
- (CAMeshVertex)vertexAtIndex:(uint64_t)idx;

@end

@interface CAMeshInterpolator: CAMeshTransform

@end

@interface CAMutableMeshTransform : CAMeshTransform

+ (instancetype)meshTransform;

@property int subdivisionSteps;
@property (copy) NSString *depthNormalization;

- (void)removeFaceAtIndex:(uint64_t)idx;
- (void)addFace:(CAMeshFace)face;
- (void)replaceFaceAtIndex:(uint64_t)idx withFace:(CAMeshFace)face;
- (void)removeVertexAtIndex:(uint64_t)idx;
- (void)addVertex:(CAMeshVertex)vertex;
- (void)replaceVertexAtIndex:(uint64_t)idx withVertex:(CAMeshVertex)vertex;

@end

@interface CALayer (Mesh)

@property (copy) CAMeshTransform *meshTransform;

@end

/** Depth normalization types. **/

CA_EXTERN NSString * const kCADepthNormalizationNone;
CA_EXTERN NSString * const kCADepthNormalizationWidth;
CA_EXTERN NSString * const kCADepthNormalizationHeight;
CA_EXTERN NSString * const kCADepthNormalizationMin;
CA_EXTERN NSString * const kCADepthNormalizationMax;
CA_EXTERN NSString * const kCADepthNormalizationAverage;

CA_EXTERN_C_END

#endif // CAMESHTRANSFORM_H
