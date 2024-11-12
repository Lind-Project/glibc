/* Linux read syscall implementation.
   Copyright (C) 2017-2024 Free Software Foundation, Inc.
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
#include <sysdep-cancel.h>
#include <syscall-template.h>
#include <stdio.h>
#include <errno.h>

int __imported_wasi_snapshot_preview1_lind_syscall(unsigned int callnumber, unsigned long long callname, unsigned long long arg1, unsigned long long arg2, unsigned long long arg3, unsigned long long arg4, unsigned long long arg5, unsigned long long arg6) __attribute__((
    __import_module__("lind"),
    __import_name__("lind-syscall")
));

/* Read NBYTES into BUF from FD.  Return the number read or -1.  */

// Edit: Dennis
ssize_t
__libc_read (int fd, void *buf, size_t nbytes)
{
  printf("__libc_read\n");
  // return MAKE_SYSCALL(12, "syscall|read", (uint64_t) fd, (uint64_t)(uintptr_t) buf, (uint64_t) nbytes, NOTUSED, NOTUSED, NOTUSED);

  printf("calling read on __imported_wasi_snapshot_preview1_lind_syscall\n");
  fflush(stdout);
  int ret = __imported_wasi_snapshot_preview1_lind_syscall(12, 0, (unsigned int) fd, (unsigned int)(uintptr_t)buf, (unsigned int) nbytes, 0, 0, 0);
  printf("done, ret=%d\n", ret);
  fflush(stdout);
  if(ret < 0)
  {
    errno = -ret;
    return -1;
  }
  else
  {
    errno = 0;
  }
  return ret;

  //return SYSCALL_CANCEL (read, fd, buf, nbytes);
}
libc_hidden_def (__libc_read)

libc_hidden_def (__read)
weak_alias (__libc_read, __read)
libc_hidden_def (read)
weak_alias (__libc_read, read)
