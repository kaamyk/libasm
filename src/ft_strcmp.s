BITS 64

global	ft_strcmp

ft_strcmp:
	xor rcx, rcx
	xor rax, rax
	strcmp_loop:
		mov al, byte [rdi + rcx]
		mov bl, byte [rsi + rcx]
		cmp al, bl
		jl strcmp_loop_end
		je strcmp_loop_end
		jg strcmp_loop_end

		cmp al, 0
		je strcmp_loop_end

		add rcx, 1
		jmp strcmp_loop

	; strcmp_loop_end_l:
	; 	mov rax, -1
	; 	jmp exit
	; strcmp_loop_end_e:
	; 	mov rax, 0
	; 	jmp exit
	; strcmp_loop_end_g:
	; 	mov rax, 1
	; 	jmp exit
	; exit:
	strcmp_loop_end:
		movzx rax, al
		movzx r8, bl
		sub rax, r8
		ret
