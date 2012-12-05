/* 
 * (c) 2012
 *
 */

#include "matroska-track.h"

/* TODO: check if all fields are used */
struct _MatroskaTrack{
  Pad       *pad;
  Caps      *caps;
  guint         index;
  FlowReturn last_flow;
  /* reverse playback */
  ClockTime  from_time;
  gint64                   from_offset;
  gint64                   to_offset;

  GArray       *index_table;

  gint          index_writer_id;

  /* some often-used info */
  gchar        *codec_id, *codec_name, *name, *language;
  guint8       *codec_priv;
  guint         codec_priv_size;
  guint8       *codec_state;
  guint         codec_state_size;
  MatroskaTrackType type;
  guint         uid, num;
  MatroskaTrackFlags flags;
  guint64       default_duration;
  guint64       pos;
  gdouble       timecodescale;

  gboolean      set_discont; /* TRUE = set DISCONT flag on next buffer */

  /* Special flag for Vorbis and Theora, for which we need to send
   * codec_priv first before sending any data, and just testing
   * for time == 0 is not enough to detect that. Used by demuxer */
  gboolean      send_xiph_headers;

  /* Special flag for Flac, for which we need to reconstruct the header
   * buffer from the codec_priv data before sending any data, and just
   * testing for time == 0 is not enough to detect that. Used by demuxer */
  gboolean      send_flac_headers;

  /* Special flag for Speex, for which we need to reconstruct the header
   * buffer from the codec_priv data before sending any data, and just
   * testing for time == 0 is not enough to detect that. Used by demuxer */
  gboolean      send_speex_headers;

  /* Special flag for VobSub, for which we have to send colour table info
   * (if available) first before sending any data, and just testing
   * for time == 0 is not enough to detect that. Used by demuxer */
  gboolean      send_dvd_event;

  /* Special counter for muxer to skip the first N vorbis/theora headers -
   * they are put into codec private data, not muxed into the stream */
  guint         xiph_headers_to_skip;

  /* Used for postprocessing a frame before it is pushed from the demuxer */
  FlowReturn (*postprocess_frame) (Element *element,
                                      MatroskaTrackContext *context,
				      Buffer **buffer);

  /* Tags to send after newsegment event */
  TagList   *pending_tags;

  /* A GArray of MatroskaTrackEncoding structures which contain the
   * encoding (compression/encryption) settings for this track, if any */
  GArray       *encodings;

  /* Whether the stream is EOS */
  gboolean      eos;
#ifdef MKV_DEMUX_MODIFICATION
  ClockTime last_ts;
  GQueue* queue;

  gboolean found_next_kframe;
  gint32 num_frames_bw_keyframes;
  guint64 avg_duration_bw_keyframes;
  guint32 frames_to_show_bw_keyframes;
  ClockTime prev_kframe_timestamp;
  ClockTime next_kframe_timestamp;
#endif

  /* any alignment we need our output buffers to have */
  gint          alignment;
};

typedef struct _MatroskaTrackVideo{
  MatroskaTrack parent;

  guint         pixel_width, pixel_height;
  guint         display_width, display_height;
  gdouble       default_fps;
  MatroskaAspectRatioMode asr_mode;
  guint32       fourcc;

  /* QoS */
  ClockTime  earliest_time;

  Buffer     *dirac_unit;
} MatroskaTrackVideo;

typedef struct _MatroskaTrackAudio{
  MatroskaTrack parent;

  guint         samplerate, channels, bitdepth;

  guint32       wvpk_block_index;
} MatroskaTrackAudio;

typedef struct _MatroskaTrackSubtitle{
  MatroskaTrack parent;

  gboolean    check_utf8;     /* buffers should be valid UTF-8 */
  gboolean    check_markup;   /* check if buffers contain markup
                               * or plaintext and escape characters */
  gboolean    invalid_utf8;   /* work around broken files      */
  gboolean    seen_markup_tag;  /* markup found in text */
} MatroskaTrackSubtitle;

typedef struct _GstMatroskaIndex {
  guint64        pos;      /* of the corresponding *cluster*! */
  guint16        track;    /* reference to 'num' */
  ClockTime   time;     /* in nanoseconds */
  guint32        block;    /* number of the block in the cluster */
} MatroskaIndex;

typedef struct _Wavpack4Header {
  guchar  ck_id [4];     /* "wvpk"                                         */
  guint32 ck_size;       /* size of entire frame (minus 8, of course)      */
  guint16 version;       /* 0x403 for now                                  */
  guint8  track_no;      /* track number (0 if not used, like now)         */
  guint8  index_no;      /* remember these? (0 if not used, like now)      */
  guint32 total_samples; /* for entire file (-1 if unknown)                */
  guint32 block_index;   /* index of first sample in block (to file begin) */
  guint32 block_samples; /* # samples in this block                        */
  guint32 flags;         /* various flags for id and decoding              */
  guint32 crc;           /* crc for actual decoded data                    */
} Wavpack4Header;

