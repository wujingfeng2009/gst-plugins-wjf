/* 
 * (c) 2012
 *
 */


#ifndef _H_MATROSKA_BYTE_DEFS_H__
#define _H_MATROSKA_BYTE_DEFS_H__

#include "matroska-common.h"

/* Define PUT and GET functions for unaligned memory */
#define TYPE_GET(__data, __idx, __size, __shift) \
    (((guint##__size) (((const guint8 *) (__data))[__idx])) << (__shift))

#define TYPE_PUT(__data, __idx, __size, __shift, __num) \
    (((guint8 *) (__data))[__idx] = (((guint##__size) (__num)) >> (__shift)) & 0xff)


/**************************************************************************************
 ********************************   Integer types  ***************************************
/**************************************************************************************/

/**
 * TYPE_READ_UINT8:
 * @data: memory location
 *
 * Read an 8 bit unsigned integer value from the memory buffer.
 */
#define TYPE_READ_UINT8(data)		(TYPE_GET (data, 0,  8,  0))

/**
 * TYPE_WRITE_UINT8:
 * @data: memory location
 * @num: value to store
 *
 * Store an 8 bit unsigned integer value into the memory buffer.
 */
#define TYPE_WRITE_UINT8(data, num)	do { \
					  TYPE_PUT (data, 0,  8,  0, num); \
					} while (0)

   
/* big-endian is a requirment for matroska file format according to matroska specification  */
#define _DATA_ENDIAN_	G_BIG_ENDIAN

#ifdef _DATA_ENDIAN_
#if _DATA_ENDIAN_ == G_BIG_ENDIAN

/**
 * TYPE_READ_UINT64_BE:
 * @data: memory location
 *
 * Read a 64 bit unsigned integer value in big endian format from the memory buffer.
 */
#define TYPE_READ_UINT64_BE(data)	(TYPE_GET (data, 0, 64, 56) | \
					 TYPE_GET (data, 1, 64, 48) | \
					 TYPE_GET (data, 2, 64, 40) | \
					 TYPE_GET (data, 3, 64, 32) | \
					 TYPE_GET (data, 4, 64, 24) | \
					 TYPE_GET (data, 5, 64, 16) | \
					 TYPE_GET (data, 6, 64,  8) | \
					 TYPE_GET (data, 7, 64,  0))

/**
 * TYPE_READ_UINT64_LE:
 * @data: memory location
 *
 * Read a 64 bit unsigned integer value in little endian format from the memory buffer.
 */
#define TYPE_READ_UINT64_LE(data)	(TYPE_GET (data, 7, 64, 56) | \
					 TYPE_GET (data, 6, 64, 48) | \
					 TYPE_GET (data, 5, 64, 40) | \
					 TYPE_GET (data, 4, 64, 32) | \
					 TYPE_GET (data, 3, 64, 24) | \
					 TYPE_GET (data, 2, 64, 16) | \
					 TYPE_GET (data, 1, 64,  8) | \
					 TYPE_GET (data, 0, 64,  0))

/**
 * TYPE_READ_UINT32_BE:
 * @data: memory location
 *
 * Read a 32 bit unsigned integer value in big endian format from the memory buffer.
 */
#define TYPE_READ_UINT32_BE(data)	(TYPE_GET (data, 0, 32, 24) | \
					 TYPE_GET (data, 1, 32, 16) | \
					 TYPE_GET (data, 2, 32,  8) | \
					 TYPE_GET (data, 3, 32,  0))

/**
 * TYPE_READ_UINT32_LE:
 * @data: memory location
 *
 * Read a 32 bit unsigned integer value in little endian format from the memory buffer.
 */
#define TYPE_READ_UINT32_LE(data)	(TYPE_GET (data, 3, 32, 24) | \
					 TYPE_GET (data, 2, 32, 16) | \
					 TYPE_GET (data, 1, 32,  8) | \
					 TYPE_GET (data, 0, 32,  0))

/**
 * TYPE_READ_UINT24_BE:
 * @data: memory location
 *
 * Read a 24 bit unsigned integer value in big endian format from the memory buffer.
 *
 * Since: 0.10.22
 */
#define TYPE_READ_UINT24_BE(data)	(TYPE_GET (data, 0, 32, 16) | \
					 TYPE_GET (data, 1, 32,  8) | \
					 TYPE_GET (data, 2, 32,  0))

/**
 * TYPE_READ_UINT24_LE:
 * @data: memory location
 *
 * Read a 24 bit unsigned integer value in little endian format from the memory buffer.
 *
 * Since: 0.10.22
 */
#define TYPE_READ_UINT24_LE(data)	(TYPE_GET (data, 2, 32, 16) | \
					 TYPE_GET (data, 1, 32,  8) | \
					 TYPE_GET (data, 0, 32,  0))

