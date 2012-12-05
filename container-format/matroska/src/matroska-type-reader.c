/* 
 * (c) 2012
 *
 */

 
/* matroska byte reader
 *
 */
#undef G_LOG_DOMAIN
#define G_LOG_DOMAIN "matroska-type-reader"

#define TYPE_READER_DISABLE_INLINES
#include "matroska-type-reader.h"

#include <string.h>

/**
 * SECTION:typereader
 * @short_description: Reads different integer, string and floating point
 *     types from a memory buffer
 *
 * #TypeReader provides a byte reader that can read different integer and
 * floating point types from a memory buffer. It provides functions for reading
 * signed/unsigned, little/big endian integers of 8, 16, 24, 32 and 64 bits
 * and functions for reading little/big endian floating points numbers of
 * 32 and 64 bits. It also provides functions to read NUL-terminated strings
 * in various character encodings.
 */

/**
 * type_reader_new:
 * @data: (in) (transfer none) (array length=size): data from which the
 *     #TypeReader should read
 * @size: Size of @data in bytes
 *
 * Create a new #TypeReader instance, which will read from @data.
 *
 * Free-function: type_reader_free
 *
 * Returns: (transfer full): a new #TypeReader instance
 *
 * Since: 0.10.22
 */
TypeReader *
type_reader_new (const guint8 * data, guint size)
{
  ENTER_FUNC
  TypeReader *ret = g_slice_new0 (TypeReader);

  ret->data = data;
  ret->size = size;
  
  LEAVE_FUNC
  return ret;
}

/**
 * type_reader_free:
 * @reader: (in) (transfer full): a #TypeReader instance
 *
 * Frees a #TypeReader instance, which was previously allocated by
 * type_reader_new() or type_reader_new_from_buffer().
 * 
 * Since: 0.10.22
 */
void
type_reader_free (TypeReader * reader)
{
  ENTER_FUNC
  g_return_if_fail (reader != NULL);

  g_slice_free (TypeReader, reader);
}

/**
 * type_reader_init:
 * @reader: a #TypeReader instance
 * @data: (in) (transfer none) (array length=size): data from which
 *     the #TypeReader should read
 * @size: Size of @data in bytes
 *
 * Initializes a #TypeReader instance to read from @data. This function
 * can be called on already initialized instances.
 * 
 * Since: 0.10.22
 */
void
type_reader_init (TypeReader * reader, const guint8 * data, guint size)
{
  ENTER_FUNC
  g_return_if_fail (reader != NULL);

  reader->data = data;
  reader->size = size;
  reader->byte = 0;
}

/**
 * type_reader_set_pos:
 * @reader: a #TypeReader instance
 * @pos: The new position in bytes
 *
 * Sets the new position of a #TypeReader instance to @pos in bytes.
 *
 * Returns: %TRUE if the position could be set successfully, %FALSE
 * otherwise.
 * 
 * Since: 0.10.22
 */
gboolean
type_reader_set_pos (TypeReader * reader, guint pos)
{
  ENTER_FUNC
  g_return_val_if_fail (reader != NULL, FALSE);

  if (pos > reader->size)
    return FALSE;

  reader->byte = pos;

  return TRUE;
}

/**
 * type_reader_get_pos:
 * @reader: a #TypeReader instance
 *
 * Returns the current position of a #TypeReader instance in bytes.
 *
 * Returns: The current position of @reader in bytes.
 * 
 * Since: 0.10.22
 */
guint
type_reader_get_pos (const TypeReader * reader)
{
  ENTER_FUNC
  return _type_reader_get_pos_inline (reader);
}

/**
 * type_reader_get_remaining:
 * @reader: a #TypeReader instance
 *
 * Returns the remaining number of bytes of a #TypeReader instance.
 *
 * Returns: The remaining number of bytes of @reader instance.
 * 
 * Since: 0.10.22
 */
