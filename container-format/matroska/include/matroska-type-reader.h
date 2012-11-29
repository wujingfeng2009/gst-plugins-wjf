/* 
 * (c) 2012
 *
 */

#ifndef _H_MATROSKA_TYPE_READER_H__
#define _H_MATROSKA_TYPE_READER_H__

#include "matroska-common.h"
#include "matroska-type-rw-defs.h"
/**
 *reader:
 * @data: Data from which the bit TypeReader will read
 * @size: Size of @data in bytes
 * @byte: Current byte position
 *
 * A TypeReader instance.
 */
 
typedef struct {
  const guint8 *data;
  guint size;
  guint byte;  /* Byte position */
} TypeReader;

TypeReader * type_reader_new (const guint8 *data, guint size) G_GNUC_MALLOC;
void type_reader_free (TypeReader *reader);
void type_reader_init (TypeReader *reader, const guint8 *data, guint size);

gboolean type_reader_set_pos (TypeReader *reader, guint pos);
guint type_reader_get_pos (const TypeReader *reader);
guint type_reader_get_remaining (const TypeReader *reader);
guint type_reader_get_size (const TypeReader *reader);

gboolean type_reader_skip (TypeReader *reader, guint nbytes);

gboolean type_reader_get_uint8 (TypeReader *reader, guint8 *val);
gboolean type_reader_get_int8 (TypeReader *reader, gint8 *val);
gboolean type_reader_get_uint16_le (TypeReader *reader, guint16 *val);
gboolean type_reader_get_int16_le (TypeReader *reader, gint16 *val);
gboolean type_reader_get_uint16_be (TypeReader *reader, guint16 *val);
gboolean type_reader_get_int16_be (TypeReader *reader, gint16 *val);
gboolean type_reader_get_uint24_le (TypeReader *reader, guint32 *val);
gboolean type_reader_get_int24_le (TypeReader *reader, gint32 *val);
gboolean type_reader_get_uint24_be (TypeReader *reader, guint32 *val);
gboolean type_reader_get_int24_be (TypeReader *reader, gint32 *val);
gboolean type_reader_get_uint32_le (TypeReader *reader, guint32 *val);
gboolean type_reader_get_int32_le (TypeReader *reader, gint32 *val);
gboolean type_reader_get_uint32_be (TypeReader *reader, guint32 *val);
gboolean type_reader_get_int32_be (TypeReader *reader, gint32 *val);
gboolean type_reader_get_uint64_le (TypeReader *reader, guint64 *val);
gboolean type_reader_get_int64_le (TypeReader *reader, gint64 *val);
gboolean type_reader_get_uint64_be (TypeReader *reader, guint64 *val);
gboolean type_reader_get_int64_be (TypeReader *reader, gint64 *val);

gboolean type_reader_peek_uint8 (const TypeReader *reader, guint8 *val);
gboolean type_reader_peek_int8 (const TypeReader *reader, gint8 *val);
gboolean type_reader_peek_uint16_le (const TypeReader *reader, guint16 *val);
gboolean type_reader_peek_int16_le (const TypeReader *reader, gint16 *val);
gboolean type_reader_peek_uint16_be (const TypeReader *reader, guint16 *val);
gboolean type_reader_peek_int16_be (const TypeReader *reader, gint16 *val);
gboolean type_reader_peek_uint24_le (const TypeReader *reader, guint32 *val);
gboolean type_reader_peek_int24_le (const TypeReader *reader, gint32 *val);
gboolean type_reader_peek_uint24_be (const TypeReader *reader, guint32 *val);
gboolean type_reader_peek_int24_be (const TypeReader *reader, gint32 *val);
gboolean type_reader_peek_uint32_le (const TypeReader *reader, guint32 *val);
gboolean type_reader_peek_int32_le (const TypeReader *reader, gint32 *val);
gboolean type_reader_peek_uint32_be (const TypeReader *reader, guint32 *val);
gboolean type_reader_peek_int32_be (const TypeReader *reader, gint32 *val);
gboolean type_reader_peek_uint64_le (const TypeReader *reader, guint64 *val);
gboolean type_reader_peek_int64_le (const TypeReader *reader, gint64 *val);
gboolean type_reader_peek_uint64_be (const TypeReader *reader, guint64 *val);
gboolean type_reader_peek_int64_be (const TypeReader *reader, gint64 *val);

