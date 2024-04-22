#include <unistd.h>

/* Make all changes done to FD actually appear on disk.  */
int
fsync (int fd)
{
  return ENOSYS;
}
libc_hidden_def (fsync)
