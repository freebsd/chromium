--- media/audio/audio_manager.h.orig	2021-03-12 23:57:26 UTC
+++ media/audio/audio_manager.h
@@ -60,7 +60,7 @@ class MEDIA_EXPORT AudioManager {
   static std::unique_ptr<AudioManager> CreateForTesting(
       std::unique_ptr<AudioThread> audio_thread);
 
-#if defined(OS_LINUX) || defined(OS_CHROMEOS)
+#if defined(OS_LINUX) || defined(OS_CHROMEOS) || defined(OS_BSD)
   // Sets the name of the audio source as seen by external apps. Only actually
   // used with PulseAudio as of this writing.
   static void SetGlobalAppName(const std::string& app_name);
