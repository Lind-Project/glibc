#include <stddef.h>  // For size_t
#include <sys/types.h>  // For other system types, if needed
#include <syscall-template.h>
#include "libioP.h"

// // Define the clone_args structure if it's not already defined
// struct clone_args {
//     __aligned_u64 flags;           // Flags that control the behavior of the child process
//     __aligned_u64 pidfd;           // File descriptor to receive the child's PID
//     __aligned_u64 child_tid;       // Pointer to a memory location where the child TID will be stored
//     __aligned_u64 parent_tid;      // Pointer to a memory location where the parent's TID will be stored
//     __aligned_u64 exit_signal;     // Signal to be sent when the child process exits
//     __aligned_u64 stack;           // Address of the stack for the child process
//     __aligned_u64 stack_size;      // Size of the stack for the child process
//     __aligned_u64 tls;             // Thread-Local Storage (TLS) descriptor for the child thread
//     __aligned_u64 set_tid;         // Pointer to an array of TIDs to be set in the child
//     __aligned_u64 set_tid_size;    // Number of TIDs in the `set_tid` array
//     __aligned_u64 cgroup;          // File descriptor for the cgroup to which the child process should be attached
// };

// 

int __GI___clone3 (struct clone_args *cl_args, size_t size, int (*func)(void *), void *arg) {
  int pid = MAKE_SYSCALL(171, "syscall|clone3", (uint64_t)cl_args, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED);
  if(pid == 0 && func != NULL) {
    int ret = func(arg);
    exit(ret);
  }
  return pid;
}
	
weak_alias (__GI___clone3, __clone3)
