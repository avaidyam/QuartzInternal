/* CoreAnimation - CAImageQueue.h

   Copyright (c) 2006-2007 Apple Inc.
   All rights reserved. */

#ifndef CAIMAGEQUEUE_H
#define CAIMAGEQUEUE_H

#include <QuartzCore/CABase.h>
#include <CoreVideo/CVBase.h>

typedef struct _CAImageQueue *CAImageQueueRef;
typedef struct _CAImageQueueVBLInfo CAImageQueueVBLInfo;
typedef struct _CAImageQueueReleasedImageInfo CAImageQueueReleasedImageInfo;

/* Bit definitions for CAImageQueueSetFlags (). */

enum CAImageQueueFlags
{
  /* Asynchronous queues will be continuously polled by the renderer
   * for new frames. Synchronous queues will only be polled when the
   * layers that reference them are marked dirty (i.e. committed into
   * the render tree.) Asynchronous queues may be marked synchronous at
   * any point, and vice versa. */

  kCAImageQueueAsync		= 1U << 0,

  /* When set, we ignore the rule that displayed images must be after
   * the current layer time. This means that the latest image before the
   * sample time will be displayed. */

  kCAImageQueueFill		= 1U << 1,

  /* Image queue content is "protected". Mac OS X 10.6, iPhone 2.0. */

  kCAImageQueueProtected	= 1U << 2,

  /* Display the clean aperture of the pixel buffer, not the entire
   * encoded contents. Mac OS X 10.6. */

  kCAImageQueueUseCleanAperture	= 1U << 3,

  /* Include the affect of the pixel aspect ratio when applying the
   * contents gravity of the layer. Mac OS X 10.6. */

  kCAImageQueueUseAspectRatio	= 1U << 4,

  /* Use the fastest color matching method. May clip components and/or
   * introduce posterization. Mac OS X 10.6. */

  kCAImageQueueLowQualityColor	= 1U << 5,
};

/* Image types for CAImageQueueInsertImage (). */

enum CAImageQueueImageType
{
  kCAImageQueueNil = 1,
  kCAImageQueueSurface,		/* Mac: CGSSurfaceID; iPhone IOSurfaceID  */
  kCAImageQueueBuffer,		/* result of CAImageRegister*Buffer() */
  kCAImageQueueIOSurface,	/* IOSurfaceID */
};

/* Bit definitions for CAImageQueueInsertImage (). */

enum CAImageQueueImageFlags
{
  /* Marks an inserted image wholly opaque. */

  kCAImageQueueOpaque	= 1U << 0,

  /* Atomically flushes the queue before inserting the new image. */

  kCAImageQueueFlush	= 1U << 1,

  /* Insert the image such that it won't be used or deleted until the
   * queue has next been flushed. */

  kCAImageQueueWillFlush = 1U << 2,

  /* Marks that the inserted image is flipped vertically.
   * Mac OS X 10.6, iPhone 2.0. */

  kCAImageQueueFlipped	= 1U << 3,

  /* Marks that the attached image has outstanding GPU rendering
   * commands targeting it. The consumer of the image sample needs to
   * somehow synchronize with the GPU before displaying the image.
   * Mac OS X 10.6, iPhone 2.0. */

  kCAImageQueueWaitGPU	= 1U << 4,
};

struct _CAImageQueueVBLInfo
{
  uint64_t hostTime;
  CFTimeInterval localTime;
  float hostRate;
};

struct _CAImageQueueReleasedImageInfo
{
  /* The number of times this image was displayed. */

  uint32_t displayCount;

  /* The layer time at which this image was first displayed. */

  CFTimeInterval localTime;

  /* Whether this image was flushed or not. */

  bool wasFlushed;

  /* The host time at which this image was first displayed. */

  uint64_t hostTime;
};

CA_EXTERN_C_BEGIN

typedef void (*CAImageQueueReleaseCallback) (unsigned int type,
    uint64_t id, void *info);

/* Create a new image queue. All images in the queue will have the
 * specified width and height. The queue will be able to hold 'capacity'
 * images at once. */

CA_EXTERN CAImageQueueRef CAImageQueueCreate (uint32_t width, uint32_t
    height, uint32_t capacity)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Free all images in the queue. Any subsequent image queue operation
 * will have undefined results. */

