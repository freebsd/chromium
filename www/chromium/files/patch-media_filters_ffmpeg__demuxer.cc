--- media/filters/ffmpeg_demuxer.cc.orig	2017-04-19 19:06:35 UTC
+++ media/filters/ffmpeg_demuxer.cc
@@ -1221,24 +1221,6 @@ void FFmpegDemuxer::OnFindStreamInfoDone
   // If no estimate is found, the stream entry will be kInfiniteDuration.
   std::vector<base::TimeDelta> start_time_estimates(format_context->nb_streams,
                                                     kInfiniteDuration);
-  const AVFormatInternal* internal = format_context->internal;
-  if (internal && internal->packet_buffer &&
-      format_context->start_time != static_cast<int64_t>(AV_NOPTS_VALUE)) {
-    struct AVPacketList* packet_buffer = internal->packet_buffer;
-    while (packet_buffer != internal->packet_buffer_end) {
-      DCHECK_LT(static_cast<size_t>(packet_buffer->pkt.stream_index),
-                start_time_estimates.size());
-      const AVStream* stream =
-          format_context->streams[packet_buffer->pkt.stream_index];
-      if (packet_buffer->pkt.pts != static_cast<int64_t>(AV_NOPTS_VALUE)) {
-        const base::TimeDelta packet_pts =
-            ConvertFromTimeBase(stream->time_base, packet_buffer->pkt.pts);
-        if (packet_pts < start_time_estimates[stream->index])
-          start_time_estimates[stream->index] = packet_pts;
-      }
-      packet_buffer = packet_buffer->next;
-    }
-  }
 
   std::unique_ptr<MediaTracks> media_tracks(new MediaTracks());
 
