section .data
	string db "Digite uma mensagem ", 10
	size equ $ - string

section .bss
    buff resb 64
section .text
global _start
_start:
	mov eax, 4 ;stdout
	mov ebx, 1 ;screen
	mov ecx, string ;message
	mov edx, size ;msg size
	int 0x80

	mov eax, 3 ;read
	mov ebx, 0 ;stdout
	mov ecx, buff
	mov ecx, 64
	int 0x80
	
	mov eax, 1
	int 0x80
