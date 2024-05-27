#!/bin/bash

# Define the source directory for object files (change ./ to your desired path)
src_dir="./build"

# Define the output archive and sysroot directory
output_archive="sysroot/lib/wasm32-wasi/libc.a"
sysroot_dir="sysroot"

# Find all .o files recursively in the source directory
object_files=$(find "$src_dir" -type f -name "*.o")

# Check if object files were found
if [ -z "$object_files" ]; then
  echo "No .o files found in '$src_dir'."
  exit 1
fi

# Create the sysroot directory structure if it doesn't exist
if [ ! -d "$sysroot_dir" ]; then
  mkdir -p "$sysroot_dir/include/wasm32-wasi" "$sysroot_dir/lib/wasm32-wasi"
fi

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