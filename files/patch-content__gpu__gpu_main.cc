--- content/gpu/gpu_main.cc.orig	2015-01-21 20:28:16 UTC
+++ content/gpu/gpu_main.cc
@@ -76,7 +76,7 @@
 bool CollectGraphicsInfo(gpu::GPUInfo& gpu_info);
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if !defined(OS_CHROMEOS)
 bool CanAccessNvidiaDeviceFile();
 #endif
@@ -161,13 +161,13 @@
     message_loop_type = base::MessageLoop::TYPE_UI;
   }
   base::MessageLoop main_message_loop(message_loop_type);
-#elif defined(OS_LINUX) && defined(USE_X11)
+#elif (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
   // We need a UI loop so that we can grab the Expose events. See GLSurfaceGLX
   // and https://crbug.com/326995.
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_UI);
   scoped_ptr<ui::PlatformEventSource> event_source =
       ui::PlatformEventSource::CreateDefault();
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   base::MessageLoop main_message_loop(base::MessageLoop::TYPE_DEFAULT);
 #elif defined(OS_MACOSX)
   // This is necessary for CoreAnimation layers hosted in the GPU process to be
@@ -234,6 +234,10 @@
       initialized_sandbox = true;
     }
 #endif  // defined(OS_LINUX)
+#if defined(OS_BSD)
+    bool initialized_gl_context = false;
+    bool should_initialize_gl_context = false;
+#endif
 
     base::TimeTicks before_initialize_one_off = base::TimeTicks::Now();
 
@@ -281,7 +285,7 @@
       }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
       initialized_gl_context = true;
 #if !defined(OS_CHROMEOS)
       if (gpu_info.gpu.vendor_id == 0x10de &&  // NVIDIA
@@ -316,14 +320,16 @@ int GpuMain(const MainFunctionParams& parameters) {
       watchdog_thread = NULL;
     }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     should_initialize_gl_context = !initialized_gl_context &&
                                    !dead_on_arrival;
 
+#if !defined(OS_BSD)
     if (!initialized_sandbox) {
       gpu_info.sandboxed = StartSandboxLinux(gpu_info, watchdog_thread.get(),
                                              should_initialize_gl_context);
     }
+#endif
 #elif defined(OS_WIN)
     gpu_info.sandboxed = StartSandboxWindows(parameters.sandbox_info);
 #elif defined(OS_MACOSX)
@@ -424,7 +430,7 @@ bool CollectGraphicsInfo(gpu::GPUInfo& gpu_info) {
 }
 #endif
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 #if !defined(OS_CHROMEOS)
 bool CanAccessNvidiaDeviceFile() {
   bool res = true;
