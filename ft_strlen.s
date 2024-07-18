BITS 64

section .data
	string db 'Salut les copains',0

section .text
	global _start
_start:
	mov rcx, 0

l1:
	mov rax, 1
	mov rdi, 1
	mov rsi, rcx
	mov rdx, 1
	syscall

	mov rax, 60
	mov rdi, 0
	syscallf