/**
 * TYPE_READ_UINT16_BE:
 * @data: memory location
 *
 * Read a 16 bit unsigned integer value in big endian format from the memory buffer.
 */
#define TYPE_READ_UINT16_BE(data)	(TYPE_GET (data, 0, 16,  8) | \
					 TYPE_GET (data, 1, 16,  0))

/**
 * TYPE_READ_UINT16_LE:
 * @data: memory location
 *
 * Read a 16 bit unsigned integer value in little endian format from the memory buffer.
 */
#define TYPE_READ_UINT16_LE(data)	(TYPE_GET (data, 1, 16,  8) | \
					 TYPE_GET (data, 0, 16,  0))
					 

/**
 * TYPE_WRITE_UINT64_BE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 64 bit unsigned integer value in big endian format into the memory buffer.
 */
#define TYPE_WRITE_UINT64_BE(data, num)	do { \
					  TYPE_PUT (data, 0, 64, 56, num); \
					  TYPE_PUT (data, 1, 64, 48, num); \
					  TYPE_PUT (data, 2, 64, 40, num); \
					  TYPE_PUT (data, 3, 64, 32, num); \
					  TYPE_PUT (data, 4, 64, 24, num); \
					  TYPE_PUT (data, 5, 64, 16, num); \
					  TYPE_PUT (data, 6, 64,  8, num); \
					  TYPE_PUT (data, 7, 64,  0, num); \
					} while (0)

/**
 * TYPE_WRITE_UINT64_LE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 64 bit unsigned integer value in little endian format into the memory buffer.
 */
#define TYPE_WRITE_UINT64_LE(data, num)	do { \
					  TYPE_PUT (data, 0, 64,  0, num); \
					  TYPE_PUT (data, 1, 64,  8, num); \
					  TYPE_PUT (data, 2, 64, 16, num); \
					  TYPE_PUT (data, 3, 64, 24, num); \
					  TYPE_PUT (data, 4, 64, 32, num); \
					  TYPE_PUT (data, 5, 64, 40, num); \
					  TYPE_PUT (data, 6, 64, 48, num); \
					  TYPE_PUT (data, 7, 64, 56, num); \
					} while (0)

/**
 * TYPE_WRITE_UINT32_BE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 32 bit unsigned integer value in big endian format into the memory buffer.
 */
#define TYPE_WRITE_UINT32_BE(data, num)	do { \
					  TYPE_PUT (data, 0, 32, 24, num); \
					  TYPE_PUT (data, 1, 32, 16, num); \
					  TYPE_PUT (data, 2, 32,  8, num); \
					  TYPE_PUT (data, 3, 32,  0, num); \
					} while (0)

/**
 * TYPE_WRITE_UINT32_LE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 32 bit unsigned integer value in little endian format into the memory buffer.
 */
#define TYPE_WRITE_UINT32_LE(data, num)	do { \
					  TYPE_PUT (data, 0, 32,  0, num); \
					  TYPE_PUT (data, 1, 32,  8, num); \
					  TYPE_PUT (data, 2, 32, 16, num); \
					  TYPE_PUT (data, 3, 32, 24, num); \
					} while (0)

