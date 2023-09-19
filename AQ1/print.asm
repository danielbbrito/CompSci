section .data
	string db "Hello, world!", 10
	size equ $ - string
section .text
global _start
_start:
	mov eax, 4 ;stdout
	mov ebx, 1 ;screen
	mov ecx, string ;message
	mov edx, size ;msg size
	int 0x80
	mov eax, 1
	int 0x80
