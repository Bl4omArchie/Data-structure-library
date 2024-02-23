section .text
    global add_binary_optimized


; var: a, b, mask (uint_64)
; while (b):
;   a = a ^ b
;   b = (((a^b)& b) << 1)
; ret a


add_binary_optimized:
    push rbp
    mov rbp, rsp

    mov eax, edi
    mov edx, esi

    while_loop:
        xor eax, edx        ; a ^ b into a
        mov ecx, edx        ; b into ecx
        xor ecx, eax        ; b ^ a into ecx
        and edx, ecx        ; ecx & b into b
        shl edx, 1          ; b << 1 into b
        
        test edx, edx
        jnz while_loop

    pop rbp
    ret