/**
 * TYPE_WRITE_UINT24_BE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 24 bit unsigned integer value in big endian format into the memory buffer.
 *
 * Since: 0.10.22
 */
#define TYPE_WRITE_UINT24_BE(data, num)	do { \
					  TYPE_PUT (data, 0, 32,  16, num); \
					  TYPE_PUT (data, 1, 32,  8, num); \
					  TYPE_PUT (data, 2, 32,  0, num); \
					} while (0)

/**
 * TYPE_WRITE_UINT24_LE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 24 bit unsigned integer value in little endian format into the memory buffer.
 *
 * Since: 0.10.22
 */
#define TYPE_WRITE_UINT24_LE(data, num)	do { \
					  TYPE_PUT (data, 0, 32,  0, num); \
					  TYPE_PUT (data, 1, 32,  8, num); \
					  TYPE_PUT (data, 2, 32,  16, num); \
					} while (0)

/**
 * TYPE_WRITE_UINT16_BE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 16 bit unsigned integer value in big endian format into the memory buffer.
 */
#define TYPE_WRITE_UINT16_BE(data, num)	do { \
					  TYPE_PUT (data, 0, 16,  8, num); \
					  TYPE_PUT (data, 1, 16,  0, num); \
					} while (0)

/**
 * TYPE_WRITE_UINT16_LE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 16 bit unsigned integer value in little endian format into the memory buffer.
 */
#define TYPE_WRITE_UINT16_LE(data, num)	do { \
					  TYPE_PUT (data, 0, 16,  0, num); \
					  TYPE_PUT (data, 1, 16,  8, num); \
					} while (0)

#elif _DATA_ENDIAN_ == G_LITTLE_ENDIAN

/**
 * TYPE_READ:
 */
#define TYPE_READ_UINT64_BE(data)	(TYPE_GET (data, 7, 64, 56) | \
					 TYPE_GET (data, 6, 64, 48) | \
					 TYPE_GET (data, 5, 64, 40) | \
					 TYPE_GET (data, 4, 64, 32) | \
					 TYPE_GET (data, 3, 64, 24) | \
					 TYPE_GET (data, 2, 64, 16) | \
					 TYPE_GET (data, 1, 64,  8) | \
					 TYPE_GET (data, 0, 64,  0))

#define TYPE_READ_UINT64_LE(data)	(TYPE_GET (data, 0, 64, 56) | \
					 TYPE_GET (data, 1, 64, 48) | \
					 TYPE_GET (data, 2, 64, 40) | \
					 TYPE_GET (data, 3, 64, 32) | \
					 TYPE_GET (data, 4, 64, 24) | \
					 TYPE_GET (data, 5, 64, 16) | \
					 TYPE_GET (data, 6, 64,  8) | \
					 TYPE_GET (data, 7, 64,  0))

#define TYPE_READ_UINT32_BE(data)	(TYPE_GET (data, 3, 32, 24) | \
					 TYPE_GET (data, 2, 32, 16) | \
					 TYPE_GET (data, 1, 32,  8) | \
					 TYPE_GET (data, 0, 32,  0))

#define TYPE_READ_UINT32_LE(data)	(TYPE_GET (data, 0, 32, 24) | \
					 TYPE_GET (data, 1, 32, 16) | \
					 TYPE_GET (data, 2, 32,  8) | \
					 TYPE_GET (data, 3, 32,  0))

#define TYPE_READ_UINT24_BE(data)	(TYPE_GET (data, 2, 32, 16) | \
					 TYPE_GET (data, 1, 32,  8) | \
					 TYPE_GET (data, 0, 32,  0))

#define TYPE_READ_UINT24_LE(data)	(TYPE_GET (data, 0, 32, 16) | \
					 TYPE_GET (data, 1, 32,  8) | \
					 TYPE_GET (data, 2, 32,  0))

#define TYPE_READ_UINT16_BE(data)	(TYPE_GET (data, 1, 16,  8) | \
					 TYPE_GET (data, 0, 16,  0))

