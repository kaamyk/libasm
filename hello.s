BITS 64

section .data
	hello db 'bonjour les amis',0

section .text
	global _start
_start:
	mov rax,1
	mov rdi,1
	mov rsi,hello
	mov rdx,16
	syscall

	mov rax, 60
	mov rdi,4
	syscall