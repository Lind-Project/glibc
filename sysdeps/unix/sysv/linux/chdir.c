#include <unistd.h>

int
__chdir (const char *__path)
{
  // return 0;
  return MAKE_SYSCALL(130, "syscall|chdir", (uint64_t) __path, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED);
}

int
chdir (const char *__path)
{
  // return 0;
  return MAKE_SYSCALL(130, "syscall|chdir", (uint64_t) __path, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED);
}
