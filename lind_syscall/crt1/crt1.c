#include <wasi/api.h>
#include <stdlib.h>
#include <sysexits.h>

int32_t __imported_wasi_snapshot_preview1_args_sizes_get(int32_t arg0, int32_t arg1) __attribute__((
    __import_module__("wasi_snapshot_preview1"),
    __import_name__("args_sizes_get")
));

__wasi_errno_t __wasi_args_sizes_get(
    __wasi_size_t *retptr0,
    __wasi_size_t *retptr1
){
    int32_t ret = __imported_wasi_snapshot_preview1_args_sizes_get((int32_t) retptr0, (int32_t) retptr1);
    return (uint16_t) ret;
}

int32_t __imported_wasi_snapshot_preview1_args_get(int32_t arg0, int32_t arg1) __attribute__((
    __import_module__("wasi_snapshot_preview1"),
    __import_name__("args_get")
));

__wasi_errno_t __wasi_args_get(
    uint8_t * * argv,
    uint8_t * argv_buf
){
    int32_t ret = __imported_wasi_snapshot_preview1_args_get((int32_t) argv, (int32_t) argv_buf);
    return (uint16_t) ret;
}

void __libc_setup_tls();
void __wasi_init_tp();

int _start() {
    __libc_setup_tls();
    __wasi_init_tp();
    return __main_void();
}

void __wasm_call_dtors() {
    
}

void __wasi_proc_exit(unsigned int exit_code) {
    
}

// The user's `main` function, expecting arguments.
//
// Note that we make this a weak symbol so that it will have a
// `WASM_SYM_BINDING_WEAK` flag in libc.so, which tells the dynamic linker that
// it need not be defined (e.g. in reactor-style apps with no main function).
// See also the TODO comment on `__main_void` below.
__attribute__((__weak__))
int __main_argc_argv(int argc, char *argv[]);

// If the user's `main` function expects arguments, the compiler will rename
// it to `__main_argc_argv`, and this version will get linked in, which
// initializes the argument data and calls `__main_argc_argv`.
//
// TODO: Ideally this function would be defined in a crt*.o file and linked in
// as necessary by the Clang driver.  However, moving it to crt1-command.c
// breaks `--no-gc-sections`, so we'll probably need to create a new file
// (e.g. crt0.o or crtend.o) and teach Clang to use it when needed.
__attribute__((__weak__, nodebug))
int __main_void(void) {
    __wasi_errno_t err;

    // Get the sizes of the arrays we'll have to create to copy in the args.
    size_t argv_buf_size;
    size_t argc;
    __wasi_args_sizes_get(&argc, &argv_buf_size);

    // Add 1 for the NULL pointer to mark the end, and check for overflow.
    size_t num_ptrs = argc + 1;
    if (num_ptrs == 0) {
        _Exit(EX_SOFTWARE);
    }

    // Allocate memory for storing the argument chars.
    char *argv_buf = malloc(argv_buf_size);
    if (argv_buf == NULL) {
        _Exit(EX_SOFTWARE);
    }

    // Allocate memory for the array of pointers. This uses `calloc` both to
    // handle overflow and to initialize the NULL pointer at the end.
    char **argv = calloc(num_ptrs, sizeof(char *));
    if (argv == NULL) {
        free(argv_buf);
        _Exit(EX_SOFTWARE);
    }

    // Fill the argument chars, and the argv array with pointers into those chars.
    // TODO: Remove the casts on `argv_ptrs` and `argv_buf` once the witx is updated with char8 support.
    __wasi_args_get((uint8_t **)argv, (uint8_t *)argv_buf);

    // Call `__main_argc_argv` with the arguments!
    return __main_argc_argv(argc, argv);
}
