BITS	64

global ft_write

extern __errno_location
;	ssize_t write(int fd, const void buf[.count], size_t count);

ft_write:
	mov		rax, 1
	syscall
	cmp		rax, 0
	jl		exit_err
	jmp		exit

	exit_err:
		neg		rax
		mov		r8, rax
		call	__errno_location wrt ..plt
		mov		[rax], r8
		mov		rax, -1
		ret

	exit:
		ret