--- media/base/video_frame.h.orig	2018-12-03 21:17:03.000000000 +0100
+++ media/base/video_frame.h	2018-12-13 23:50:03.082947000 +0100
@@ -72,7 +72,7 @@
     STORAGE_UNOWNED_MEMORY = 2,  // External, non owned data pointers.
     STORAGE_OWNED_MEMORY = 3,  // VideoFrame has allocated its own data buffer.
     STORAGE_SHMEM = 4,         // Pixels are backed by Shared Memory.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // TODO(mcasas): Consider turning this type into STORAGE_NATIVE
     // based on the idea of using this same enum value for both DMA
     // buffers on Linux and CVPixelBuffers on Mac (which currently use
@@ -238,7 +238,7 @@
       uint8_t* a_data,
       base::TimeDelta timestamp);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Wraps provided dmabufs
   // (https://www.kernel.org/doc/html/latest/driver-api/dma-buf.html) with a
   // VideoFrame. The frame will take ownership of |dmabuf_fds|, and will
@@ -415,7 +415,7 @@
   // Returns the offset into the shared memory where the frame data begins.
   size_t shared_memory_offset() const;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Returns a vector containing the backing DmaBufs for this frame. The number
   // of returned DmaBufs will be equal or less than the number of planes of
   // the frame. If there are less, this means that the last FD contains the
@@ -625,7 +625,7 @@
   // memory.
   size_t shared_memory_offset_;
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Dmabufs for the frame, used when storage is STORAGE_DMABUFS. Size is either
   // equal or less than the number of planes of the frame. If it is less, then
   // the memory area represented by the last FD contains the remaining planes.
