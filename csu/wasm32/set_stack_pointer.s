	.text

	.export_name	set_stack_pointer, set_stack_pointer

	.globaltype	__stack_pointer, i32

	.hidden	set_stack_pointer
	.globl	set_stack_pointer
	.type	set_stack_pointer,@function

set_stack_pointer:
	.functype	set_stack_pointer (i32) -> ()

	local.get   0  # start_arg
	i32.load    0  # stack
	global.set  __stack_pointer

	end_function