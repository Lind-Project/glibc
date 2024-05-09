#include <sys/syscall.h>
#include <stdint.h> // For uint64_t
#include <unistd.h>

// Define NOTUSED for unused arguments
#define NOTUSED 0xdeadbeefdeadbeefULL

#define MAKE_SYSCALL(syscallnum, callname, arg1, arg2, arg3, arg4, arg5, arg6) \
    syscall(syscallnum, (uint64_t)(arg1), (uint64_t)(arg2), (uint64_t)(arg3), \
                 (uint64_t)(arg4), (uint64_t)(arg5), (uint64_t)(arg6))