guint
type_reader_get_remaining (const TypeReader * reader)
{
  ENTER_FUNC
  return _type_reader_get_remaining_inline (reader);
}

/**
 * type_reader_get_size:
 * @reader: a #TypeReader instance
 *
 * Returns the total number of bytes of a #TypeReader instance.
 *
 * Returns: The total number of bytes of @reader instance.
 * 
 * Since: 0.10.26
 */
guint
type_reader_get_size (const TypeReader * reader)
{
  ENTER_FUNC
  return _type_reader_get_size_inline (reader);
}

#define type_reader_get_remaining _type_reader_get_remaining_inline
#define type_reader_get_size _type_reader_get_size_inline

/**
 * type_reader_skip:
 * @reader: a #TypeReader instance
 * @nbytes: the number of bytes to skip
 *
 * Skips @nbytes bytes of the #TypeReader instance.
 *
 * Returns: %TRUE if @nbytes bytes could be skipped, %FALSE otherwise.
 * 
 * Since: 0.10.22
 */
gboolean
type_reader_skip (TypeReader * reader, guint nbytes)
{
  ENTER_FUNC
  return _type_reader_skip_inline (reader, nbytes);
}


#define TYPE_READER_PEEK_GET(bits,type,name) \
gboolean \
type_reader_get_##name (TypeReader * reader, type * val) \
{ \
  ENTER_FUNC	\
  return _type_reader_get_##name##_inline (reader, val); \
} \
\
gboolean \
type_reader_peek_##name (const TypeReader * reader, type * val) \
{ \
  ENTER_FUNC	\
  return _type_reader_peek_##name##_inline (reader, val); \
}

/* *INDENT-OFF* */

TYPE_READER_PEEK_GET(8,guint8,uint8)
TYPE_READER_PEEK_GET(8,gint8,int8)

TYPE_READER_PEEK_GET(16,guint16,uint16_le)
TYPE_READER_PEEK_GET(16,guint16,uint16_be)
TYPE_READER_PEEK_GET(16,gint16,int16_le)
TYPE_READER_PEEK_GET(16,gint16,int16_be)

TYPE_READER_PEEK_GET(24,guint32,uint24_le)
TYPE_READER_PEEK_GET(24,guint32,uint24_be)
TYPE_READER_PEEK_GET(24,gint32,int24_le)
TYPE_READER_PEEK_GET(24,gint32,int24_be)

TYPE_READER_PEEK_GET(32,guint32,uint32_le)
TYPE_READER_PEEK_GET(32,guint32,uint32_be)
TYPE_READER_PEEK_GET(32,gint32,int32_le)
TYPE_READER_PEEK_GET(32,gint32,int32_be)

TYPE_READER_PEEK_GET(64,guint64,uint64_le)
TYPE_READER_PEEK_GET(64,guint64,uint64_be)
TYPE_READER_PEEK_GET(64,gint64,int64_le)
TYPE_READER_PEEK_GET(64,gint64,int64_be)



TYPE_READER_PEEK_GET(32,gfloat,float32_le)
TYPE_READER_PEEK_GET(32,gfloat,float32_be)
TYPE_READER_PEEK_GET(64,gdouble,float64_le)
TYPE_READER_PEEK_GET(64,gdouble,float64_be)

/* *INDENT-ON* */

/**
 * type_reader_get_data:
 * @reader: a #TypeReader instance
 * @size: Size in bytes
 * @val: (out) (transfer none) (array length=size): address of a
 *     #guint8 pointer variable in which to store the result
 *
 * Returns a constant pointer to the current data
 * position if at least @size bytes are left and
 * updates the current position.
 *
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 * 
 * Since: 0.10.22
 */
gboolean
type_reader_get_data (TypeReader * reader, guint size,
    const guint8 ** val)
{
  ENTER_FUNC
  return _type_reader_get_data_inline (reader, size, val);
}

