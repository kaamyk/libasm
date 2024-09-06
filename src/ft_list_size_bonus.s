BITS	64

global ft_list_size

;	int ft_list_size(t_list *begin_list);
ft_list_size:
	xor		rax, rax
size_loop:
	test	rdi, rdi
	jz		end
	inc		rax
	mov		rdi, [rdi + 0x8]
	jmp		size_loop

end:
	ret