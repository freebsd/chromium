--- chrome/common/extensions/command.cc.orig.port	Tue Mar 10 23:29:08 2015
+++ chrome/common/extensions/command.cc	Wed Mar 11 07:22:50 2015
@@ -301,7 +301,7 @@ std::string Command::CommandPlatform() {
   return values::kKeybindingPlatformMac;
 #elif defined(OS_CHROMEOS)
   return values::kKeybindingPlatformChromeOs;
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   return values::kKeybindingPlatformLinux;
 #else
   return "";
