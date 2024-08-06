BITS 64

section .data
	string db '>Test<',0x0A,0
	string_l equ $ - string
	args_err_mess db 'Wrong numbers of arguments',0x0A,0
	args_err_mess_l equ $ - args_err_mess
	alloc_err_mess db 'Allocation failed',0x0A,0
	alloc_err_mess_l equ $ - alloc_err_mess

section .bss
	res_itoa resb 1024
	tmp	resq 1
	res_strlen resq 1
	len_num resq 1
	dest_memory resq 1

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
	mov [res_strlen],rcx	; move into variable res_strlen, the value of rcx

	call ft_itoa
		
	jmp exit_prog

ft_itoa:
	call	l_num	; Stores (number of digit + NULL byte) in len_num
	;	void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset);
	mov rax, 9
	xor rdi, rdi ;	set start addr to 0 to let kernel choose
	mov rsi, rbx
	mov rdx, 3
	mov r10, 0x22
	xor r8, r8
	xor r9, r9
	syscall	; RAX contains the addr of memory allocated

	cmp rax, -1	; check if allocation failed
	je alloc_err

	mov [dest_memory],rax	; mov addr in a variable
	call write_num_in_string

	mov rax, 1
	mov rdi, 1
	lea rsi, [dest_memory]
	lea rdx, [len_num]
	syscall
	ret

write_num_in_string:
	mov rcx,len_num
	mov r8, 10
	call write_num_loop
	ret

write_num_loop:
	cmp rcx, 0
	je write_num_loop_end	; Si rcx = len_num => quitte la loop

	div r8	; divide by 10, quotient in RAX and remainder in RDX
	mov rbx, rdx
	add rbx, 0x30
	cmp rbx, 10
	jl write_num_loop_end	; Si quotient < 10 quitte loop

	mov rsi,[dest_memory]	; Reset rsi at beginning of allocated memory 
	add rsi, rcx	; add to rsi index

	mov rsi,rbx	; Stores the number character in the final string
	
	dec rcx
	jmp write_num_loop

write_num_loop_end:
	ret

l_num:
	mov rax, [res_strlen]
	xor rcx, rcx
	mov r8, 10
	call l_num_loop
	ret

l_num_loop:
	inc rcx
	cmp rax, 10
	jl l_num_end_loop	; Jump if strictly lesser than
	div r8	; divide by 10, quotient in RAX and remainder in RDX
	jmp l_num_loop

l_num_end_loop:
	inc rcx	; inc one time for null byte
	mov [len_num], rcx
	xor rcx, rcx
	ret

alloc_err:
	mov rax,1
	mov rdi,2
	mov rsi,[args_err_mess]
	mov rdx,[args_err_mess_l]
	syscall
	call exit_prog

exit_err:
	mov rax, 1
	mov rdi, 2
	lea rsi, [args_err_mess]
	lea rdx, [args_err_mess_l]
	syscall
	call exit_prog

exit_prog:
	mov rax, 60
	xor rdi, rdi
	syscall