/**
 * type_reader_peek_data:
 * @reader: a #TypeReader instance
 * @size: Size in bytes
 * @val: (out) (transfer none) (array length=size): address of a
 *     #guint8 pointer variable in which to store the result
 *
 * Returns a constant pointer to the current data
 * position if at least @size bytes are left and
 * keeps the current position.
 *
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 * 
 * Since: 0.10.22
 */
gboolean
type_reader_peek_data (const TypeReader * reader, guint size,
    const guint8 ** val)
{
  ENTER_FUNC
  return _type_reader_peek_data_inline (reader, size, val);
}

/**
 * type_reader_dup_data:
 * @reader: a #TypeReader instance
 * @size: Size in bytes
 * @val: (out) (transfer full) (array length=size): address of a
 *     #guint8 pointer variable in which to store the result
 *
 * Free-function: g_free
 *
 * Returns a newly-allocated copy of the current data
 * position if at least @size bytes are left and
 * updates the current position. Free with g_free() when no longer needed.
 *
 * Returns: %TRUE if successful, %FALSE otherwise.
 *
 * Since: 0.10.24
 */
gboolean
type_reader_dup_data (TypeReader * reader, guint size, guint8 ** val)
{
  ENTER_FUNC
  return _type_reader_dup_data_inline (reader, size, val);
}

/**
 * type_reader_masked_scan_uint32:
 * @reader: a #TypeReader
 * @mask: mask to apply to data before matching against @pattern
 * @pattern: pattern to match (after mask is applied)
 * @offset: offset from which to start scanning, relative to the current
 *     position
 * @size: number of bytes to scan from offset
 *
 * Scan for pattern @pattern with applied mask @mask in the byte reader data,
 * starting from offset @offset relative to the current position.
 *
 * The bytes in @pattern and @mask are interpreted left-to-right, regardless
 * of endianness.  All four bytes of the pattern must be present in the
 * byte reader data for it to match, even if the first or last bytes are masked
 * out.
 *
 * It is an error to call this function without making sure that there is
 * enough data (offset+size bytes) in the byte reader.
 *
 * Returns: offset of the first match, or -1 if no match was found.
 *
 * Example:
 * <programlisting>
 * // Assume the reader contains 0x00 0x01 0x02 ... 0xfe 0xff
 *
 * type_reader_masked_scan_uint32 (reader, 0xffffffff, 0x00010203, 0, 256);
 * // -> returns 0
 * type_reader_masked_scan_uint32 (reader, 0xffffffff, 0x00010203, 1, 255);
 * // -> returns -1
 * type_reader_masked_scan_uint32 (reader, 0xffffffff, 0x01020304, 1, 255);
 * // -> returns 1
 * type_reader_masked_scan_uint32 (reader, 0xffff, 0x0001, 0, 256);
 * // -> returns -1
 * type_reader_masked_scan_uint32 (reader, 0xffff, 0x0203, 0, 256);
 * // -> returns 0
 * type_reader_masked_scan_uint32 (reader, 0xffff0000, 0x02030000, 0, 256);
 * // -> returns 2
 * type_reader_masked_scan_uint32 (reader, 0xffff0000, 0x02030000, 0, 4);
 * // -> returns -1
 * </programlisting>
 *
 * Since: 0.10.24
 */
guint
type_reader_masked_scan_uint32 (const TypeReader * reader, guint32 mask,
    guint32 pattern, guint offset, guint size)
{
  const guint8 *data;
  guint32 state;
  guint i;

  ENTER_FUNC
  g_return_val_if_fail (size > 0, -1);
  g_return_val_if_fail ((guint64) offset + size <= reader->size - reader->byte,
      -1);

  /* we can't find the pattern with less than 4 bytes */
  if (G_UNLIKELY (size < 4))
    return -1;

  data = reader->data + reader->byte + offset;

  /* set the state to something that does not match */
  state = ~pattern;

  /* now find data */
  for (i = 0; i < size; i++) {
    /* throw away one byte and move in the next byte */
    state = ((state << 8) | data[i]);
    if (G_UNLIKELY ((state & mask) == pattern)) {
      /* we have a match but we need to have skipped at
       * least 4 bytes to fill the state. */
      if (G_LIKELY (i >= 3))
        return offset + i - 3;
    }
  }

  /* nothing found */
  return -1;
}

