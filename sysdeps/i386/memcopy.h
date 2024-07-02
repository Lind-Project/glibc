/* memcopy.h -- definitions for memory copy functions.  i386 version.
   Copyright (C) 1991-2024 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#include <sysdeps/generic/memcopy.h>
#include <string.h>  // For memcpy

#undef BYTE_COPY_FWD
#define BYTE_COPY_FWD(dst_bp, src_bp, nbytes)				      \
  do									      \
    {									      \
      size_t __nbytes = (nbytes);					      \
      if (__nbytes & 1)							      \
        {								      \
	  ((byte *) dst_bp)[0] =  ((byte *) src_bp)[0];			      \
	  src_bp += 1;							      \
	  dst_bp += 1;							      \
	  __nbytes -= 1;						      \
        }								      \
      while (__nbytes > 0)						      \
	{								      \
	  byte __x = ((byte *) src_bp)[0];				      \
	  byte __y = ((byte *) src_bp)[1];				      \
	  src_bp += 2;							      \
	  __nbytes -= 2;						      \
	  ((byte *) dst_bp)[0] = __x;					      \
	  ((byte *) dst_bp)[1] = __y;					      \
	  dst_bp += 2;							      \
	}								      \
    } while (0)

/* Copy exactly NBYTES_TO_COPY bytes from SRC_END_PTR to DST_END_PTR,
   beginning at the bytes right before the pointers and continuing towards
   smaller addresses.  Don't assume anything about alignment of the
   pointers.  */
#undef BYTE_COPY_BWD
#define BYTE_COPY_BWD(dst_ep, src_ep, nbytes)				      \
  do									      \
    {									      \
      size_t __nbytes = (nbytes);					      \
      if (__nbytes & 1)							      \
        {								      \
	  src_ep -= 1;							      \
	  dst_ep -= 1;							      \
	  ((byte *) dst_ep)[0] =  ((byte *) src_ep)[0];			      \
	  __nbytes -= 1;						      \
        }								      \
      while (__nbytes > 0)						      \
	{								      \
	  byte __x, __y;						      \
	  src_ep -= 2;							      \
	  __y = ((byte *) src_ep)[1];					      \
	  __x = ((byte *) src_ep)[0];					      \
	  dst_ep -= 2;							      \
	  __nbytes -= 2;						      \
	  ((byte *) dst_ep)[1] = __y;					      \
	  ((byte *) dst_ep)[0] = __x;					      \
	}								      \
    } while (0)

/* The powerpc memcpy implementation is safe to use for memmove.  */
#undef MEMCPY_OK_FOR_FWD_MEMMOVE
#define MEMCPY_OK_FOR_FWD_MEMMOVE 1

#undef	WORD_COPY_BWD
#define WORD_COPY_BWD(dst_ep, src_ep, nbytes_left, nbytes)          \
  do                                                                \
    {                                                               \
      size_t __nbytes = (nbytes);                                   \
      char *dst = (char *)(dst_ep);                                 \
      const char *src = (const char *)(src_ep);                     \
      /* Copy bytes backward from the end */                        \
      for (size_t i = 0; i < __nbytes; ++i)                         \
        dst[__nbytes - 1 - i] = src[__nbytes - 1 - i];              \
      (nbytes_left) = 0;                                            \
    } while (0)

