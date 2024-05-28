#!/bin/bash

# Define the source directory for object files (change ./build to your desired path)
src_dir="./build"

# Define paths for copying additional resources
include_source_dir="/sysroot-coulson/include"
crt1_source_path="/lind-glibc/replace-sysroot/replace/sysroot/lib/wasm32-wasi/crt1.o"

# Define the output archive and sysroot directory
output_archive="sysroot/lib/wasm32-wasi/libc.a"
sysroot_dir="sysroot"

# First, remove the existing sysroot directory to start cleanly
rm -rf "$sysroot_dir"

# Find all .o files recursively in the source directory, ignoring stamp.o
object_files=$(find "$src_dir" -type f -name "*.o" ! -name "stamp.o")

# Check if object files were found
if [ -z "$object_files" ]; then
  echo "No suitable .o files found in '$src_dir'."
  exit 1
fi

# Create the sysroot directory structure
mkdir -p "$sysroot_dir/include/wasm32-wasi" "$sysroot_dir/lib/wasm32-wasi"

# Pack all found .o files into a single .a archive
/wasi-sdk/build/wasi-sdk-22.0/bin/llvm-ar rcs "$output_archive" $object_files

# Check if llvm-ar succeeded
if [ $? -eq 0 ]; then
  echo "Successfully created $output_archive with the following .o files:"
  echo "$object_files"
else
  echo "Failed to create the archive."
  exit 1
fi

# Copy all files from the external include directory to the new sysroot include directory
cp -r "$include_source_dir"/* "$sysroot_dir/include/wasm32-wasi/"

# Copy the crt1.o file into the new sysroot lib directory
cp "$crt1_source_path" "$sysroot_dir/lib/wasm32-wasi/"
