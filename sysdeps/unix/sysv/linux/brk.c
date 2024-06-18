/* Change data segment.  Linux generic version.
   Copyright (C) 2020-2024 Free Software Foundation, Inc.
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
   License along with the GNU C Library.  If not, see
   <https://www.gnu.org/licenses/>.  */

#include <errno.h>
#include <unistd.h>
#include <sysdep.h>
#include <brk_call.h>

/* This must be initialized data because commons can't have aliases.  */
void *__curbrk = 0;

#if HAVE_INTERNAL_BRK_ADDR_SYMBOL
/* Old braindamage in GCC's crtstuff.c requires this symbol in an attempt
   to work around different old braindamage in the old Linux ELF dynamic
   linker.  */
weak_alias (__curbrk, ___brk_addr)
#endif

#define PAGESIZE (0x10000)

int
__brk (void *addr)
{
  // Coulnnis: we firstly try if forcing pagesize alignment is okay for glibc
  //           as __builtin_wasm_memory_grow() only support pagesize aligned increments
  __curbrk = __builtin_wasm_memroy_size(0) * PAGESIZE;
  if (addr < __curbrk || (unsigned int) addr % PAGESIZE) {
    __set_errno (EINVAL);
    return -1;
  }
  
  unsigned long grow_ret = __builtin_wasm_memory_grow(0, (unsigned long)(addr - __curbrk) / PAGESIZE);
  if (grow_ret < 0) {
    __set_errno (ENOMEM);
    return -1;
  }
  __curbrk = (void *) addr;
  return 0;
}
weak_alias (__brk, brk)
