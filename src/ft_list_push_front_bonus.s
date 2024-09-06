BITS	64

section .bss
n_ptr	resq 1;

section .text
global ft_list_push_front

extern	ft_strdup
extern	malloc

;	C12 ex01
;	void ft_list_push_front(t_list **begin_list, void *data);
ft_list_push_front:
;	Push both arg on stack
	push	rdi
	push	rsi

	test 	rdi, rdi
	jz		exit

;	Allocate sizeof(t_list) = sizeof(void*) + sizeof(t_list*)
;							= 0x8 + 0x8
	mov		rdi, 0x10
	call	malloc	wrt ..plt
	test	rax, rax
	jz		exit

	pop 	rsi
	mov		[rax], rsi

	pop		rdi					; rdi = begin_list
	mov		rbx, [rdi]
	mov		[rax + 0x8], rbx	; struct.next = *begin_list
	mov		[rdi], rax			; *begin_list = (&)n_struct

exit:
	ret
	
