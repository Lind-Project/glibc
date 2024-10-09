	.text

	.export_name	set_stack_start, set_stack_start

	.globaltype	__stack_pointer, i32
	.functype	_start () -> (i32)

	.hidden	set_stack_start
	.globl	set_stack_start
	.type	set_stack_start,@function

set_stack_start:
	.functype	set_stack_start (i32) -> (i32)

	local.get   0  # start_arg
	global.set  __stack_pointer

	call _start

	local.set 0
	local.get 0

	return

	end_function