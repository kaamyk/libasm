BITS	64

global ft_write
;	ssize_t write(int fd, const void buf[.count], size_t count);
;	On success, the number of bytes written is returned.
;	On error, -1 is returned, and errno is set to indicate the error.
ft_write:
	xor r9, r9
	mov rax, 1
	mov r8, rdx
	mov rdx, 1
	ft_putchar:
		cmp r9, r8
		jge exit
		cmp byte [rsi], 0
		je	exit
		syscall
		inc r9
		inc rsi
		jmp ft_putchar
	exit:
		ret
