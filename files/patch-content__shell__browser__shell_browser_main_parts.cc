--- content/shell/browser/shell_browser_main_parts.cc.orig	Tue Mar 10 23:41:41 2015
+++ content/shell/browser/shell_browser_main_parts.cc	Wed Mar 11 07:22:50 2015
@@ -38,7 +38,7 @@
 #if defined(USE_AURA) && defined(USE_X11)
 #include "ui/events/devices/x11/touch_factory_x11.h"
 #endif
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
 #include "ui/base/ime/input_method_initializer.h"
 #endif
 
@@ -105,7 +105,7 @@
 }
 
 void ShellBrowserMainParts::PreEarlyInitialization() {
-#if !defined(OS_CHROMEOS) && defined(USE_AURA) && defined(OS_LINUX)
+#if !defined(OS_CHROMEOS) && defined(USE_AURA) && (defined(OS_BSD) || defined(OS_LINUX))
   ui::InitializeInputMethodForTesting();
 #endif
 #if defined(OS_ANDROID)
