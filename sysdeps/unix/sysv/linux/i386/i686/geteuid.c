#include <unistd.h>
#include <syscall-template.h>

__uid_t
__geteuid (void)
{
	return MAKE_SYSCALL(51, "syscall|geteuid", NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED);
  // return 0;
}

weak_alias (__geteuid, geteuid)
