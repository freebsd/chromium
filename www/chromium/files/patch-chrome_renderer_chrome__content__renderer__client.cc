--- chrome/renderer/chrome_content_renderer_client.cc.orig	2020-09-08 19:14:01 UTC
+++ chrome/renderer/chrome_content_renderer_client.cc
@@ -1089,7 +1089,7 @@ WebPlugin* ChromeContentRendererClient::CreatePlugin(
       }
 
       case chrome::mojom::PluginStatus::kRestartRequired: {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
         placeholder =
             create_blocked_plugin(IDR_BLOCKED_PLUGIN_HTML,
                                   l10n_util::GetStringFUTF16(
