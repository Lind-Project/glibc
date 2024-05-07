#include <unistd.h>
#include <sys/syscall.h>
#include <errno.h>
#include <stdarg.h>
#include <stdio.h>

// Define NOTUSED for unused arguments
#define NOTUSED 0

// Macro for making a system call with up to six arguments
#define MAKE_SYSCALL(syscallnum, callname, arg1, arg2, arg3, arg4, arg5, arg6) \
    make_syscall(syscallnum, callname, 6, (long)(arg1), (long)(arg2), (long)(arg3), \
                 (long)(arg4), (long)(arg5), (long)(arg6))

// Generic syscall function supporting up to 6 arguments
long make_syscall(int syscall_number, const char *callname, int num_args, ...) {
    va_list args;
    va_start(args, num_args);
    long sys_args[6] = {0};  // Array to hold up to 6 syscall arguments
    
    // Populate the sys_args array with the provided arguments
    for (int i = 0; i < num_args && i < 6; i++) {
        sys_args[i] = va_arg(args, long);
    }
    va_end(args);

    // Optionally log the syscall being made
    printf("Making syscall: %s (number %d)\n", callname, syscall_number);

    // Call the syscall function with unpacked arguments
    long result = syscall(syscall_number, sys_args[0], sys_args[1], sys_args[2],
                          sys_args[3], sys_args[4], sys_args[5]);

    if (result < 0) {
        errno = -result;
        return -1;
    }

    return result;
}

