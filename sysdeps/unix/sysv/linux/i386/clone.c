#include <sched.h>
#include "libioP.h"

int32_t __imported_wasi_clone(int32_t args) __attribute__((
    __import_module__("wasix"),
    __import_name__("lind-clone")
));

int32_t __wasi_clone(void *args) {
    return __imported_wasi_clone((int32_t) args);
}

int32_t __imported_wasi_do_clone(int32_t args, int32_t share_memory, int32_t start_func) __attribute__((
    __import_module__("wasix"),
    __import_name__("lind-do-clone")
));

int32_t __wasi_do_clone(void *args, int32_t share_memory, int32_t start_func) {
    return __imported_wasi_do_clone((int32_t) args, share_memory, start_func);
}

void wasi_clone_start(void *p);
void *__dummy_reference2 = wasi_clone_start;

struct start_args {
    char *stack;
    int (*start_func)(void *);
    void *start_arg;
};

int __wasi_clone_start_C(void *p)
{
    struct start_args *args = p;

    return args->start_func(args->start_arg);
}

int __GI___clone (int (*__fn) (void *__arg), void *__child_stack,
		    int __flags, void *__arg, ...) {
    struct start_args *args = (void *)__child_stack;
    args->stack = __child_stack - sizeof(struct start_args);
    args->start_func = __fn;
    args->start_arg = __arg;

    // whether the memory is shared
    int share_memory = (__flags & CLONE_VM);
    int start_fn = !(__fn == NULL);

    // return __wasi_clone(args);
    return __wasi_do_clone(args, share_memory, start_fn);
}
weak_alias (__GI___clone, __clone)
weak_alias (__GI___clone, clone)
