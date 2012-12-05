/* 
 * (c) 2012
 *
 */

#include "ebml-reader.h"

#define MAX_VINT_LEN  				8
#define MAX_EBML_ID_LEN  			4
#define MAX_EBML_SIZE_LEN  	MAX_VINT_LEN

#define LEN_MASK						0x80


#define GET_VINT_LEN_UNCHECKED(head_byte_ptr, len_ptr)	\
{	\
	guint8 len_mask = LEN_MASK;	\
	gint length;		\
	for ( length = 1; !( ( (guint8 *)(head_byte_ptr) )[0] & len_mask ); ( len_mask >>= 1, ++length ) );	\
	*(len_ptr) = length;	\
}

#define GET_VINT_VAL_BY_LEN_UNCHECKED(data_ptr, len, val_ptr)	\
{	\
	guint64 vint_val = 0x0;		\
	gint num;	\
	for ( num = 0; num < (len); ( ( vint_val = (vint_val << 8) | GST_READ_UINT8 ((data_ptr) + num) ), ++num ) );	\
	*(val_ptr) = vint_val;	\
}

#define GET_VINT_VAL_UNCHECKED(data_ptr, val_ptr)	\
{	\
	guint8 len_mask = LEN_MASK;	\
	gint length;		\
	guint64 vint_val = 0x0;		\
	gint num;		\
	for ( length = 1; !( ( (guint8 *)(data_ptr) )[0] & len_mask ); ( len_mask >>= 1, ++length ) );	\
	g_assert( length <= MAX_VINT_LEN );		\
	for ( num = 0; num < (length); ( ( vint_val = (vint_val << 8) | GST_READ_UINT8 ((data_ptr) + num) ), ++num ) );	\
	*(val_ptr) = vint_val;	\
}


#define GET_VINT_LEN(head_byte_ptr, len_ptr)	\
{	\
	g_assert( (head_byte_ptr) && (len_ptr) );		\
	GET_VINT_LEN_UNCHECKED(head_byte_ptr, len_ptr);	\
	g_assert( *(len_ptr) <= MAX_VINT_LEN );		\
}

#define GET_VINT_VAL_BY_LEN(data_ptr, len, val_ptr)	\
{	\
	g_assert( (data_ptr) && (val_ptr) && ((len) <= MAX_VINT_LEN) );		\
	GET_VINT_VAL_BY_LEN_UNCHECKED(data_ptr, len, val_ptr)	\
}

#define GET_VINT_VAL(data_ptr, val_ptr)	\
{	\
	g_assert( (data_ptr) && (val_ptr) );		\
	GET_VINT_VAL_UNCHECKED(data_ptr, val_ptr)	\
}


gboolean _matroska_ebml_reader_peek_element_id_and_size_unchecked (const guint8 *data,
	guint32 remained_bytes, guint32 *id, guint64 *size, guint32 *read_bytes)
{
	guint8 *ebml_offset = data;
	guint32 ebml_id = (guint32) GST_EBML_SIZE_UNKNOWN;
	guint64 ebml_size = GST_EBML_SIZE_UNKNOWN;
	guint64 ebml_read_bytes = 0;
	gint tmp_len = 0;

	/* Get ebml id */
	GET_VINT_LEN_UNCHECKED(ebml_offset, &tmp_len);
	g_assert( tmp_len <= MAX_VINT_LEN );
	if (tmp_len > MAX_EBML_ID_LEN || tmp_len > remained_bytes)
	{
		g_error("error: Invalid EBML id, the id length(%d) exceeds MAX_EBML_ID_LEN(%d) or remained_bytes(%d)! \n",
			tmp_len, MAX_EBML_ID_LEN, remained_bytes);
		return FALSE;
	}
	g_debug("EBML id length is: %d. \n", tmp_len);

	GET_VINT_VAL_BY_LEN_UNCHECKED(ebml_offset, tmp_len, &ebml_id);

	ebml_offset += tmp_len;
	remained_bytes -= tmp_len;
	ebml_read_bytes += tmp_len;
	tmp_len = 0;

	/* Get ebml size */
	GET_VINT_LEN_UNCHECKED(ebml_offset, &tmp_len);
	g_assert( tmp_len <= MAX_VINT_LEN );
	if (tmp_len > MAX_EBML_SIZE_LEN || tmp_len > remained_bytes)
	{
		g_error("error: Invalid EBML size, the size length(%d) exceeds MAX_EBML_SIZE_LEN(%d) or remained_bytes(%d)! \n",
			tmp_len, MAX_EBML_SIZE_LEN, remained_bytes);
		return FALSE;
	}
	g_debug("EBML id size is: %d. \n", tmp_len);

	GET_VINT_VAL_BY_LEN_UNCHECKED(ebml_offset, tmp_len, &ebml_size);
	ebml_read_bytes += tmp_len;

	*id = ebml_id;
	*size = ebml_size;
	*read_bytes = ebml_read_bytes;
	return TRUE;
}
/*
 * peek element id and size at given address.
 * data: 			[in]	given mem address.
 * remained_bytes:	[in]	remained_bytes in mem start from data.
 * id:   			[out]	element id to peek.
 * size: 			[out]	element data size to peek.
 * read_bytes:		[out]	total bytes of id plus size.
*/
gboolean matroska_ebml_reader_peek_element_id_and_size (const guint8 *data,
	guint32 remained_bytes, guint32 *id, guint64 *size, guint32 *read_bytes)
{
	g_return_val_if_fail (data != NULL, FALSE);
	g_return_val_if_fail (id != NULL, FALSE);
	g_return_val_if_fail (size != NULL, FALSE);
	g_return_val_if_fail (read_bytes != NULL, FALSE);
	g_return_val_if_fail (remained_bytes > 0, FALSE);

	return _matroska_ebml_reader_peek_element_id_and_size_unchecked (data, remained_bytes, id, size, read_bytes);	
}


gboolean matroska_ebml_reader_skip_element_id_and_size (const guint8 *data,
	guint32 remained_bytes)
{
	ENTER_FUNC
	guint32 id;
	guint64 size;
	guint32 read_bytes;
	g_return_val_if_fail (data != NULL, FALSE);
	g_return_val_if_fail (remained_bytes > 0, FALSE);
	
	if( !_matroska_ebml_reader_peek_element_id_and_size_unchecked (data,
		remained_bytes, &id, &size, &read_bytes) )
	{
		g_error("error: Peek element id and size failed!\n",);
		return FALSE;
	}
}


FileCache *File_cache_new(guint32 cache_size)
{
	ENTER_FUNC
	FileCache *cache = g_slice_new0(FileCache);
	type_reader_init(FILE_CACHE_CAST_READER(cache), 
		(guint8 *)g_malloc0(cache_size), cache_size);
	cache->cache_file_offset = 0;
	cache->file_path = NULL;
	LEAVE_FUNC
	return cache;
}

FileCache *File_cache_new_with_file(guint32 cache_size, gchar *file_path)
{
	ENTER_FUNC
	FileCache *cache = g_slice_new0(FileCache);
	type_reader_init(FILE_CACHE_CAST_READER(cache), 
		(guint8 *)g_malloc0(cache_size), cache_size);
	cache->cache_file_offset = 0;
	cache->file_path = g_strdup(file_path);
	LEAVE_FUNC
	return cache;
}




