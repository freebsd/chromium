--- chrome/common/chrome_switches.h.orig	2021-03-12 23:57:19 UTC
+++ chrome/common/chrome_switches.h
@@ -255,7 +255,7 @@ extern const char kAllowNaClFileHandleAPI[];
 extern const char kAllowNaClSocketAPI[];
 #endif
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || \
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_MAC) || defined(OS_BSD) || \
     defined(OS_WIN)
 extern const char kEnableNewAppMenuIcon[];
 extern const char kGuest[];
