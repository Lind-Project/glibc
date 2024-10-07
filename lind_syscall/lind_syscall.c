/* Indirect system call.  Linux generic implementation.
   Copyright (C) 1997-2024 Free Software Foundation, Inc.
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

//Entry point for wasmtime
int __imported_wasi_snapshot_preview1_lind_syscall(unsigned int callnumber, unsigned long long callname, unsigned long long arg1, unsigned long long arg2, unsigned long long arg3, unsigned long long arg4, unsigned long long arg5, unsigned long long arg6) __attribute__((
    __import_module__("lind"),
    __import_name__("lind-syscall")
));


//Part of Marco MAKE_SYSCALL, take in the number of the syscall and the name of the syscall and 6 argument.
int lind_syscall (unsigned int callnumber, unsigned long long callname, unsigned long long arg1, unsigned long long arg2, unsigned long long arg3, unsigned long long arg4, unsigned long long arg5, unsigned long long arg6)
{
  return __imported_wasi_snapshot_preview1_lind_syscall(callnumber, callname, arg1, arg2, arg3, arg4, arg5, arg6);
}