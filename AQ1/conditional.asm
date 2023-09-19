section .data
	prompt db "Digite um mensagem", 10
	
	ne_msg db "Não é A", 10
	e_msg db "É A", 10
section .bss
	buff resb 64
section .text
global _start
	_start:
	mov eax, 4
	mov ebx, 1
	mov ecx, prompt
	mov edx, 19
	int 0x80
	
	mov eax, 3
	mov ebx, 0
	mov ecx, buff
	mov edx, 64
	int 0x80

	cmp [buff], byte 'A'
	je then

	mov eax, 4
	mov ebx, 1
	mov ecx, ne_msg
	mov edx, 10
	int 0x80
	jmp ext
	

	then:
		mov eax, 4
		mov ebx, 1
		mov ecx, e_msg
		mov edx, 5
		int 0x80
	ext:
		mov eax, 1
		int 0x80		
