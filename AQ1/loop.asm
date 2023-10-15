section .data
    prompt db "Digite seu nome: "
    prompt_len equ $ - prompt

    greet db "Olá, "
    greet_len equ $ - greet

section .bss
    buffer resb 64
    buffer2 resb 64
section .text
global _start
_start:
    mov eax, 4 ; stdout
    mov ebx, 1
    mov ecx, prompt
    mov edx, prompt_len
    int 0x80

    mov eax, 3 ; stdin
    mov ebx, 0
    mov ecx, buffer
    mov edx, 64
    int 0x80

    ; Start loop implementation
    mov esi, 0

    loop:
        mov al, [buffer + esi]
        mov [buffer2 + esi], al
        cmp al, 10
        je end
        inc esi
        jmp loop
    
    end:
        mov eax, 4
        mov ebx, 1
        mov ecx, greet
        mov edx, greet_len
        int 0x80

        mov eax, 4
        mov ebx, 1
        mov ecx, buffer2
        mov edx, esi
        int 0x80

        mov eax, 1
        mov ebx, 0
        int 0x80

