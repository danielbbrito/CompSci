section .data
    error_message db "An error has ocurred! Please try again.", 0xa
    len_error_message equ $ - error_message

    buffer_full_message db "The buffer is full", 0xa
    len_buffer_full equ $ - buffer_full_message

output db 'A', 0
    input_path db "./input.txt", 0
    output_path db "output.txt", 0

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
    mov ebx, [fd_in]
    mov ecx, buffer
    mov edx, 1024
    int 0x80

    ; CHECK IF ANYTHING WAS READ
    cmp eax, 0
    jl error_handler
    ; Works up to here!!!!!!
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
    mov ecx, 0
    jmp encrypts
    encrypts:
        movzx eax, byte [buffer + ecx] ; gets current byte
        cmp eax, 0
        je end ; break loop if EOF
        add eax, 3 ; changes the byte's ascii value
        inc ecx ; increment counter
        cmp ecx, 1024
        jge buffer_full
        mov [buffer + ecx], eax ; updates the buffer

        jmp encrypts
    end:
    ; WRITE TO OUTPUT FILE
    mov edx, ecx
    mov eax, 4 ; sys_write
    mov ebx, [fd_out] ; output file descriptor
    mov ecx, buffer ; to write
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



buffer_full:
    mov eax, 4
    mov ebx, 1
    mov ecx, buffer_full_message
    mov edx, len_buffer_full
    int 0x80

    mov eax, 1
    mov ebx, 1
    int 0x80