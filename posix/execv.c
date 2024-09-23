/* Copyright (C) 1991-2024 Free Software Foundation, Inc.
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

#include <unistd.h>
#include <syscall-template.h>

// __int32_t __imported_wasi_execv() __attribute__((
//     __import_module__("wasix"),
//     __import_name__("lind-execv")
// ));

// __int32_t __wasi_execv(const char *path, char *const argv[]) {
//     return __imported_wasi_execv((__uint64_t) path, (__uint64_t) argv);
// }

/* Execute PATH with arguments ARGV and environment from `environ'.  */
int
execv (const char *path, char *const argv[])
{
  return MAKE_SYSCALL(69, "syscall|execv", (uint64_t)path, (uint64_t)argv, NOTUSED, NOTUSED, NOTUSED, NOTUSED);
  // return __wasi_execv(path, argv);
  // return __execve (path, argv, __environ);
}
