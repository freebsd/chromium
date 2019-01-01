--- media/capture/video/linux/video_capture_device_factory_linux.cc.orig	2018-12-30 23:33:57.000000000 +0100
+++ media/capture/video/linux/video_capture_device_factory_linux.cc	2018-12-30 23:35:38.475055000 +0100
@@ -259,6 +259,7 @@
   if (!(capabilities & V4L2_CAP_VIDEO_CAPTURE))
     return false;
 
+#if !defined(OS_FREEBSD)
   const std::vector<uint32_t>& usable_fourccs =
       VideoCaptureDeviceLinux::GetListOfUsableFourCCs(false);
   v4l2_fmtdesc fmtdesc = {};
@@ -267,6 +268,7 @@
     if (base::ContainsValue(usable_fourccs, fmtdesc.pixelformat))
       return true;
   }
+#endif
 
   DVLOG(1) << "No usable formats found";
   return false;
@@ -312,9 +314,13 @@
   v4l2_format.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
   for (; DoIoctl(fd, VIDIOC_ENUM_FMT, &v4l2_format) == 0; ++v4l2_format.index) {
     VideoCaptureFormat supported_format;
+#if !defined(OS_FREEBSD)
     supported_format.pixel_format =
         VideoCaptureDeviceLinux::V4l2FourCcToChromiumPixelFormat(
             v4l2_format.pixelformat);
+#else
+    supported_format.pixel_format = PIXEL_FORMAT_UNKNOWN;
+#endif
 
     if (supported_format.pixel_format == PIXEL_FORMAT_UNKNOWN)
       continue;