gboolean type_reader_get_float32_le (TypeReader *reader, gfloat *val);
gboolean type_reader_get_float32_be (TypeReader *reader, gfloat *val);
gboolean type_reader_get_float64_le (TypeReader *reader, gdouble *val);
gboolean type_reader_get_float64_be (TypeReader *reader, gdouble *val);

gboolean type_reader_peek_float32_le (const TypeReader *reader, gfloat *val);
gboolean type_reader_peek_float32_be (const TypeReader *reader, gfloat *val);
gboolean type_reader_peek_float64_le (const TypeReader *reader, gdouble *val);
gboolean type_reader_peek_float64_be (const TypeReader *reader, gdouble *val);

gboolean type_reader_dup_data  (TypeReader *reader, guint size, guint8 ** val);
gboolean type_reader_get_data  (TypeReader *reader, guint size, const guint8 ** val);
gboolean type_reader_peek_data (const TypeReader *reader, guint size, const guint8 ** val);

#define type_reader_dup_string(reader,str) \
    type_reader_dup_string_utf8(reader,str)

gboolean type_reader_dup_string_utf8  (TypeReader *reader, gchar ** str);
gboolean type_reader_dup_string_utf16 (TypeReader *reader, guint16 ** str);
gboolean type_reader_dup_string_utf32 (TypeReader *reader, guint32 ** str);

#define type_reader_skip_string(reader) \
    type_reader_skip_string_utf8(reader)

gboolean type_reader_skip_string_utf8  (TypeReader *reader);
gboolean type_reader_skip_string_utf16 (TypeReader *reader);
gboolean type_reader_skip_string_utf32 (TypeReader *reader);

#define type_reader_get_string(reader,str) \
    type_reader_get_string_utf8(reader,str)

#define type_reader_peek_string(reader,str) \
    type_reader_peek_string_utf8(reader,str)

gboolean type_reader_get_string_utf8   (TypeReader *reader, const gchar ** str);
gboolean type_reader_peek_string_utf8  (const TypeReader *reader, const gchar ** str);

guint    type_reader_masked_scan_uint32 (const TypeReader *reader,
                                             guint32               mask,
                                             guint32               pattern,
                                             guint                 offset,
                                             guint                 size);

/**
 * TYPE_READER_INIT:
 * @data: Data from which the #TypeReader should read
 * @size: Size of @data in bytes
 *
 * A #TypeReader must be initialized with this macro, before it can be
 * used. This macro can used be to initialize a variable, but it cannot
 * be assigned to a variable. In that case you have to use
 * type_reader_init().
 *
 * Since: 0.10.22
 */
#define TYPE_READER_INIT(data, size) {data, size, 0}


/* unchecked variants */
static inline void
type_reader_skip_unchecked (TypeReader *reader, guint nbytes)
{
  reader->byte += nbytes;
}

#define TYPE_READER_GET_PEEK_BITS_UNCHECKED(bits,type,lower,upper,adj) \
\
static inline type \
type_reader_peek_##lower##_unchecked (const TypeReader *reader) \
{ \
  type val = (type) TYPE_READ_##upper (reader->data + reader->byte); \
  adj \
  return val; \
} \
\
static inline type \
type_reader_get_##lower##_unchecked (TypeReader *reader) \
{ \
  type val = type_reader_peek_##lower##_unchecked (reader); \
  reader->byte += bits / 8; \
  return val; \
}

