BITS	64

global ft_atoi_base

extern ft_strlen

section .data
section .text

;	C04 ex05
ft_atoi_base:
	;	Check for invalid arguments
	;		empty strings
	cmp rdi, 0x0
	je	exit_wrong_arg
	cmp rsi, 0x0
	je	exit_wrong_arg
	cmp byte [rdi], 0x0
	je	exit_wrong_arg
	cmp byte [rsi], 0x0
	je	exit_wrong_arg
	;		Parse base
	mov r8, rdi
	mov rdi, rsi
	call ft_strlen
	cmp rax, 1
	je	exit_wrong_arg
	mov rdi, r8
	mov rcx, rsi
	add	rcx, rax	; Store in rcx addr of base's last char
	sub rcx, 0x1
	mov rbx, rcx	; Store again in rbx for loops
	base_parse_loop:
		cmp rcx, rsi
		je	base_parse_loop_end

		;	check if char is +||-||whitespace 
		cmp byte [rcx], 0x2b
		je exit_wrong_arg
		cmp byte [rcx], 0x2d
		je exit_wrong_arg
		;	OK if a < 9 || a > 13
		;	check if 9 <= a (not > a)
		cmp byte [rcx], 0x9
		jl	jmp_white_spaces
		;	check if 13 >= a (not < a)
		cmp	byte [rcx], 0xd
		jg	jmp_white_spaces
		jmp exit_wrong_arg
		jmp_white_spaces:
		cmp byte [rcx], 0x20
		je exit_wrong_arg

		;	parse from end until rcx addr
		mov r8, rbx
		call check_double
		cmp rax, -1
		je exit_wrong_arg
		dec rcx
		jmp base_parse_loop
	base_parse_loop_end:
		mov rax, 1
		ret

	exit_wrong_arg:
		mov rax, 0
		ret

	check_double:
		check_double_loop:
			cmp r8, rcx
			je check_double_loop_end
			mov r9, [r8]
			cmp r9, [rcx]
			je check_double_loop_err
			dec r8
			jmp check_double_loop
		check_double_loop_end:
			mov rax, 0
			ret
		check_double_loop_err:
			mov rax, -1
			ret

