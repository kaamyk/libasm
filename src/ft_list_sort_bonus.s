BITS	64

global ft_list_sort

ft_list_sort:
	push 	rdi

find_smallest:					; rdi contains addr of first item not sorted
	mov		rcx, [rdi]			; rdi = *begin_list
	mov 	rax, [rdi]			; rax stores the final address
find_smallest_loop:
	cmp		qword rcx, 0x0
	je		find_smallest_end

	mov		r8, [rax]
	mov		r8, [r8]
	mov 	r9, [rcx]
	mov		r9, [r9]
	cmp		r8, r9
	jg		switch
	
	mov		rcx, qword [rcx + 0x8]	; rcx = rcx->next
	jmp		find_smallest_loop
switch:
	mov		rax, rcx
	jmp		find_smallest_loop
find_smallest_end:
	pop		rdi
	ret
