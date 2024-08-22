global ft_strcpy

;	char *strcpy(char *restrict dst, const char *restrict src);
;	Returns dst
ft_strcpy:
	xor rcx, rcx
	strcpy_loop:
		cmp byte [rsi + rcx], 0
		je	strcpy_loop_end
		mov cl, [rsi + rcx]
		mov [rdi + rcx], cl
		inc rcx
		jmp strcpy_loop

	strcpy_loop_end:
		mov byte [rdi + rcx], 0
		mov rax, rdi
		ret