#define TYPE_READ_UINT16_LE(data)	(TYPE_GET (data, 0, 16,  8) | \
					 TYPE_GET (data, 1, 16,  0))
					 
/**
 * TYPE_WRITE:
 */
#define TYPE_WRITE_UINT64_BE(data, num)	do { \
					  TYPE_PUT (data, 0, 64,  0, num); \
					  TYPE_PUT (data, 1, 64,  8, num); \
					  TYPE_PUT (data, 2, 64, 16, num); \
					  TYPE_PUT (data, 3, 64, 24, num); \
					  TYPE_PUT (data, 4, 64, 32, num); \
					  TYPE_PUT (data, 5, 64, 40, num); \
					  TYPE_PUT (data, 6, 64, 48, num); \
					  TYPE_PUT (data, 7, 64, 56, num); \
					} while (0)

#define TYPE_WRITE_UINT64_LE(data, num)	do { \
					  TYPE_PUT (data, 0, 64, 56, num); \
					  TYPE_PUT (data, 1, 64, 48, num); \
					  TYPE_PUT (data, 2, 64, 40, num); \
					  TYPE_PUT (data, 3, 64, 32, num); \
					  TYPE_PUT (data, 4, 64, 24, num); \
					  TYPE_PUT (data, 5, 64, 16, num); \
					  TYPE_PUT (data, 6, 64,  8, num); \
					  TYPE_PUT (data, 7, 64,  0, num); \
					} while (0)

#define TYPE_WRITE_UINT32_BE(data, num)	do { \
					  TYPE_PUT (data, 0, 32,  0, num); \
					  TYPE_PUT (data, 1, 32,  8, num); \
					  TYPE_PUT (data, 2, 32, 16, num); \
					  TYPE_PUT (data, 3, 32, 24, num); \
					} while (0)

#define TYPE_WRITE_UINT32_LE(data, num)	do { \
					  TYPE_PUT (data, 0, 32, 24, num); \
					  TYPE_PUT (data, 1, 32, 16, num); \
					  TYPE_PUT (data, 2, 32,  8, num); \
					  TYPE_PUT (data, 3, 32,  0, num); \
					} while (0)
					
#define TYPE_WRITE_UINT24_BE(data, num)	do { \
					  TYPE_PUT (data, 0, 32,  0, num); \
					  TYPE_PUT (data, 1, 32,  8, num); \
					  TYPE_PUT (data, 2, 32,  16, num); \
					} while (0)
					
#define TYPE_WRITE_UINT24_LE(data, num)	do { \
					  TYPE_PUT (data, 0, 32,  16, num); \
					  TYPE_PUT (data, 1, 32,  8, num); \
					  TYPE_PUT (data, 2, 32,  0, num); \
					} while (0)
					
#define TYPE_WRITE_UINT16_BE(data, num)	do { \
					  TYPE_PUT (data, 0, 16,  0, num); \
					  TYPE_PUT (data, 1, 16,  8, num); \
					} while (0)
					
#define TYPE_WRITE_UINT16_LE(data, num)	do { \
					  TYPE_PUT (data, 0, 16,  8, num); \
					  TYPE_PUT (data, 1, 16,  0, num); \
					} while (0)

#else /* !G_LITTLE_ENDIAN && !G_BIG_ENDIAN */
#error unknown ENDIAN type
#endif 

#endif /* #ifdef _DATA_ENDIAN_ */




/**************************************************************************************
 *******************************   Floating types  ***************************************
/**************************************************************************************/


