section .text
    global add_binary_optimized
    global sub_binary_optimized


; Algorithm 3.1
add_binary_optimized:
    push rbp
    mov rbp, rsp

    mov rax, rdi    ; a
    mov rbx, rsi    ; b
    mov rcx, rdx    ; carry

    add_loop:
        mov rdx, rax        ; a into rdx
        xor rax, rbx        ; xor b into a
        and rbx, rdx        ; & rdx into b
        shl rbx, 1          ; b << 1 into b
        
        test edx, edx
        jnz add_loop

    add rax, rcx
    pop rbp
    ret


; Algorithm 3.2
sub_binary_optimized:
    push rbp
    mov rbp, rsp

    mov eax, edi    ; a
    mov edx, esi    ; b

    sub_loop:
        xor eax, edx        ; a ^ b into a
        and edx, eax        ; a & b into b
        shl edx, 1          ; b << 1 into b
        
        test edx, edx
        jnz sub_loop

    pop rbp
    ret