#include <stddef.h>  // For size_t
#include <sys/types.h>  // For other system types, if needed
#include <syscall-template.h>
#include <stdio.h>
#include <stdlib.h>

int __imported_wasi_snapshot_preview1_lind_syscall(unsigned int callnumber, unsigned long long callname, unsigned long long arg1, unsigned long long arg2, unsigned long long arg3, unsigned long long arg4, unsigned long long arg5, unsigned long long arg6) __attribute__((
    __import_module__("lind"),
    __import_name__("lind-syscall")
));


int __GI___clone3 (struct clone_args *cl_args, size_t size, int (*func)(void *), void *arg) {
  int pid = __imported_wasi_snapshot_preview1_lind_syscall(171, 0, (unsigned long long)cl_args, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED);
  // int pid = MAKE_SYSCALL(171, "syscall|clone3", (uint64_t)cl_args, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED);
  printf("clone3 returns %d\n", pid);
  fflush(stdout);
  if(pid == 0 && func != NULL) {
    int ret = func(arg);
    exit(ret);
  }
  return pid;
}
	
weak_alias (__GI___clone3, __clone3)
