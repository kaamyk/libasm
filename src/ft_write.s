BITS	64

global ft_write
;	ssize_t write(int fd, const void buf[.count], size_t count);
;	On success, the number of bytes written is returned.
;	On error, -1 is returned, and errno is set to indicate the error.
ft_write:
	xor rcx, rcx
	mov rax, 1
	mov r8, rdx
	mov rdx, 1
	ft_putchar:
		cmp rcx, r8
		jge exit
		cmp byte [rsi + rcx], 0
		je	exit
		syscall
		add rcx, 1
		jmp ft_putchar
	exit:
		ret