#ifdef _FOOL_GTK_DOC_
G_INLINE_FUNC gfloat TYPE_READ_FLOAT_LE (const guint8 *data);
G_INLINE_FUNC gfloat TYPE_READ_FLOAT_BE (const guint8 *data);
G_INLINE_FUNC gdouble TYPE_READ_DOUBLE_LE (const guint8 *data);
G_INLINE_FUNC gdouble TYPE_READ_DOUBLE_BE (const guint8 *data);
G_INLINE_FUNC void TYPE_WRITE_FLOAT_LE (guint8 *data, gfloat num);
G_INLINE_FUNC void TYPE_WRITE_FLOAT_BE (guint8 *data, gfloat num);
G_INLINE_FUNC void TYPE_WRITE_DOUBLE_LE (guint8 *data, gdouble num);
G_INLINE_FUNC void TYPE_WRITE_DOUBLE_BE (guint8 *data, gdouble num);
#endif


/**
 * TYPE_READ_FLOAT_LE:
 * @data: memory location
 *
 * Read a 32 bit float value in little endian format from the memory buffer.
 *
 * Returns: The floating point value read from @data
 *
 * Since: 0.10.22
 *
 */
inline static gfloat
TYPE_READ_FLOAT_LE(const guint8 *data)
{
  union
  {
    guint32 i;
    gfloat f;
  } u;

  u.i = TYPE_READ_UINT32_LE (data);
  return u.f;
}

/**
 * TYPE_READ_FLOAT_BE:
 * @data: memory location
 *
 * Read a 32 bit float value in big endian format from the memory buffer.
 *
 * Returns: The floating point value read from @data
 *
 * Since: 0.10.22
 *
 */
inline static gfloat
TYPE_READ_FLOAT_BE(const guint8 *data)
{
  union
  {
    guint32 i;
    gfloat f;
  } u;

  u.i = TYPE_READ_UINT32_BE (data);
  return u.f;
}

/**
 * TYPE_READ_DOUBLE_LE:
 * @data: memory location
 *
 * Read a 64 bit double value in little endian format from the memory buffer.
 *
 * Returns: The double-precision floating point value read from @data
 *
 * Since: 0.10.22
 *
 */
inline static gdouble
TYPE_READ_DOUBLE_LE(const guint8 *data)
{
  union
  {
    guint64 i;
    gdouble d;
  } u;

  u.i = TYPE_READ_UINT64_LE (data);
  return u.d;
}

/**
 * TYPE_READ_DOUBLE_BE:
 * @data: memory location
 *
 * Read a 64 bit double value in big endian format from the memory buffer.
 *
 * Returns: The double-precision floating point value read from @data
 *
 * Since: 0.10.22
 *
 */
inline static gdouble
TYPE_READ_DOUBLE_BE(const guint8 *data)
{
  union
  {
    guint64 i;
    gdouble d;
  } u;

  u.i = TYPE_READ_UINT64_BE (data);
  return u.d;
}

/**
 * TYPE_WRITE_FLOAT_LE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 32 bit float value in little endian format into the memory buffer.
 *
 * Since: 0.10.22
 *
 */
inline static void
TYPE_WRITE_FLOAT_LE(guint8 *data, gfloat num)
{
  union
  {
    guint32 i;
    gfloat f;
  } u;

  u.f = num;
  TYPE_WRITE_UINT32_LE (data, u.i);
}

/**
 * TYPE_WRITE_FLOAT_BE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 32 bit float value in big endian format into the memory buffer.
 *
 * Since: 0.10.22
 *
 */
inline static void
TYPE_WRITE_FLOAT_BE(guint8 *data, gfloat num)
{
  union
  {
    guint32 i;
    gfloat f;
  } u;

  u.f = num;
  TYPE_WRITE_UINT32_BE (data, u.i);
}

/**
 * TYPE_WRITE_DOUBLE_LE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 64 bit double value in little endian format into the memory buffer.
 *
 * Since: 0.10.22
 *
 */
inline static void
TYPE_WRITE_DOUBLE_LE(guint8 *data, gdouble num)
{
  union
  {
    guint64 i;
    gdouble d;
  } u;

  u.d = num;
  TYPE_WRITE_UINT64_LE (data, u.i);
}