CA_EXTERN void CAImageQueueInvalidate (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Sets the `owner' of the image queue. 'ptr' will not be retained by
 * the image queue, since it's assumed that it retains the queue.
 * Currently unless 'ptr' is a CALayer object, the behavior is undefined. */

CA_EXTERN void CAImageQueueSetOwner (CAImageQueueRef iq, CFTypeRef ptr)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Change the size of images added to the queue. */

CA_EXTERN void CAImageQueueSetSize (CAImageQueueRef iq, uint32_t width,
    uint32_t height)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN uint32_t CAImageQueueGetWidth (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN uint32_t CAImageQueueGetHeight (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN uint32_t CAImageQueueGetCapacity (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Invalidate all images in the queue. */

CA_EXTERN void CAImageQueueFlush (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Removes all consumed images except the latest from the queue. Returns
 * the number of free slots. */

CA_EXTERN size_t CAImageQueueCollect (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Push one image into the queue for time 't'. The image is of kind
 * 'type' and has identifier 'id' (meaning defined by 'type'). This
 * function returns true if successful, or false if the queue was
 * already full. If non-null, 'release' defines a function to be called
 * when the image is removed from the queue. */

CA_EXTERN bool CAImageQueueInsertImage (CAImageQueueRef iq, CFTimeInterval t,
    unsigned int type, uint64_t id, uint32_t flags,
    CAImageQueueReleaseCallback release, void *info)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Defines the latest time that the image queue has the canonical image
 * for. If an image is required after this time and none is available,
 * offline renderers may decide to wait for new images to be inserted
 * into the queue. (Real-time renderers will always use the latest
 * image at or before the current sample time.) The default value of
 * this property is Infinity. Flushing the queue resets it to the
 * default value. (Note that if layer time is currently playing backwards
 * the meaning of any comparisons against this value are inverted.) */

CA_EXTERN void CAImageQueueSetLatestCanonicalTime (CAImageQueueRef iq,
    CFTimeInterval t)
    __OSX_AVAILABLE_STARTING (__MAC_10_6, __IPHONE_2_0);

/* When called from the 'release' callback of an image entered into
 * the queue, returns the address of a structure describing when the
 * image was first displayed (in layer time), and how many times it
 * was displayed. May return a null pointer. */

CA_EXTERN const CAImageQueueReleasedImageInfo *CAImageQueueGetReleasedImageInfo (void)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Register an image buffer with the queue. Returns the id to be used
 * to insert the buffer into the queue (with type `kCAImageQueueBuffer').
 * 'format' is one of the members of the `CAImageFormat' enum. */

CA_EXTERN uint64_t CAImageQueueRegisterBuffer (CAImageQueueRef iq,
    void *data, size_t rowbytes, size_t width, size_t height, unsigned
    int format)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Register a CoreVideo style pixel buffer with the image queue.
 * Returns the id to be used to insert the buffer into the queue (with
 * type `kCAImageQueueBuffer'). `pixel_format' is the CoreVideo style
 * pixel format type. The 'flags' argument should currently be zero. */

CA_EXTERN uint64_t CAImageQueueRegisterPixelBuffer (CAImageQueueRef iq,
    void *data, size_t data_size, size_t rowbytes, size_t width, size_t height,
    OSType pixel_format, CFDictionaryRef attachments, uint32_t flags)
    __OSX_AVAILABLE_STARTING (__MAC_10_6, __IPHONE_2_0);

/* Remove a previously registered image buffer. */

CA_EXTERN void CAImageQueueDeleteBuffer (CAImageQueueRef iq, uint64_t id)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Set or get the flags associated with the queue 'iq'. */

CA_EXTERN void CAImageQueueSetFlags (CAImageQueueRef iq, uint32_t mask,
    uint32_t flags)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN uint32_t CAImageQueueGetFlags (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Query the next times at which the queue will be sampled. Up to
 * 'count' times will be placed in 'buffer'. The actual number of time
 * values stored in the buffer will be returned. */

CA_EXTERN size_t CAImageQueueGetTimes (CAImageQueueRef iq,
    CFTimeInterval *buffer, size_t count)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN size_t CAImageQueueGetVBLInfo (CAImageQueueRef iq,
    CAImageQueueVBLInfo *buffer, size_t count)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN void CAImageQueueGetTimeStamp (CAImageQueueRef iq,
    const CAImageQueueVBLInfo *vbl, CVTimeStamp *ts)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Returns the sample time of the latest image in the queue. */

CA_EXTERN CFTimeInterval CAImageQueueGetLatestTime (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Returns the sample time of the latest displayed image in the queue. */

CA_EXTERN CFTimeInterval CAImageQueueGetDisplayTime (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Returns the number of unconsumed images in the queue. If that is
 * nonzero, the minimum and maximum time of those images is placed in
 * 'minTime' and 'maxTime' respectively.  */

CA_EXTERN size_t CAImageQueueGetUnconsumedImageCount (CAImageQueueRef iq, 
    CFTimeInterval *minTime, CFTimeInterval *maxTime)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Returns the display mask associated with 'iq'. */

CA_EXTERN uint32_t CAImageQueueGetDisplayMask (CAImageQueueRef iq)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Returns the CF type pointer for image queue objects. */

CA_EXTERN CFTypeID CAImageQueueGetTypeID (void)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN_C_END

#endif /* CAIMAGEQUEUE_H */