TYPE_READER_GET_PEEK_BITS_UNCHECKED(8,guint8,uint8,UINT8,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(8,gint8,int8,UINT8,/* */)

TYPE_READER_GET_PEEK_BITS_UNCHECKED(16,guint16,uint16_le,UINT16_LE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(16,guint16,uint16_be,UINT16_BE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(16,gint16,int16_le,UINT16_LE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(16,gint16,int16_be,UINT16_BE,/* */)

TYPE_READER_GET_PEEK_BITS_UNCHECKED(32,guint32,uint32_le,UINT32_LE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(32,guint32,uint32_be,UINT32_BE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(32,gint32,int32_le,UINT32_LE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(32,gint32,int32_be,UINT32_BE,/* */)

TYPE_READER_GET_PEEK_BITS_UNCHECKED(24,guint32,uint24_le,UINT24_LE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(24,guint32,uint24_be,UINT24_BE,/* */)

/* fix up the sign for 24-bit signed ints stored in 32-bit signed ints */
TYPE_READER_GET_PEEK_BITS_UNCHECKED(24,gint32,int24_le,UINT24_LE,
    if (val & 0x00800000) val |= 0xff000000;)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(24,gint32,int24_be,UINT24_BE,
    if (val & 0x00800000) val |= 0xff000000;)

TYPE_READER_GET_PEEK_BITS_UNCHECKED(64,guint64,uint64_le,UINT64_LE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(64,guint64,uint64_be,UINT64_BE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(64,gint64,int64_le,UINT64_LE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(64,gint64,int64_be,UINT64_BE,/* */)

TYPE_READER_GET_PEEK_BITS_UNCHECKED(32,gfloat,float32_le,FLOAT_LE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(32,gfloat,float32_be,FLOAT_BE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(64,gdouble,float64_le,DOUBLE_LE,/* */)
TYPE_READER_GET_PEEK_BITS_UNCHECKED(64,gdouble,float64_be,DOUBLE_BE,/* */)

#undef TYPE_READER_GET_PEEK_BITS_UNCHECKED

static inline const guint8 *
type_reader_peek_data_unchecked (const TypeReader *reader)
{
  return (const guint8 *) (reader->data + reader->byte);
}

static inline const guint8 *
type_reader_get_data_unchecked (TypeReader *reader, guint size)
{
  const guint8 *data;

  data = type_reader_peek_data_unchecked (reader);
  type_reader_skip_unchecked (reader, size);
  return data;
}

static inline guint8 *
type_reader_dup_data_unchecked (TypeReader *reader, guint size)
{
  gconstpointer data = type_reader_get_data_unchecked (reader, size);
  return (guint8 *) g_memdup (data, size);
}

/* Unchecked variants that should not be used */
static inline guint
_type_reader_get_pos_unchecked (const TypeReader *reader)
{
  return reader->byte;
}

static inline guint
_type_reader_get_remaining_unchecked (const TypeReader *reader)
{
  return reader->size - reader->byte;
}

static inline guint
_type_reader_get_size_unchecked (const TypeReader *reader)
{
  return reader->size;
}

/* inlined variants (do not use directly) */

static inline guint
_type_reader_get_remaining_inline (const TypeReader *reader)
{
  g_return_val_if_fail (reader != NULL, 0);

  return _type_reader_get_remaining_unchecked (reader);
}

static inline guint
_type_reader_get_size_inline (const TypeReader *reader)
{
  g_return_val_if_fail (reader != NULL, 0);

  return _type_reader_get_size_unchecked (reader);
}

#define TYPE_READER_GET_PEEK_BITS_INLINE(bits,type,name) \
\
static inline gboolean \
_type_reader_peek_##name##_inline (const TypeReader *reader, type * val) \
{ \
  g_return_val_if_fail (reader != NULL, FALSE); \
  g_return_val_if_fail (val != NULL, FALSE); \
  \
  if (_type_reader_get_remaining_unchecked (reader) < (bits / 8)) \
    return FALSE; \
\
  *val = type_reader_peek_##name##_unchecked (reader); \
  return TRUE; \
} \
\
static inline gboolean \
_type_reader_get_##name##_inline (TypeReader *reader, type * val) \
{ \
  g_return_val_if_fail (reader != NULL, FALSE); \
  g_return_val_if_fail (val != NULL, FALSE); \
  \
  if (_type_reader_get_remaining_unchecked (reader) < (bits / 8)) \
    return FALSE; \
\
  *val = type_reader_get_##name##_unchecked (reader); \
  return TRUE; \
}

TYPE_READER_GET_PEEK_BITS_INLINE(8,guint8,uint8)
TYPE_READER_GET_PEEK_BITS_INLINE(8,gint8,int8)

TYPE_READER_GET_PEEK_BITS_INLINE(16,guint16,uint16_le)
TYPE_READER_GET_PEEK_BITS_INLINE(16,guint16,uint16_be)
TYPE_READER_GET_PEEK_BITS_INLINE(16,gint16,int16_le)
TYPE_READER_GET_PEEK_BITS_INLINE(16,gint16,int16_be)

TYPE_READER_GET_PEEK_BITS_INLINE(32,guint32,uint32_le)
TYPE_READER_GET_PEEK_BITS_INLINE(32,guint32,uint32_be)
TYPE_READER_GET_PEEK_BITS_INLINE(32,gint32,int32_le)
TYPE_READER_GET_PEEK_BITS_INLINE(32,gint32,int32_be)

TYPE_READER_GET_PEEK_BITS_INLINE(24,guint32,uint24_le)
TYPE_READER_GET_PEEK_BITS_INLINE(24,guint32,uint24_be)
TYPE_READER_GET_PEEK_BITS_INLINE(24,gint32,int24_le)
TYPE_READER_GET_PEEK_BITS_INLINE(24,gint32,int24_be)

TYPE_READER_GET_PEEK_BITS_INLINE(64,guint64,uint64_le)
TYPE_READER_GET_PEEK_BITS_INLINE(64,guint64,uint64_be)
TYPE_READER_GET_PEEK_BITS_INLINE(64,gint64,int64_le)
TYPE_READER_GET_PEEK_BITS_INLINE(64,gint64,int64_be)

TYPE_READER_GET_PEEK_BITS_INLINE(32,gfloat,float32_le)
TYPE_READER_GET_PEEK_BITS_INLINE(32,gfloat,float32_be)
TYPE_READER_GET_PEEK_BITS_INLINE(64,gdouble,float64_le)
TYPE_READER_GET_PEEK_BITS_INLINE(64,gdouble,float64_be)

#undef TYPE_READER_GET_PEEK_BITS_INLINE

#ifndef TYPE_READER_DISABLE_INLINES

#define type_reader_get_remaining(reader) \
    _type_reader_get_remaining_inline(reader)

#define type_reader_get_size(reader) \
    _type_reader_get_size_inline(reader)

#define type_reader_get_pos(reader) \
    _type_reader_get_pos_inline(reader)

/* we use defines here so we can add the G_LIKELY() */
#define type_reader_get_uint8(reader,val) \
    G_LIKELY(_type_reader_get_uint8_inline(reader,val))
#define type_reader_get_int8(reader,val) \
    G_LIKELY(_type_reader_get_int8_inline(reader,val))
#define type_reader_get_uint16_le(reader,val) \
    G_LIKELY(_type_reader_get_uint16_le_inline(reader,val))
#define type_reader_get_int16_le(reader,val) \
    G_LIKELY(_type_reader_get_int16_le_inline(reader,val))
#define type_reader_get_uint16_be(reader,val) \
    G_LIKELY(_type_reader_get_uint16_be_inline(reader,val))
#define type_reader_get_int16_be(reader,val) \
    G_LIKELY(_type_reader_get_int16_be_inline(reader,val))
#define type_reader_get_uint24_le(reader,val) \
    G_LIKELY(_type_reader_get_uint24_le_inline(reader,val))
#define type_reader_get_int24_le(reader,val) \
    G_LIKELY(_type_reader_get_int24_le_inline(reader,val))
#define type_reader_get_uint24_be(reader,val) \
    G_LIKELY(_type_reader_get_uint24_be_inline(reader,val))
#define type_reader_get_int24_be(reader,val) \
    G_LIKELY(_type_reader_get_int24_be_inline(reader,val))
#define type_reader_get_uint32_le(reader,val) \
    G_LIKELY(_type_reader_get_uint32_le_inline(reader,val))
#define type_reader_get_int32_le(reader,val) \
    G_LIKELY(_type_reader_get_int32_le_inline(reader,val))
#define type_reader_get_uint32_be(reader,val) \
    G_LIKELY(_type_reader_get_uint32_be_inline(reader,val))
#define type_reader_get_int32_be(reader,val) \
    G_LIKELY(_type_reader_get_int32_be_inline(reader,val))
#define type_reader_get_uint64_le(reader,val) \
    G_LIKELY(_type_reader_get_uint64_le_inline(reader,val))
#define type_reader_get_int64_le(reader,val) \
    G_LIKELY(_type_reader_get_int64_le_inline(reader,val))
#define type_reader_get_uint64_be(reader,val) \
    G_LIKELY(_type_reader_get_uint64_be_inline(reader,val))
#define type_reader_get_int64_be(reader,val) \
    G_LIKELY(_type_reader_get_int64_be_inline(reader,val))

#define type_reader_peek_uint8(reader,val) \
    G_LIKELY(_type_reader_peek_uint8_inline(reader,val))
#define type_reader_peek_int8(reader,val) \
    G_LIKELY(_type_reader_peek_int8_inline(reader,val))
#define type_reader_peek_uint16_le(reader,val) \
    G_LIKELY(_type_reader_peek_uint16_le_inline(reader,val))
#define type_reader_peek_int16_le(reader,val) \
    G_LIKELY(_type_reader_peek_int16_le_inline(reader,val))
#define type_reader_peek_uint16_be(reader,val) \
    G_LIKELY(_type_reader_peek_uint16_be_inline(reader,val))
#define type_reader_peek_int16_be(reader,val) \
    G_LIKELY(_type_reader_peek_int16_be_inline(reader,val))
#define type_reader_peek_uint24_le(reader,val) \
    G_LIKELY(_type_reader_peek_uint24_le_inline(reader,val))
#define type_reader_peek_int24_le(reader,val) \
    G_LIKELY(_type_reader_peek_int24_le_inline(reader,val))
#define type_reader_peek_uint24_be(reader,val) \
    G_LIKELY(_type_reader_peek_uint24_be_inline(reader,val))
#define type_reader_peek_int24_be(reader,val) \
    G_LIKELY(_type_reader_peek_int24_be_inline(reader,val))
#define type_reader_peek_uint32_le(reader,val) \
    G_LIKELY(_type_reader_peek_uint32_le_inline(reader,val))
#define type_reader_peek_int32_le(reader,val) \
    G_LIKELY(_type_reader_peek_int32_le_inline(reader,val))
#define type_reader_peek_uint32_be(reader,val) \
    G_LIKELY(_type_reader_peek_uint32_be_inline(reader,val))
#define type_reader_peek_int32_be(reader,val) \
    G_LIKELY(_type_reader_peek_int32_be_inline(reader,val))
#define type_reader_peek_uint64_le(reader,val) \
    G_LIKELY(_type_reader_peek_uint64_le_inline(reader,val))
#define type_reader_peek_int64_le(reader,val) \
    G_LIKELY(_type_reader_peek_int64_le_inline(reader,val))
#define type_reader_peek_uint64_be(reader,val) \
    G_LIKELY(_type_reader_peek_uint64_be_inline(reader,val))
#define type_reader_peek_int64_be(reader,val) \
    G_LIKELY(_type_reader_peek_int64_be_inline(reader,val))

#define type_reader_get_float32_le(reader,val) \
    G_LIKELY(_type_reader_get_float32_le_inline(reader,val))
#define type_reader_get_float32_be(reader,val) \
    G_LIKELY(_type_reader_get_float32_be_inline(reader,val))
#define type_reader_get_float64_le(reader,val) \
    G_LIKELY(_type_reader_get_float64_le_inline(reader,val))
#define type_reader_get_float64_be(reader,val) \
    G_LIKELY(_type_reader_get_float64_be_inline(reader,val))
#define type_reader_peek_float32_le(reader,val) \
    G_LIKELY(_type_reader_peek_float32_le_inline(reader,val))
#define type_reader_peek_float32_be(reader,val) \
    G_LIKELY(_type_reader_peek_float32_be_inline(reader,val))
#define type_reader_peek_float64_le(reader,val) \
    G_LIKELY(_type_reader_peek_float64_le_inline(reader,val))
#define type_reader_peek_float64_be(reader,val) \
    G_LIKELY(_type_reader_peek_float64_be_inline(reader,val))

#endif /* TYPE_READER_DISABLE_INLINES */

static inline gboolean
_type_reader_dup_data_inline (TypeReader *reader, guint size, guint8 ** val)
{
  g_return_val_if_fail (reader != NULL, FALSE);
  g_return_val_if_fail (val != NULL, FALSE);

  if (G_UNLIKELY (size > reader->size || _type_reader_get_remaining_inline (reader) < size))
    return FALSE;

  *val = type_reader_dup_data_unchecked (reader, size);
  return TRUE;
}

static inline gboolean
_type_reader_get_data_inline (TypeReader *reader, guint size, const guint8 ** val)
{
  g_return_val_if_fail (reader != NULL, FALSE);
  g_return_val_if_fail (val != NULL, FALSE);

  if (G_UNLIKELY (size > reader->size || _type_reader_get_remaining_inline (reader) < size))
    return FALSE;

  *val = type_reader_get_data_unchecked (reader, size);
  return TRUE;
}

static inline gboolean
_type_reader_peek_data_inline (const TypeReader *reader, guint size, const guint8 ** val)
{
  g_return_val_if_fail (reader != NULL, FALSE);
  g_return_val_if_fail (val != NULL, FALSE);

  if (G_UNLIKELY (size > reader->size || _type_reader_get_remaining_inline (reader) < size))
    return FALSE;

  *val = type_reader_peek_data_unchecked (reader);
  return TRUE;
}

static inline guint
_type_reader_get_pos_inline (const TypeReader *reader)
{
  g_return_val_if_fail (reader != NULL, 0);

  return _type_reader_get_pos_unchecked (reader);
}

static inline gboolean
_type_reader_skip_inline (TypeReader *reader, guint nbytes)
{
  g_return_val_if_fail (reader != NULL, FALSE);

  if (G_UNLIKELY (_type_reader_get_remaining_unchecked (reader) < nbytes))
    return FALSE;

  reader->byte += nbytes;
  return TRUE;
}

#ifndef TYPE_READER_DISABLE_INLINES

#define type_reader_dup_data(reader,size,val) \
    G_LIKELY(_type_reader_dup_data_inline(reader,size,val))
#define type_reader_get_data(reader,size,val) \
    G_LIKELY(_type_reader_get_data_inline(reader,size,val))
#define type_reader_peek_data(reader,size,val) \
    G_LIKELY(_type_reader_peek_data_inline(reader,size,val))
#define type_reader_skip(reader,nbytes) \
    G_LIKELY(_type_reader_skip_inline(reader,nbytes))

#endif /* TYPE_READER_DISABLE_INLINES */


#endif /* _H_MATROSKA_TYPE_READER_H__ */