/**
 * TYPE_WRITE_DOUBLE_BE:
 * @data: memory location
 * @num: value to store
 *
 * Store a 64 bit double value in big endian format into the memory buffer.
 *
 * Since: 0.10.22
 *
 */
inline static void
TYPE_WRITE_DOUBLE_BE(guint8 *data, gdouble num)
{
  union
  {
    guint64 i;
    gdouble d;
  } u;

  u.d = num;
  TYPE_WRITE_UINT64_BE (data, u.i);
}



/******************************  Native to/from convertion macros  ************************************/


/* FIXME: Remove this once we depend on a GLib version with this */
#ifndef GFLOAT_FROM_LE
/**
 * GFLOAT_SWAP_LE_BE:
 * @in: input value
 *
 * Swap byte order of a 32-bit floating point value (float).
 *
 * Returns: @in byte-swapped.
 *
 * Since: 0.10.22
 *
 */
#ifdef _FOOL_GTK_DOC_
G_INLINE_FUNC gfloat GFLOAT_SWAP_LE_BE (gfloat in);
G_INLINE_FUNC gdouble GDOUBLE_SWAP_LE_BE (gdouble in);
#endif

inline static gfloat
GFLOAT_SWAP_LE_BE(gfloat in)
{
  union
  {
    guint32 i;
    gfloat f;
  } u;

  u.f = in;
  u.i = GUINT32_SWAP_LE_BE (u.i);
  return u.f;
}

/**
 * GDOUBLE_SWAP_LE_BE:
 * @in: input value
 *
 * Swap byte order of a 64-bit floating point value (double).
 *
 * Returns: @in byte-swapped.
 *
 * Since: 0.10.22
 *
 */

inline static gdouble
GDOUBLE_SWAP_LE_BE(gdouble in)
{
  union
  {
    guint64 i;
    gdouble d;
  } u;

  u.d = in;
  u.i = GUINT64_SWAP_LE_BE (u.i);
  return u.d;
}

/**
 * GDOUBLE_TO_LE:
 * @val: value
 *
 * Convert 64-bit floating point value (double) from native byte order into
 * little endian byte order.
 *
 * Since: 0.10.22
 *
 */
/**
 * GDOUBLE_TO_BE:
 * @val: value
 *
 * Convert 64-bit floating point value (double) from native byte order into
 * big endian byte order.
 *
 * Since: 0.10.22
 *
 */
/**
 * GDOUBLE_FROM_LE:
 * @val: value
 *
 * Convert 64-bit floating point value (double) from little endian byte order
 * into native byte order.
 *
 * Since: 0.10.22
 *
 */
/**
 * GDOUBLE_FROM_BE:
 * @val: value
 *
 * Convert 64-bit floating point value (double) from big endian byte order
 * into native byte order.
 *
 * Since: 0.10.22
 *
 */

/**
 * GFLOAT_TO_LE:
 * @val: value
 *
 * Convert 32-bit floating point value (float) from native byte order into
 * little endian byte order.
 *
 * Since: 0.10.22
 *
 */
/**
 * GFLOAT_TO_BE:
 * @val: value
 *
 * Convert 32-bit floating point value (float) from native byte order into
 * big endian byte order.
 *
 * Since: 0.10.22
 *
 */
/**
 * GFLOAT_FROM_LE:
 * @val: value
 *
 * Convert 32-bit floating point value (float) from little endian byte order
 * into native byte order.
 *
 * Since: 0.10.22
 *
 */
/**
 * GFLOAT_FROM_BE:
 * @val: value
 *
 * Convert 32-bit floating point value (float) from big endian byte order
 * into native byte order.
 *
 * Since: 0.10.22
 *
 */

#if G_BYTE_ORDER == G_LITTLE_ENDIAN
#define GFLOAT_TO_LE(val)    ((gfloat) (val))
#define GFLOAT_TO_BE(val)    (GFLOAT_SWAP_LE_BE (val))
#define GDOUBLE_TO_LE(val)   ((gdouble) (val))
#define GDOUBLE_TO_BE(val)   (GDOUBLE_SWAP_LE_BE (val))

