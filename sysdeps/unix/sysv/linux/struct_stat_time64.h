/* Struct stat with 64-bit time support.
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
   License along with the GNU C Library; if not, see
   <https://www.gnu.org/licenses/>.  */

#ifndef _BITS_STRUCT_STAT_TIME64_H
#define _BITS_STRUCT_STAT_TIME64_H 1

#if __TIMESIZE == 64
# define __stat64_t64 stat64
#else
# include <struct___timespec64.h>

// struct __stat64_t64
//   {
// # define __struct_timespec struct __timespec64
// # include <bits/struct_stat_time64_helper.h>
//   };
// Qianxi Edit: keep all stat struct same
struct __stat64_t64
  {
    __dev_t st_dev;		/* Device.  */
    __ino_t st_ino;		/* File serial number.	*/
    int __padding;
    
    __mode_t st_mode;			/* File mode.  */
    __nlink_t st_nlink;			/* Link count.  */

    __uid_t st_uid;		/* User ID of the file's owner.	*/
    __gid_t st_gid;		/* Group ID of the file's group.*/

    __dev_t st_rdev;		/* Device number, if device.  */
    
    __off64_t st_size;			/* Size of file, in bytes.  */

    __blksize_t st_blksize;	/* Optimal block size for I/O.  */

    __blkcnt_t st_blocks;		/* Number 512-byte blocks allocated. */
    
    /* Nanosecond resolution timestamps are stored in a format
       equivalent to 'struct timespec'.  This is the type used
       whenever possible but the Unix namespace rules do not allow the
       identifier 'timespec' to appear in the <sys/stat.h> header.
       Therefore we have to handle the use of this header in strictly
       standard-compliant sources special.  */
    struct timespec st_atim;		/* Time of last access.  */
    struct timespec st_mtim;		/* Time of last modification.  */
    struct timespec st_ctim;		/* Time of last status change.  */
  };

#endif /* __TIMESIZE == 64  */

#endif /* _BITS_STRUCT_STAT_TIME64_H  */
