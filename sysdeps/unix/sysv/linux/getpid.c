#include <unistd.h>

int32_t __imported_wasi_fork() __attribute__((
    __import_module__("wasix"),
    __import_name__("lind-fork")
));

int32_t __wasi_fork() {
    return __imported_wasi_fork(0);
}

pid_t
__getpid (void)
{
  return __imported_wasi_fork(0);
}

pid_t
getpid (void)
{
  return __imported_wasi_fork(0);
}

