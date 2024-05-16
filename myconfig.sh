#!/bin/bash

set -e

# Since we are taking Linux glibc as a starting point we need the
# Linux kernel headers.  In the long term we will need Linux's errno
# numbers, but probably nothing more.
# rm -rf kernel-headers
mkdir kernel-headers
cp -a /usr/include/asm /usr/include/asm-generic /usr/include/linux \
     kernel-headers/

BUILDDIR=build
mkdir -p $BUILDDIR
cd $BUILDDIR
<<<<<<< Updated upstream
../configure --disable-werror --disable-profile --prefix=/home/dennis/Documents/Just-One-Turtle/glibc/target --host=i686-linux-gnu --build=i686-linux-gnu \
    CFLAGS=" -O2 -march=i686 -g" \
    CC="gcc -m32" CXX="g++ -m32" \
    CFLAGS="-O2 -march=i686" \
    CXXFLAGS="-O2 -march=i686"
#    --with-headers=`pwd`/../kernel-headers --enable-kernel=2.2.0
#    --disable-shared
=======
../configure --prefix=/home/dennis/Documents/Just-One-Turtle/glibc/target --target=wasm32-unknown-wasi --host=x86_64-linux-gnu \
    CFLAGS="--sysroot /home/dennis/Documents/Just-One-Turtle/wasi-libc/sysroot -fstrict-aliasing -O2 -g -mno-tls-direct-seg-refs" \
    CXXFLAGS="--sysroot /home/dennis/Documents/Just-One-Turtle/wasi-libc/sysroot -fstrict-aliasing -O2 -g -mno-tls-direct-seg-refs" \
    CC="/home/dennis/Documents/Just-One-Turtle/clang+llvm-16.0.4-x86_64-linux-gnu-ubuntu-22.04/bin/clang" \
    CXX="/home/dennis/Documents/Just-One-Turtle/clang+llvm-16.0.4-x86_64-linux-gnu-ubuntu-22.04/bin/clang++" \
    --with-headers=`pwd`/../kernel-headers --enable-kernel=2.2.0 \
    --disable-shared
>>>>>>> Stashed changes
