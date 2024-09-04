BITS	64

global ft_write
;	ssize_t write(int fd, const void buf[.count], size_t count);

ft_write:
	mov rax, 1
	syscall
	cmp rax, 0
	jl	exit_err
	jmp exit

	exit_err:
		mov rax, -1
		ret

	exit:
		ret