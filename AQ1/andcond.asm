section .data
	prompt db "Digite uma mensagem: ", 0
	satisfies db "O primeiro caractere da mensagem é uma letra minuscula", 10
	notsatisfies db "O primeiro caractere da mensagem NÃO é uma letra minúscula", 10
	

section .bss
	buff resb 64
section .text
global _start
	_start:
		mov eax, 4 ; print
		mov ebx, 1 ; stdout (screen)
		mov ecx, prompt
		mov edx, 21
		int 0x80
		
		mov eax, 3 ; read
		mov ebx, 0 ; stdin
		mov ecx, buff
		mov edx, 64
		int 0x80	
		cmp [buff],byte 'a'
		jae first

		first:
			cmp [buff], byte 'z'
			jbe second
			
		second:
			mov eax, 4
			mov ebx, 1
			mov ecx, satisfies
			mov edx, 56
			int 0x80

			mov eax, 1
			int 0x80
		
		mov eax, 4
		mov ebx, 1
		mov ecx, notsatisfies
		mov edx, 60
		int 0x80

		mov eax, 1
		int 0x80
	
