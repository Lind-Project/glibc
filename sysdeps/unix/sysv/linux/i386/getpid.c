#include <unistd.h>
#include <syscall-template.h>

// __int32_t __imported_wasi_getpid() __attribute__((
//     __import_module__("wasix"),
//     __import_name__("lind-getpid")
// ));

// __int32_t __wasi_getpid() {
//     return __imported_wasi_getpid(0);
// }

pid_t
__getpid (void)
{
  // return __wasi_getpid();
  return MAKE_SYSCALL(31, "syscall|getpid", NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED, NOTUSED);
}

pid_t
getpid (void)
{
  return __getpid();
}


