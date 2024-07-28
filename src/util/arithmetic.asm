section .text
    global add_binary_optimized
    global sub_binary_optimized


; Algorithm 3.1
add_binary_optimized:
    push rbp
    mov rbp, rsp

    add_loop:
        mov rax, rdi        ; a into rdx
        xor rdi, rsi        ; xor b into a
        and rsi, rax        ; & rdx into b
        shl rsi, 1          ; b << 1 into b
        
        test rsi, rsi
        jnz add_loop

    add rdi, rdx
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