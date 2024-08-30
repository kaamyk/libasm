BITS	64

global ft_read

ft_read:
	xor rax, rax
	syscall
	cmp rax, 0
	jl	exit_err
	jmp exit

	exit_err:
		mov rax, -1
		ret

	exit:
		ret
