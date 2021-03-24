--- tools/gn/src/util/sys_info.cc.orig	2021-03-13 00:10:18 UTC
+++ tools/gn/src/util/sys_info.cc
@@ -34,6 +34,8 @@ std::string OperatingSystemArchitecture() {
     arch = "x86_64";
   } else if (arch == "amd64") {
     arch = "x86_64";
+  } else if (arch == "arm64") {
+    arch = "aarch64";
   } else if (os == "AIX" || os == "OS400") {
     arch = "ppc64";
   }
