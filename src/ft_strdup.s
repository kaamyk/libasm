BITS	64

global	ft_strdup

extern ft_strlen
extern ft_strcpy
extern _malloc

ft_strdup:
	call ft_strlen
	;rax > s_len
	inc rax 	; +1 for '\0'
	mov r8, rax
	mov r9, rdi

	;Get the actual brk
	mov rax, 12	;sys_brk
	xor rdi, rdi
	syscall
	;rax > actual highest available address
	mov r10, rax

	;allocate the new area
	add rax, r8
	mov rdi, rax
	mov rax, 12
	syscall

	;check result
	cmp rax, 0
	jl exit
	
	;set up for strcpy
	sub rax, r8
	mov rdi, rax
	mov rsi, r9
	call ft_strcpy

	ret

	exit:
		ret