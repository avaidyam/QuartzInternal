/* CoreAnimation - CADebug.h

   Copyright (c) 2006-2007 Apple Inc.
   All rights reserved. */

#ifndef CADEBUG_H
#define CADEBUG_H

#include <QuartzCore/CABase.h>

/* The supported debug options. The `CA_FOO=1' comments describe the
 * environment variables that can be used to enable the options via the
 * command line. */

enum CADebugFlags
{
  /* Flash updated screen regions yellow. CA_COLOR_FLUSH=1 */

  kCADebugColorFlush			= 1U << 0,

  /* Put cyan overlay over images that were copied by CoreAnimation.
   * CA_COLOR_COPY=1 */

  kCADebugColorCopy			= 1U << 1,

  /* Put red overlay over layers that were drawn with blending enabled;
   * put green overlay over layers drawn without blending. CA_COLOR_OPAQUE=1 */

  kCADebugColorOpaque			= 1U << 2,

  /* Don't wait 10ms after performing color-flush option. CA_COLOR_NO_WAIT=1 */

  kCADebugColorNoWait			= 1U << 3,

  /* Flush graphics context after drawing every primitive. CA_AUTO_FLUSH=1 */

  kCADebugAutoFlush			= 1U << 4,

  /* Print render tree to standard error every frame. CA_PRINT_TREE=1 */

  kCADebugPrintTree			= 1U << 5,

  /* Print instance counts of render object types every frame.
   * CA_PRINT_OBJECTS=1 */

  kCADebugPrintObjects			= 1U << 6,

  /* Print message whenever an implicit transaction is started.
   * CA_LOG_IMPLICIT_TRANSACTIONS=1 */

  kCADebugPrintImplicitTransactions	= 1U << 7,

  /* Periodically print current and maximum image memory use.
   * CA_LOG_MEMORY_USAGE=1 */

  kCADebugPrintMemoryUsage		= 1U << 8,

  /* Print message whenever an image is copied when it's committed to
   * the render tree. CA_LOG_IMAGE_COPIES=1 */

  kCADebugPrintImageCopies		= 1U << 9,

  /* Periodically print messages about rendering performance.
   * CA_PRINT_PERF=1 */

  kCADebugPrintPerformance		= 1U << 10,

  /* Disable opacity-culling. CA_DISABLE_OCCLUSION_CULLING=1 */

  kCADebugDisableOcclusionCulling	= 1U << 11,

  /* Disable incremental update. CA_DISABLE_DIRTY_REGIONS=1 */

  kCADebugDisableDirtyRegions		= 1U << 12,

  /* Print message whenever a layer backing store is drawn into before
   * its back buffer is idle, and thus a third buffer is allocated.
   * CA_LOG_TRIPLE_BUFFERING=1 */

  kCADebugPrintTripleBuffering		= 1U << 13,

  /* Put magenta overlay over images whose source pixels aren't aligned
   * to destination pixels. CA_COLOR_SUBPIXEL=1 */

  kCADebugColorSubpixel			= 1U << 14,

  /* Disable all rendering. CA_DISABLE_RENDER=1 */

  kCADebugDisableRender			= 1U << 15,

  /* Wake up to render even when we know nothing has changed. Combine
   * with kCADebugDisableDirtyRegions to measure raw performance.
   * CA_ALWAYS_RENDER=1 */

  kCADebugAlwaysRender			= 1U << 16,

  /* Put yellow overlay over offscreen-rendered content.
   * CA_COLOR_OFFSCREEN=1 */

  kCADebugColorOffscreen		= 1U << 17,

  /* Put blue overlay over content that's detached from the compositor.
   * CA_COLOR_DETACHED=1 */

  kCADebugColorDetached		 	= 1U << 18,
};

#define CADebugFlagNames "color-flush", "color-copy", "color-opaque", \
  "color-no-wait", "auto-flush", "print-tree", "print-objects", \
  "print-implicit-transactions", "print-memory-usage", "print-image-copies", \
  "print-performance", "disable-occlusion-culling", "disable-dirty-regions", \
  "print-triple-buffering", "color-subpixel", "disable-rendering", \
  "always-render", "color-offscreen", "color-detached"

CA_EXTERN_C_BEGIN

/* Returns the bitmask defining the currently enabled debug options. */

CA_EXTERN uint32_t CAGetDebugFlags (void)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Change the currently enabled debug options; all bits in 'mask' are
 * set to the corresponding values in 'value'. */

CA_EXTERN void CASetDebugFlags (uint32_t mask, uint32_t value)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* These two functions are for debugging CoreAnimation memory usage - they
 * return the current and maximum number of bytes allocated by CoreAnimation
 * for images. */

CA_EXTERN size_t CAGetCurrentImageBytes (void)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);
CA_EXTERN size_t CAGetMaximumImageBytes (void)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Returns the total number of transactions committed. */

CA_EXTERN uint32_t CAGetTransactionCounter (void)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Returns the total number of frames rendered locally. */

CA_EXTERN uint32_t CAGetFrameCounter (void)
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

/* Set this to enable extra checks in -[CALayer release] to catch layers
 * being over-released. */

CA_EXTERN unsigned int CADebugLayerRelease
    __OSX_AVAILABLE_STARTING (__MAC_10_5, __IPHONE_2_0);

CA_EXTERN_C_END

#endif /* CADEBUG_H */
