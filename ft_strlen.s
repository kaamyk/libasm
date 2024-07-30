BITS 64

section .data
	string db 'Salut les copains',0
	args_err_mess db 'Wrong numbers of arguments',0
	args_err_mess_l db 26

section .bss
	str_arg: resb 1024
	s_len: resd 1

section .text
	global _start


_start:

	; check_args
	cmp rdi, 0x1
	jne print_args_err_mess
	mov [str_arg],rcx
	jmp ft_strlen
	xor rcx,rcx

print_args_err_mess:
	mov rax,1
	mov rdi,1
	mov rsi,[args_err_mess]
	mov rdx,[args_err_mess_l]
	syscall

ft_strlen:
	cmp byte [rsi + rcx], 0
	je print_result
	inc rcx
	jmp ft_strlen

print_result:
	mov rcx,s_len
	mov rax,1
	mov rdi,1
	mov rsi,[s_len]
	mov rdx,1
	syscall

	mov rax,60
	xor rdi,rdi
	syscall