#define TYPE_READER_SCAN_STRING(bits) \
static guint \
type_reader_scan_string_utf##bits (const TypeReader * reader) \
{ \
  guint len, off, max_len; \
  \
  ENTER_FUNC	\
  max_len = (reader->size - reader->byte) / sizeof (guint##bits); \
  \
  /* need at least a single NUL terminator */ \
  if (max_len < 1) \
    return 0; \
  \
  len = 0; \
  off = reader->byte; \
  /* endianness does not matter if we are looking for a NUL terminator */ \
  while (TYPE_READ_UINT##bits##_LE (&reader->data[off]) != 0) { \
    ++len; \
    off += sizeof (guint##bits); \
    /* have we reached the end without finding a NUL terminator? */ \
    if (len == max_len) \
      return 0; \
  } \
  /* return size in bytes including the NUL terminator (hence the +1) */ \
  return (len + 1) * sizeof (guint##bits); \
}

#define TYPE_READ_UINT8_LE TYPE_READ_UINT8
TYPE_READER_SCAN_STRING (8);
#undef TYPE_READ_UINT8_LE
TYPE_READER_SCAN_STRING (16);
TYPE_READER_SCAN_STRING (32);

#define TYPE_READER_SKIP_DUP_GET_PEEK_STRING(bits, type) \
gboolean \
type_reader_skip_string_utf##bits (TypeReader * reader) \
{ \
  guint size; /* size in bytes including the terminator */ \
  \
  ENTER_FUNC	\
  g_return_val_if_fail (reader != NULL, FALSE); \
  \
  size = type_reader_scan_string_utf##bits (reader); \
  reader->byte += size; \
  return (size > 0); \
}	\
\
gboolean \
type_reader_dup_string_utf##bits (TypeReader * reader, type ** str) \
{ \
  guint size; /* size in bytes including the terminator */ \
  \
  ENTER_FUNC	\
  g_return_val_if_fail (reader != NULL, FALSE); \
  g_return_val_if_fail (str != NULL, FALSE); \
  \
  size = type_reader_scan_string_utf##bits (reader); \
  if (size == 0) { \
    *str = NULL; \
    return FALSE; \
  } \
  *str = ( type *) g_memdup (reader->data + reader->byte, size); \
  reader->byte += size; \
  return TRUE; \
}	\
\
gboolean \
type_reader_get_string_utf##bits (TypeReader * reader, type ** str) \
{ \
  guint size; /* size in bytes including the terminator */ \
  \
  ENTER_FUNC	\
  g_return_val_if_fail (reader != NULL, FALSE); \
  g_return_val_if_fail (str != NULL, FALSE); \
  \
  size = type_reader_scan_string_utf##bits (reader); \
  if (size == 0) { \
    *str = NULL; \
    return FALSE; \
  } \
  *str = (const type *) (reader->data + reader->byte); \
  reader->byte += size; \
  return TRUE; \
}	\
\
gboolean \
type_reader_peek_string_utf##bits (TypeReader * reader, type ** str) \
{ \
  guint size; /* size in bytes including the terminator */ \
  \
  ENTER_FUNC	\
  g_return_val_if_fail (reader != NULL, FALSE); \
  g_return_val_if_fail (str != NULL, FALSE); \
  \
  size = type_reader_scan_string_utf##bits (reader); \
  if (size == 0) { \
    *str = NULL; \
    return FALSE; \
  } \
  *str = (const type *) (reader->data + reader->byte); \
  return TRUE; \
}


/**
 * type_reader_skip_string:
 * @reader: a #TypeReader instance
 *
 * Skips a NUL-terminated string in the #TypeReader instance, advancing
 * the current position to the byte after the string. This will work for
 * any NUL-terminated string with a character width of 8 bits, so ASCII,
 * UTF-8, ISO-8859-N etc.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be skipped, %FALSE otherwise.
 */
 
/**
 * type_reader_peek_string:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer none) (array zero-terminated=1): address of a
 *     #gchar pointer varieble in which to store the result
 *
 * Returns a constant pointer to the current data position if there is
 * a NUL-terminated string in the data (this could be just a NUL terminator).
 * The current position will be maintained. This will work for any
 * NUL-terminated string with a character width of 8 bits, so ASCII,
 * UTF-8, ISO-8859-N etc.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be skipped, %FALSE otherwise.
 *
 * Since: 0.10.24
 */




/**
 * type_reader_skip_string_utf8:
 * @reader: a #TypeReader instance
 *
 * Skips a NUL-terminated string in the #TypeReader instance, advancing
 * the current position to the byte after the string. This will work for
 * any NUL-terminated string with a character width of 8 bits, so ASCII,
 * UTF-8, ISO-8859-N etc. No input checking for valid UTF-8 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be skipped, %FALSE otherwise.
 */
 
 /**
 * type_reader_dup_string_utf8:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer full) (array zero-terminated=1): address of a
 *     #gchar pointer varieble in which to store the result
 *
 * Free-function: g_free
 *
 * FIXME:Reads (copies) a NUL-terminated string in the #TypeReader instance,
 * advancing the current position to the byte after the string. This will work
 * for any NUL-terminated string with a character width of 8 bits, so ASCII,
 * UTF-8, ISO-8859-N etc. No input checking for valid UTF-8 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be read into @str, %FALSE otherwise. The
 *     string put into @str must be freed with g_free() when no longer needed.
 */

/**
 * type_reader_get_string_utf8:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer none) (array zero-terminated=1): address of a
 *     #gchar pointer varieble in which to store the result
 *
 * Returns a constant pointer to the current data position if there is
 * a NUL-terminated string in the data (this could be just a NUL terminator),
 * advancing the current position to the byte after the string. This will work
 * for any NUL-terminated string with a character width of 8 bits, so ASCII,
 * UTF-8, ISO-8859-N etc.
 *
 * No input checking for valid UTF-8 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be found, %FALSE otherwise.
 */
 
/**
 * type_reader_peek_string_utf8:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer none) (array zero-terminated=1): address of a
 *     #gchar pointer varieble in which to store the result
 *
 * Returns a constant pointer to the current data position if there is
 * a NUL-terminated string in the data (this could be just a NUL terminator).
 * The current position will be maintained. This will work for any
 * NUL-terminated string with a character width of 8 bits, so ASCII,
 * UTF-8, ISO-8859-N etc.
 *
 * No input checking for valid UTF-8 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be skipped, %FALSE otherwise.
 */
TYPE_READER_SKIP_DUP_GET_PEEK_STRING (8);


/**
 * type_reader_skip_string_utf16:
 * @reader: a #TypeReader instance
 *
 * Skips a NUL-terminated string in the #TypeReader instance, advancing
 * the current position to the byte after the string. This will work for
 * any NUL-terminated string with a character width of 16 bits, so ASCII,
 * UTF-16, ISO-8859-N etc. No input checking for valid UTF-16 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be skipped, %FALSE otherwise.
 */
 
 
/**
 * type_reader_dup_string_utf16:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer full) (array zero-terminated=1): address of a
 *     #guint16 pointer varieble in which to store the result
 *
 * Free-function: g_free
 *
 * Returns a newly-allocated copy of the current data position if there is
 * a NUL-terminated UTF-16 string in the data (this could be an empty string
 * as well), and advances the current position.
 *
 * No input checking for valid UTF-16 is done. This function is endianness
 * agnostic - you should not assume the UTF-16 characters are in host
 * endianness.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Note: there is no peek or get variant of this function to ensure correct
 * byte alignment of the UTF-16 string.
 *
 * Returns: %TRUE if a string could be read, %FALSE otherwise. The
 *     string put into @str must be freed with g_free() when no longer needed.
 */

/**
 * type_reader_get_string_utf16:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer none) (array zero-terminated=1): address of a
 *     #gchar pointer varieble in which to store the result
 *
 * Returns a constant pointer to the current data position if there is
 * a NUL-terminated string in the data (this could be just a NUL terminator),
 * advancing the current position to the byte after the string. This will work
 * for any NUL-terminated string with a character width of 16 bits, so ASCII,
 * UTF-16, ISO-8859-N etc.
 *
 * No input checking for valid UTF-16 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be found, %FALSE otherwise.
 */
 
/**
 * type_reader_peek_string_utf16:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer none) (array zero-terminated=1): address of a
 *     #gchar pointer varieble in which to store the result
 *
 * Returns a constant pointer to the current data position if there is
 * a NUL-terminated string in the data (this could be just a NUL terminator).
 * The current position will be maintained. This will work for any
 * NUL-terminated string with a character width of 16 bits, so ASCII,
 * UTF-16, ISO-8859-N etc.
 *
 * No input checking for valid UTF-16 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be skipped, %FALSE otherwise.
 */
TYPE_READER_SKIP_DUP_GET_PEEK_STRING (16);

/**
 * type_reader_skip_string_utf32:
 * type_reader_dup_string_utf32:
 * type_reader_get_string_utf32:
 * type_reader_peek_string_utf32:
 * @reader: a #TypeReader instance
 *
 * Skips a NUL-terminated UTF-32 string in the #TypeReader instance,
 * advancing the current position to the byte after the string.
 *
 * No input checking for valid UTF-32 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be skipped, %FALSE otherwise.
 */
 
/**
 * type_reader_dup_string_utf32:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer full) (array zero-terminated=1): address of a
 *     #guint32 pointer varieble in which to store the result
 *
 * Free-function: g_free
 *
 * Returns a newly-allocated copy of the current data position if there is
 * a NUL-terminated UTF-32 string in the data (this could be an empty string
 * as well), and advances the current position.
 *
 * No input checking for valid UTF-32 is done. This function is endianness
 * agnostic - you should not assume the UTF-32 characters are in host
 * endianness.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Note: there is no peek or get variant of this function to ensure correct
 * byte alignment of the UTF-32 string.
 *
 * Returns: %TRUE if a string could be read, %FALSE otherwise. The
 *     string put into @str must be freed with g_free() when no longer needed.
 */

/**
 * type_reader_get_string_utf32:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer none) (array zero-terminated=1): address of a
 *     #gchar pointer varieble in which to store the result
 *
 * Returns a constant pointer to the current data position if there is
 * a NUL-terminated string in the data (this could be just a NUL terminator),
 * advancing the current position to the byte after the string. This will work
 * for any NUL-terminated string with a character width of 32 bits, so ASCII,
 * UTF-32, ISO-8859-N etc.
 *
 * No input checking for valid UTF-32 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be found, %FALSE otherwise.
 */
 
/**
 * type_reader_peek_string_utf32:
 * @reader: a #TypeReader instance
 * @str: (out) (transfer none) (array zero-terminated=1): address of a
 *     #gchar pointer varieble in which to store the result
 *
 * Returns a constant pointer to the current data position if there is
 * a NUL-terminated string in the data (this could be just a NUL terminator).
 * The current position will be maintained. This will work for any
 * NUL-terminated string with a character width of 32 bits, so ASCII,
 * UTF-32, ISO-8859-N etc.
 *
 * No input checking for valid UTF-32 is done.
 *
 * This function will fail if no NUL-terminator was found in in the data.
 *
 * Returns: %TRUE if a string could be skipped, %FALSE otherwise.
 */
TYPE_READER_SKIP_DUP_GET_PEEK_STRING (32);
