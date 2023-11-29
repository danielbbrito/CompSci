section .data
    error_message db "An error has ocurred! Please try again.", 0xa
    len_error_message equ $ - error_message
output db 'A', 0
    input_path db "./input.txt"
    output_path db "output.txt"

section .bss
    buffer: resb 1024
    fd_out: resb 1
    fd_in: resb 1
    
section .text
global _start
_start:
    ; OPEN INPUT FILE
    mov eax, 5 ; sys_open
    mov ebx, input_path ; pathname
    mov ecx, 0 ; read only flag
    int 0x80
    
    ; CHECK IF FILE WAS OPENED
    cmp eax, 0 ; compare eax and 0
    jl error_handler ; error if eax < 0

    ; SAVE FILE DESCRIPTOR 
    mov [fd_in], eax

    ; READ FROM FILE
    mov eax, 3 ; sys_read
    mov ecx, buffer
    mov edx, 1024
    int 0x80

    ; CHECK IF ANYTHING WAS READ
    cmp byte [buffer], 0
    je error_handler

    ; CLOSE INPUT FILE
    mov eax, 6 ; sys_close
    int 0x80

    ; OPEN OR CREATE OUTPUT FILE
    mov eax, 5 ; sys_open
    mov ebx, output_path ; pathname
    mov ecx, 101o ; open to write or create file
    mov edx, 700o
    int 0x80

    ; CHECK IF FILE WAS OPENED
    cmp eax, 0
    jl error_handler

    mov [fd_out], eax ; store output file descriptor


    ; ENCRYPT DATA IN BUFFER
    jmp encrypts
    mov ecx, 0
    encrypts:
        mov eax, [buffer] ; gets current byte
        cmp eax, 0
        je end ; break loop if EOF
        add eax, 3 ; changes the byte's ascii value
        inc ecx ; increment counter
        mov [buffer + ecx], eax ; updates the buffer

        jmp encrypts
    end:
    ; WRITE TO OUTPUT FILE
    mov eax, 4 ; sys_write
    mov ebx, fd_out ; output file descriptor
    mov ecx, buffer ; to write
    mov edx, 1024
    int 0x80

    ; CHECK IF WRITE WAS SUCCESSFUL
    cmp eax, 0
    jl error_handler

    ; END
    mov eax, 1
    mov ebx, 0
    int 0x80


error_handler:
    mov eax, 4
    mov ebx, 1
    mov ecx, error_message
    mov edx, len_error_message
    int 0x80

    mov eax, 1
    mov ebx, 1
    int 0x80

    ret

