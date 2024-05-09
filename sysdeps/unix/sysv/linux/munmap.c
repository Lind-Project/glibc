#include <unistd.h>
#include <sysdep-cancel.h>
#include <stdint.h>
#include <fcntl.h>

int
__GI___munmap (uint64_t stack, uint64_t stack_size)
{
  return 0;
}

int munmap (uint64_t stack, uint64_t stack_size)
{
  return 0;
}

weak_alias(__GI___munmap, __munmap)
