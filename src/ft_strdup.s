BITS	64

section .text
global	ft_strdup

extern ft_strlen
extern ft_strcpy
extern malloc
extern __errno_location

;	char *strdup(const char *s);

ft_strdup:
	test	rdi, rdi
	jz		exit_err

	push	rdi
	call	ft_strlen
	inc		rax 	; +1 for '\0'

	; Allocate using malloc
	mov		rdi, rax
	call	malloc wrt ..plt
	; Check result
	cmp		rax, 0
	pop		rsi
	je		exit_err
	
	;set up for strcpy
	mov		rdi, rax
	call	ft_strcpy

	ret

	exit_err:
		mov		r8, 0xc
		call	__errno_location wrt ..plt
		mov		[rax], r8
		mov		rax, 0
		ret
