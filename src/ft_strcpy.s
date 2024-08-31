BITS 64

global ft_strcpy

ft_strcpy:
	xor rcx, rcx
	strcpy_loop:
		cmp byte [rsi + rcx], 0
		je	strcpy_loop_end
		mov al, byte [rsi + rcx]
		mov [rdi + rcx], al
		add rcx, 1
		jmp strcpy_loop

	strcpy_loop_end:
		mov byte [rdi + rcx], 0
		mov rax, rdi
		ret
