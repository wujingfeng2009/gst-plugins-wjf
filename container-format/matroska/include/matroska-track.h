/* 
 * (c) 2012
 *
 */


#ifndef _H_MATROSKA_TRACK_H__
#define _H_MATROSKA_TRACK_H__

#include "matroska-common.h"
#include "matroska-ids.h"


/*
 * Enumerations for various types (mapping from binary
 * value to what it actually means).
 */

typedef enum {
  MTRSK_TRACK_TYPE_VIDEO    = 0x1,
  MTRSK_TRACK_TYPE_AUDIO    = 0x2,
  MTRSK_TRACK_TYPE_COMPLEX  = 0x3,
  MTRSK_TRACK_TYPE_LOGO     = 0x10,
  MTRSK_TRACK_TYPE_SUBTITLE = 0x11,
  MTRSK_TRACK_TYPE_BUTTONS  = 0x12,
  MTRSK_TRACK_TYPE_CONTROL  = 0x20,
} MatroskaTrackType;

typedef struct _MatroskaTrack MatroskaTrack;

gboolean matroska_track_init_video_context    (MatroskaTrackContext ** p_context);

/*
 * These aren't in any way "matroska-form" things,
 * it's just something I use in the muxer/demuxer.
 */

typedef enum {
  MTRSK_TRACK_ENABLED = (1<<0),
  MTRSK_TRACK_DEFAULT = (1<<1),
  MTRSK_TRACK_LACING  = (1<<2),
  MTRSK_TRACK_FORCED  = (1<<3),
  MTRSK_TRACK_SHIFT   = (1<<16)
} MatroskaTrackFlags;

typedef enum {
  MTRSK_VIDEOTRACK_INTERLACED = (MTRSK_TRACK_SHIFT<<0)
} MatroskaVideoTrackFlags;



typedef enum {
  MTRSK_ASPECT_RATIO_MODE_FREE  = 0x0,
  MTRSK_ASPECT_RATIO_MODE_KEEP  = 0x1,
  MTRSK_ASPECT_RATIO_MODE_FIXED = 0x2,
} MatroskaAspectRatioMode;


typedef enum {
  MTRSK_TRACK_ENCODING_SCOPE_FRAME = (1<<0),
  MTRSK_TRACK_ENCODING_SCOPE_CODEC_DATA = (1<<1),
  MTRSK_TRACK_ENCODING_SCOPE_NEXT_CONTENT_ENCODING = (1<<2)
} MatroskaTrackEncodingScope;

typedef enum {
  MTRSK_TRACK_COMPRESSION_ALGORITHM_ZLIB = 0,
  MTRSK_TRACK_COMPRESSION_ALGORITHM_BZLIB = 1,
  MTRSK_TRACK_COMPRESSION_ALGORITHM_LZO1X = 2,
  MTRSK_TRACK_COMPRESSION_ALGORITHM_HEADERSTRIP = 3
} MatroskaTrackCompressionAlgorithm;

typedef struct _GstMatroskaTrackEncoding {
  guint   order;
  guint   scope     : 3;
  guint   type      : 1;
  guint   comp_algo : 2;
  guint8 *comp_settings;
  guint   comp_settings_length;
} MatroskaTrackEncoding;

gboolean gst_matroska_track_init_video_context    (MatroskaTrackContext ** p_context);
gboolean gst_matroska_track_init_audio_context    (MatroskaTrackContext ** p_context);
gboolean gst_matroska_track_init_subtitle_context (MatroskaTrackContext ** p_context);

void gst_matroska_register_tags (void);


#endif /* _H_MATROSKA_TRACK_H__ */

