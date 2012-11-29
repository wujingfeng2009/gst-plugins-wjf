/* 
 * (c) 2012
 *
 */

#include "ebml-reader.h"

#define MAX_VINT_LEN  				8
#define MAX_EBML_ID_LEN  			4
#define MAX_EBML_SIZE_LEN  	MAX_VINT_LEN

#define LEN_MASK						0x80

#define GET_VINT_LEN(head_byte_ptr, len_ptr)	\
	{	\
		guint8 len_mask = LEN_MASK;	\
		gint length;		\
		g_assert( (head_byte_ptr) && (len_ptr) );		\
		for ( length = 1; !( ( (guint8 *)(head_byte_ptr) )[0] & len_mask ); ( len_mask >>= 1, ++length ) );	\
		*(len_ptr) = length;	\
		g_assert( length <= MAX_VINT_LEN );		\
	}

#define GET_VINT_VAL_BY_LEN(data_ptr, len, val_ptr)	\
	{	\
		guint64 vint_val = 0x0;		\
		gint num;	\
		g_assert( (data_ptr) && (val_ptr) && ((len) <= MAX_VINT_LEN) );		\
		for ( num = 0; num < (len); ( ( vint_val = (vint_val << 8) | GST_READ_UINT8 ((data_ptr) + num) ), ++num ) );	\
		*(val_ptr) = vint_val;	\
	}

#define GET_VINT_VAL(data_ptr, val_ptr)	\
	{	\
		gint vint_val_len = 0;		\
		GET_VINT_LEN(data_ptr, &vint_val_len);	\
		GET_VINT_VAL_BY_LEN(data_ptr, vint_val_len, val_ptr);	\
	}

gboolean matroska_ebml_reader_get_id_and_length (const guint8 *data, guint32 *id, guint64 *size)
{
  guint8 *ebml_offset = data;
  guint32 ebml_id = (guint32) GST_EBML_SIZE_UNKNOWN;
  guint64 ebml_size = GST_EBML_SIZE_UNKNOWN;
  gint tmp_len = 0;

  g_return_val_if_fail (ebml_offset != NULL, FALSE);
  g_return_val_if_fail (id != NULL, FALSE);
  g_return_val_if_fail (size != NULL, FALSE);

  /* Get ebml id */
  GET_VINT_LEN(ebml_offset, &tmp_len);
  if (tmp_len > MAX_EBML_ID_LEN)
  {
  	g_error("error: Invalid EBML id, the id length exceeds %d! \n", MAX_EBML_ID_LEN);
	return FALSE;
  }
  g_debug("EBML id length is: %d. \n", tmp_len);
  
  GET_VINT_VAL_BY_LEN(ebml_offset, tmp_len, &ebml_id);

  ebml_offset += tmp_len;
  tmp_len = 0;
  
  /* Get ebml size */
  GET_VINT_LEN(ebml_offset, &tmp_len);
  if (tmp_len > MAX_EBML_SIZE_LEN)
  {
  	g_error("error: Invalid EBML size, the size length exceeds %d! \n", MAX_EBML_SIZE_LEN);
	return FALSE;
  }
  g_debug("EBML id size is: %d. \n", tmp_len);
  
  GET_VINT_VAL_BY_LEN(ebml_offset, tmp_len, &ebml_size);

  *id = ebml_id;
  *size = ebml_size;
  return TRUE;
}



