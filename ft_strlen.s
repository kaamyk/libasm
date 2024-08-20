BITS 64

section .data
	string db '>Test<',0x0A,0
	string_l equ $ - string
	args_err_mess db 'Wrong numbers of arguments',0x0A,0
	args_err_mess_l equ $ - args_err_mess
	alloc_err_mess db 'Allocation failed',0x0A,0
	alloc_err_mess_l equ $ - alloc_err_mess
	len_error_mess db 'len_num equal zero',0x0A,0
	len_error_mess_l equ $ - len_error_mess

section .bss
	str_arg resb 1024
	res_itoa resb 1024
	tmp	resq 1
	res_strlen resq 1
	len_num resq 1
	dest_memory resq 1

section .text
	global _start

_start:
	; Check number of  arguments
	mov rdi, [rsp]
	cmp rdi, 2
	jne exit_err

	; Copy arguments
	mov rsi, [rsp + 16]

	xor rcx, rcx          ; Clear RCX (used as counter)

	call ft_strlen

    mov rax, 1            ; syscall: sys_write
    mov rdi, 1            ; file descriptor: stdout
    mov rdx, rcx          ; number of bytes to write
    syscall               ; make the syscall
    ; jmp exit_prog

	xor rcx, rcx
	call ft_strlen
	mov [res_strlen],rcx	; move into variable res_strlen, the value of rcx
	
	call print_result
	call exit_prog

ft_strlen:
		cmp	byte [rsi + rcx], 0
		je	ft_strlen_end
		inc rcx
		jmp	ft_strlen
ft_strlen_end:
	mov [res_strlen], rcx
	ret

print_result:
	call ft_itoa

	mov rax, 1
	mov rdi, 1
	mov rsi, [dest_memory]
	mov rdx, 1
	; mov rdx, [len_num]
	syscall
	ret

ft_itoa:
	call	l_num	; Stores (number of digit + NULL byte) in len_num
	;	void *mmap(void *start, size_t length, int prot, int flags, int fd, off_t offset);

	cmp byte [len_num], 0
	je	len_error

	mov rax, 9
	xor rdi, rdi ;	set start addr to 0 to let kernel choose
	mov rsi, [len_num]
	mov rdx, 3
	mov r10, 0x22
	xor r8, r8
	xor r9, r9
	syscall	; RAX contains the addr of memory allocated

	cmp rax, -1	; check if allocation failed
	je alloc_err

	; mov [dest_memory], rax
	; lea rsi, [dest_memory]	; Put the address of string's origin in rsi
	; add rsi, [len_num - 1]		; Put the address of string's end in rsi
	; mov rbx, [dest_memory]	; Store the address of string's origin in rbx
	; mov rcx, len_num
	; mov r8, 10
	; mov rax, res_strlen
	call write_num_in_string
	ret

write_num_in_string:
	mov [dest_memory], rax
	lea rsi, [dest_memory]	; Put the address of string's origin in rsi
	add rsi, [len_num - 1]		; Put the address of string's end in rsi
	mov rbx, [dest_memory]	; Store the address of string's origin in rbx
	mov rcx, len_num
	mov r8, 10
	mov rax, res_strlen
	write_num_loop:
		cmp rcx, 0
		je write_num_loop_end	; Si rcx = len_num => quitte la loop
		sub rsi, 1

		cmp rax, 0
		je write_num_loop_end	; If quotient < 10 leave loop

		div r8	; divide by 10, quotient in RAX and remainder in RDX
		add rdx, '0'	; add '0'(ascii value) to the digit
		mov [rsi], rdx

		sub rcx, 1
		jmp write_num_loop
	write_num_loop_end:
		ret

l_num:
	mov rax, [res_strlen]
	xor rcx, rcx
	mov r8, 10
	l_num_loop:
		inc rcx
		cmp rax, 10
		jl l_num_end_loop	; Jump if strictly lesser than
		xor rdx, rdx
		div r8	; divide by 10, quotient in RAX and remainder in RDX
		jmp l_num_loop
	l_num_end_loop:
		inc rcx	; inc one time for null byte
		mov [len_num], rcx
		ret
	ret

len_error:
	mov rax,1
	mov rdi,2
	mov rsi,[len_error_mess]
	mov rdx,[len_error_mess_l]
	syscall
	call exit_prog_err

alloc_err:
	mov rax,1
	mov rdi,2
	mov rsi,[args_err_mess]
	mov rdx,[args_err_mess_l]
	syscall
	call exit_prog_err

exit_err:
	mov rax, 1
	mov rdi, 2
	lea rsi, [args_err_mess]
	lea rdx, [args_err_mess_l]
	syscall
	call exit_prog_err

exit_prog_err:
	mov rax, 60
	mov rdi, 1
	syscall

exit_prog:
	mov rax, 60
	xor rdi, rdi
	syscall