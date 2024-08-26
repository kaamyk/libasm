BITS 64

global ft_strlen

ft_strlen:
	xor rcx, rcx
	
	ft_strlen_loop:
		cmp	byte [rdi + rcx], 0
		je	ft_strlen_end
		inc rcx
		jmp	ft_strlen_loop

	ft_strlen_end:
		mov rax, rcx
		ret
