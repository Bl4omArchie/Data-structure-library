section .text
    global binary_addition


binary_addition:
    mov rdi, rdi
    mov rsi, rsi


    jmp xor_while

    mov rax, rdi
    ret

xor_while:
    