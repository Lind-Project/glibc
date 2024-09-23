	.text

	.export_name	wasi_clone_start, wasi_clone_start

	.globaltype	__stack_pointer, i32
	.functype	__wasi_clone_start_C (i32) -> (i32)

	.hidden	wasi_clone_start
	.globl	wasi_clone_start
	.type	wasi_clone_start,@function

wasi_clone_start:
	.functype	wasi_clone_start (i32) -> (i32)

	# Set up the minimum C environment.
	# Note: offsetof(start_arg, stack) == 0
	local.get   0  # start_arg
	i32.load    0  # stack
	global.set  __stack_pointer

	# Make the C function do the rest of work.
	local.get   0  # start_arg
	call __wasi_clone_start_C

	end_function