#elif G_BYTE_ORDER == G_BIG_ENDIAN
#define GFLOAT_TO_LE(val)    (GFLOAT_SWAP_LE_BE (val))
#define GFLOAT_TO_BE(val)    ((gfloat) (val))
#define GDOUBLE_TO_LE(val)   (GDOUBLE_SWAP_LE_BE (val))
#define GDOUBLE_TO_BE(val)   ((gdouble) (val))

#else /* !G_LITTLE_ENDIAN && !G_BIG_ENDIAN */
#error unknown ENDIAN type
#endif /* !G_LITTLE_ENDIAN && !G_BIG_ENDIAN */

#define GFLOAT_FROM_LE(val)  (GFLOAT_TO_LE (val))
#define GFLOAT_FROM_BE(val)  (GFLOAT_TO_BE (val))
#define GDOUBLE_FROM_LE(val) (GDOUBLE_TO_LE (val))
#define GDOUBLE_FROM_BE(val) (GDOUBLE_TO_BE (val))

#endif /* !defined(GFLOAT_FROM_LE) */



/********************************  Miscellaneous utility macros ***************************************/

/**
 * TYPE_ROUND_UP_2:
 * @num: integer value to round up
 *
 * Rounds an integer value up to the next multiple of 2.
 */
#define TYPE_ROUND_UP_2(num)  (((num)+1)&~1)
/**
 * TYPE_ROUND_UP_4:
 * @num: integer value to round up
 *
 * Rounds an integer value up to the next multiple of 4.
 */
#define TYPE_ROUND_UP_4(num)  (((num)+3)&~3)
/**
 * TYPE_ROUND_UP_8:
 * @num: integer value to round up
 *
 * Rounds an integer value up to the next multiple of 8.
 */
#define TYPE_ROUND_UP_8(num)  (((num)+7)&~7)
/**
 * TYPE_ROUND_UP_16:
 * @num: integer value to round up
 *
 * Rounds an integer value up to the next multiple of 16.
 */
#define TYPE_ROUND_UP_16(num) (((num)+15)&~15)
/**
 * TYPE_ROUND_UP_32:
 * @num: integer value to round up
 *
 * Rounds an integer value up to the next multiple of 32.
 */
#define TYPE_ROUND_UP_32(num) (((num)+31)&~31)
/**
 * TYPE_ROUND_UP_64:
 * @num: integer value to round up
 *
 * Rounds an integer value up to the next multiple of 64.
 */
#define TYPE_ROUND_UP_64(num) (((num)+63)&~63)

/**
 * TYPE_ROUND_DOWN_2:
 * @num: integer value to round down
 *
 * Rounds an integer value down to the next multiple of 2.
 *
 * Since: 0.10.12
 */
#define TYPE_ROUND_DOWN_2(num)  ((num)&(~1))
/**
 * TYPE_ROUND_DOWN_4:
 * @num: integer value to round down
 *
 * Rounds an integer value down to the next multiple of 4.
 *
 * Since: 0.10.12
 */
#define TYPE_ROUND_DOWN_4(num)  ((num)&(~3))
/**
 * TYPE_ROUND_DOWN_8:
 * @num: integer value to round down
 *
 * Rounds an integer value down to the next multiple of 8.
 *
 * Since: 0.10.12
 */
#define TYPE_ROUND_DOWN_8(num)  ((num)&(~7))
/**
 * TYPE_ROUND_DOWN_16:
 * @num: integer value to round down
 *
 * Rounds an integer value down to the next multiple of 16.
 *
 * Since: 0.10.12
 */
#define TYPE_ROUND_DOWN_16(num) ((num)&(~15))
/**
 * TYPE_ROUND_DOWN_32:
 * @num: integer value to round down
 *
 * Rounds an integer value down to the next multiple of 32.
 *
 * Since: 0.10.12
 */
#define TYPE_ROUND_DOWN_32(num) ((num)&(~31))


#endif

