
global ft_strlen
ft_strlen:

	mov rsi, rdi
	xor rcx, rcx

	ft_strlen_loop:
		cmp	byte [rdi + rcx], 0
		je	ft_strlen_end
		inc rcx
		jmp	ft_strlen_loop

	ft_strlen_end:
		mov rax, rcx
		ret