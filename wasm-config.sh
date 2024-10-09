#!/bin/bash

set -e

BUILDDIR=build
mkdir -p $BUILDDIR
cd $BUILDDIR
../configure --disable-werror --disable-hidden-plt --disable-profile --with-headers=/usr/i686-linux-gnu/include --prefix=/home/lind-wasm/glibc/target --host=i686-linux-gnu --build=i686-linux-gnu\
    CFLAGS=" -matomics -mbulk-memory -O2 -g" \
    CC="/home/clang+llvm-16.0.4-x86_64-linux-gnu-ubuntu-22.04/bin/clang --target=wasm32-unkown-wasi -v -Wno-int-conversion"