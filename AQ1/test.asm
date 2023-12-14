section .data
    suc db "Worked", 10
    suc_len equ $ - suc
    err db "Fail", 10
    err_len equ $ - err
    input_path db "input.txt", 0

section .bss
    fd_in resb 1
    buffer resb 1024
section .text
global _start
_start:
    mov eax, 5 ; sys_open
    mov ebx, input_path ; pathname
    mov ecx, 0 ; read only flag
    int 0x80

    mov [fd_in], eax

    ; READ FROM FILE
    mov eax, 3 ; sys_read
    mov ebx, [fd_in]
    mov ecx, buffer
    mov edx, 1024
    int 0x80

    ; CHECK IF ANYTHING WAS READ
    cmp eax, 0
    jl error

    mov eax, 4
    mov ebx, 1
    mov ecx, suc
    mov edx, suc_len

    int 80h

    mov eax, 1
    int 80h

error:
        mov eax, 4
        mov ebx, 1
        mov ecx, err
        mov edx, err_len

        int 80h

        mov eax, 1
        int 80h

    

    