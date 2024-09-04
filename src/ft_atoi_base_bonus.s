BITS	64

global ft_atoi_base

extern ft_strlen

section .data
section .bss
	last_byte_addr resq 1
section .text

;	C04 ex05
ft_atoi_base:
	push rbp	 ;	push the old stack frame on the stack
	mov rbp, rsp ;	put the address of the new stack frame

	sub	rsp, 0x20
	mov qword [rsp], rdi	; Storing args
	mov qword [rsp + 0x8], rsi	; in stack
	
	;	Check for invalid arguments
	;	 ---empty strings
	cmp qword [rsp], 0x0
	je	exit_wrong_arg
	cmp qword [rsp + 0x8], 0x0
	je	exit_wrong_arg
	mov rax, qword [rsp]
	mov rax, [rax]
	cmp byte al, 0x0
	je	exit_wrong_arg
	mov rax, qword [rsp + 0x8]
	mov rax, [rax]
	cmp byte al, 0x0
	je	exit_wrong_arg
	;	----Parse base
	;		----Check length
	mov rdi, qword [rsp + 0x8]
	call ft_strlen
	cmp rax, 1
	je	exit_wrong_arg
	mov [rsp + 0x10], rax		; Put base len in stack

	;		----Check double
	mov rcx, [rsp + 0x8]		; Put in rcx base's addr
	add	rcx, [rsp + 0x10]		; Store in rcx addr base's null terminating char
	dec rcx						; Move rcx to last char's addr
	mov [rsp + 0x14], rcx		; Store in stack for loops
	dec rcx
	jmp base_parse_loop			; Move rcx to second to last char

	base_parse_loop:
		cmp rcx, [rsp + 0x8]
		je	base_parse_loop_end
	;			----check if char is +||-||whitespace 
		cmp byte [rcx], 0x2b	; +
		je exit_wrong_arg
		cmp byte [rcx], 0x2d	; -
		je exit_wrong_arg
	;			----OK if (a < 9 || a > 13) && a != 32
		cmp	byte [rcx], 0xd
		jg	jmp_white_spaces
		cmp byte [rcx], 0x9
		jl	jmp_white_spaces
		jmp exit_wrong_arg
		jmp_white_spaces:
		cmp byte [rcx], 0x20
		je exit_wrong_arg
		;		----Parse from end until rcx addr
		mov rdi, [rsp + 0x14]	; Put addr of base last char in first arg 
		mov rsi, rcx
		call check_double
		cmp rax, -1
		je exit_wrong_arg
		dec rcx
		jmp base_parse_loop
	base_parse_loop_end:
		jmp convert
		mov rax, 1
		mov rsp, rbp
		pop rbp
		ret

	exit_wrong_arg:
		mov rax, 0
		mov rsp, rbp
		pop rbp
		ret
	
	check_double: ;	rdi = last char | rsi = actual char
		push rbp
		mov rbp, rsp
		check_double_loop:
			cmp rdi, rsi
			je check_double_loop_end
			mov byte bl, [rdi]
			cmp byte bl, [rsi]
			je check_double_loop_err
			dec rdi
			jmp check_double_loop
		check_double_loop_end:
			mov rax, 0
			mov rsp, rbp
			pop rbp
			ret
		check_double_loop_err:
			mov rax, -1
			mov rsp, rbp
			pop rbp
			ret

	convert:
		xor r8, r8					; r8 is our counter
		mov rsi, [rsp + 0x8]		; Put base addr in second arg
		mov qword [rsp + 0x17], 0x0	; Put value 0 in stack for res
		convert_loop:
			xor rax, rax
			; mov rax, qword [rsp + 0x17]	; Get the res value
			; mov rcx, qword [rsp + 0x10]	; Put value len base in rcx to mult res
			; mul rcx						; rax * rcx => rax
			; mov [rsp + 0x17], qword rax	; Put rax in res
			mov rax, [rsp]				; Move in rax addr of str
			mov rax, [rax + r8]			; Dereference pointer
			cmp al, 0x0					; Check if reached null byte
			je exit
			movzx rdi, al			; Move in first arg str[r8]
			call get_digit_rank 
			cmp rax, -1
			je exit_wrong_arg
			;	No err: Add the new decimal digit
			mov r9, rax
			mov rax, qword [rsp + 0x17]	; Get the res value
			mov rcx, qword [rsp + 0x10]	; Put value len base in rcx to mult res
			mul rcx						; rax * rcx => rax
			add rax, r9
			mov [rsp + 0x17], qword rax	; Put rax in res
			add r8, 1
			jmp convert_loop
	
	get_digit_rank:	; rdi = str[r8] | rsi = *base
		push rbp
		mov rbp, rsp
		xor rcx, rcx
		xor rax, rax
		get_digit_rank_loop:
			cmp byte [rsi + rcx], 0x0			; Check if reached base's null byte
			je get_digit_rank_loop_err
			mov al, byte [rsi + rcx]
			cmp al, dil			; if (base[rcx] == str[r8])
			je get_digit_rank_loop_end
			inc rcx
			jmp get_digit_rank_loop
		get_digit_rank_loop_err:
			mov rax, -1
			mov rsp, rbp
			pop rbp
			ret
		get_digit_rank_loop_end:
			mov rax, rcx
			mov rsp, rbp
			pop rbp
			ret

	exit:
		xor rax, rax
		mov rax, [rsp + 0x17]
		mov rsp, rbp
		pop rbp
		ret