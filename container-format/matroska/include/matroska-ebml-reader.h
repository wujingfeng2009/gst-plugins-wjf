/* 
 * (c) 2012
 *
 */



#ifndef _H_MATROSKA_EBML_READER_H__
#define _H_MATROSKA_EBML_READER_H__

#include "matroska-common.h"
#include "matroska-ids.h"


#define UINT64_VAL_UNKNOWN	G_MAXUINT64
#define UINT32_VAL_UNKNOWN	G_MAXUINT32

typedef struct GNode GNode;

typedef struct _EbmlMaster {
	guint32 id;
	guint32 id_bytes;
	guint64 size;
	guint32 size_bytes;
	guint8 *data;
	guint64 file_pos;
}EbmlMaster;

typedef struct _FileCache {
  TypeReader reader;
  guint64 cache_file_offset;
  gchar *file_path;
} FileCache;

typedef struct _MatroskaEbmlReader {
  FileCache *cache;
  GNode *master_tree;
} MatroskaEbmlReader;

typedef enum {
  FILE_CACHE_SEEK_SET,
  FILE_CACHE_SEEK_CUR,
  FILE_CACHE_SEEK_END,
} File_cache_seek_t;



FileCache *File_cache_new(guint32 cache_size);
FileCache *File_cache_new_with_file(guint32 cache_size, gchar *file_path);
void File_cache_free(FileCache *cache);

gboolean File_cache_seek(FileCache *cache, guint64 file_offset, File_cache_seek_t seek_type);
guint64 File_cache_tell(FileCache *cache);

guint64 File_cache_get_file_length(FileCache *cache);
guint32 File_cache_get_cache_size(FileCache *cache);

gboolean File_cache_reset_cache_size(FileCache *cache, guint32 cache_size);
gboolean File_cache_set_file(FileCache *cache, gchar *file_path);

#define FILE_CACHE_CAST_READER(cache_ptr)	\
	(((cache_ptr) == NULL) ? (NULL) : (TypeReader *)(cache_ptr))
#define READER_CAST_FILE_CACHE(reader_ptr)	\
	((reader_ptr) == NULL) ? (NULL) : (FileCache *)(reader_ptr))









typedef GstFlowReturn (*GstPeekData) (gpointer * context, guint peek, const guint8 ** data);

/* returns UNEXPECTED if not enough data */
GstFlowReturn gst_ebml_peek_id_length    (guint32 * _id, guint64 * _length,
                                          guint * _needed,
                                          GstPeekData peek, gpointer * ctx,
                                          GstElement * el, guint64 offset);

void          gst_ebml_read_init         (GstEbmlRead * ebml,
                                          GstElement * el, GstBuffer * buf,
                                          guint64 offset);

void          gst_ebml_read_clear        (GstEbmlRead * ebml);

GstFlowReturn gst_ebml_peek_id           (GstEbmlRead * ebml, guint32 * id);

/* return _PARSE if not enough data to read what is needed, _ERROR or _OK */
GstFlowReturn gst_ebml_read_skip         (GstEbmlRead *ebml);

GstFlowReturn gst_ebml_read_buffer       (GstEbmlRead *ebml,
                                          guint32     *id,
                                          GstBuffer  **buf);

GstFlowReturn gst_ebml_read_uint         (GstEbmlRead *ebml,
                                          guint32     *id,
                                          guint64     *num);

GstFlowReturn gst_ebml_read_sint         (GstEbmlRead *ebml,
                                          guint32     *id,
                                          gint64      *num);

GstFlowReturn gst_ebml_read_float        (GstEbmlRead *ebml,
                                          guint32     *id,
                                          gdouble     *num);

GstFlowReturn gst_ebml_read_ascii        (GstEbmlRead *ebml,
                                          guint32     *id,
                                          gchar      **str);

GstFlowReturn gst_ebml_read_utf8         (GstEbmlRead *ebml,
                                          guint32     *id,
                                          gchar      **str);

GstFlowReturn gst_ebml_read_date         (GstEbmlRead *ebml,
                                          guint32     *id,
                                          gint64      *date);

GstFlowReturn gst_ebml_read_master       (GstEbmlRead *ebml,
                                          guint32     *id);

GstFlowReturn gst_ebml_read_pop_master   (GstEbmlRead *ebml);

GstFlowReturn gst_ebml_read_binary       (GstEbmlRead *ebml,
                                          guint32     *id,
                                          guint8     **binary,
                                          guint64     *length);

GstFlowReturn gst_ebml_read_header       (GstEbmlRead *read,
                                          gchar      **doctype,
                                          guint       *version);

/* Returns current (absolute) position of Ebml parser,
 * i.e. taking into account offset provided at init */
static inline guint64
gst_ebml_read_get_pos (GstEbmlRead * ebml)
{
  GstEbmlMaster *m;

  g_return_val_if_fail (ebml->readers, 0);
  g_return_val_if_fail (ebml->readers->len, 0);

  m = &(g_array_index (ebml->readers, GstEbmlMaster, ebml->readers->len - 1));
  return m->offset + gst_byte_reader_get_pos (&m->br);
}

/* Returns starting offset of Ebml parser */
static inline guint64
gst_ebml_read_get_offset (GstEbmlRead * ebml)
{
  return ebml->offset;
}

static inline GstByteReader *
gst_ebml_read_br (GstEbmlRead * ebml)
{
  g_return_val_if_fail (ebml->readers, NULL);
  g_return_val_if_fail (ebml->readers->len, NULL);

  return &(g_array_index (ebml->readers,
          GstEbmlMaster, ebml->readers->len - 1).br);
}

static inline gboolean
gst_ebml_read_has_remaining (GstEbmlRead * ebml, guint64 bytes_needed,
    gboolean auto_pop)
{
  gboolean res;

  res = (gst_byte_reader_get_remaining (gst_ebml_read_br (ebml)) >= bytes_needed);
  if (G_LIKELY (!res && auto_pop)) {
    gst_ebml_read_pop_master (ebml);
  }

  return G_LIKELY (res);
}



#endif /* _H_MATROSKA_EBML_READER_H__ */
