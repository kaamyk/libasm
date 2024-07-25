BITS 64

section .data
	string db 'Salut les copains',0

section .text
	global _start
_start:
	mov rcx, 0
	;mov rsi string
	mov rsi, rcx
	mov rax,1
	mov rdi,1
	mov rdx,1

print_number:
	

l1:
	add rcx,1
	call int_to_string
	syscall

	mov rax, 60
	mov rdi, 0
	syscall

	loop l1