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
#define BYTE_COPY_FWD(dst_bp, src_bp, nbytes)    \
  do {                                           \
    memcpy(dst_bp, src_bp, nbytes);              \
    dst_bp += nbytes;                            \
    src_bp += nbytes;                            \
  } while (0)

#undef BYTE_COPY_BWD
#define BYTE_COPY_BWD(dst_ep, src_ep, nbytes)         \
  do                                                  \
    {                                                 \
      memmove((dst_ep) - (nbytes),                    \
              (src_ep) - (nbytes),                    \
              nbytes);                                \
      dst_ep += 1;                                    \
      src_ep += 1;                                    \
    } while (0)

#undef	WORD_COPY_FWD
#define WORD_COPY_FWD(dst_bp, src_bp, nbytes_left, nbytes)            \
  do                                                                  \
    {                                                                 \
      size_t __nbytes = (nbytes);                                     \
      char *dst = (char *)(dst_bp);                                   \
      const char *src = (const char *)(src_bp);                       \
      /* Ensure the source and destination do not overlap */          \
      if (dst != src && (src + __nbytes > dst || dst + __nbytes > src))  \
      {                                                               \
        /* Copy bytes */                                              \
        for (size_t i = 0; i < __nbytes; i++)                         \
          dst[i] = src[i];                                            \
      }                                                               \
      (nbytes_left) = 0;                                              \
    } while (0)

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

