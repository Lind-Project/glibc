#include <unistd.h>

int
__fchdir (int __fd)
{
  // return 0;
  return MAKE_SYSCALL(161, "syscall|fchdir", (uint64_t) _fd, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED);
}
