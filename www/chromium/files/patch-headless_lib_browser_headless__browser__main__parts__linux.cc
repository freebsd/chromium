--- headless/lib/browser/headless_browser_main_parts_linux.cc.orig	2021-03-12 23:57:25 UTC
+++ headless/lib/browser/headless_browser_main_parts_linux.cc
@@ -11,7 +11,7 @@
 namespace headless {
 
 void HeadlessBrowserMainParts::PostMainMessageLoopStart() {
-#if defined(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS_ASH)
+#if defined(USE_DBUS) && !BUILDFLAG(IS_CHROMEOS_ASH) && !defined(OS_BSD)
   bluez::BluezDBusManager::Initialize(/*system_bus=*/nullptr);
 #endif
 }
