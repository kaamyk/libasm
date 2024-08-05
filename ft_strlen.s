BITS 64

section .data
	string db '>Test<',0x0A,0
	string_l equ $ - string
	args_err_mess db 'Wrong numbers of arguments',0x0A,0
	args_err_mess_l equ $ - args_err_mess

section .bss
	str_res resb 1024
	tmp	resq 1
	res resq 1
	len_num resq 1

section .text
	global _start

_start:
	mov rax, 1
	mov rdi, 1
	lea rsi, [string]
	lea rdx, [string_l]
	syscall

	; Check number of  arguments
	mov rdi, [rsp]
	cmp rdi, 2
	jne exit_err

	; Copy arguments
	mov rsi, [rsp + 8] 

	xor rcx, rcx
	call ft_strlen
	call exit_prog

ft_strlen:
	cmp	byte [rsi + rcx], 0
	je	print_result
	inc rcx
	jmp	ft_strlen

print_result:
	mov rax, 1
	mov rdi, 1
	lea rsi, [string]
	lea rdx, [string_l]
	syscall
	; move into variable res, the value of rcx
	mov [res],rcx

	mov rax, 1
	mov rdi, 1
	lea rsi, [res]
	lea rdx, [1]
	syscall
	
	jmp exit_prog

ft_itoa:
	call	l_num	; Stores the number of digit in RBX
	

l_num:
	mov rax, [res]
	xor rcx, rcx
	call l_num_loop

l_num_loop:
	inc rcx
	cmp len_num, 10
	jl l_num_end_loop	; Jump if strictly lesser than
	div 10
	jmp l_num_loop

l_num_end_loop:
	mov rbx, rcx
	xor rcx, rcx
	ret

exit_err:
	mov rax, 1
	mov rdi, 1
	lea rsi, [args_err_mess]
	lea rdx, [args_err_mess_l]
	syscall
	call exit_prog

exit_prog:
	mov rax, 60
	xor rdi, rdi
	syscall