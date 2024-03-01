section .text
    global add_binary_optimized
    global sub_binary_optimized


; Algorithm 3.1:
; var: a, b
; while (b):
;   a = a ^ b
;   b = ((a^b)& b) << 1
; ret a

add_binary_optimized:
    push rbp
    mov rbp, rsp
    mov eax, edi
    mov edx, esi

    add_loop:
        mov ecx, eax        ; a into ecx
        xor eax, edx        ; a ^ b into a
        and edx, ecx        ; ecx & b into b
        shl edx, 1          ; b << 1 into b
        
        test edx, edx
        jnz add_loop

    pop rbp
    ret



; Algorithm 3.2:
; var: a, b
; while (b):
;   a = a ^ b
;   b = (a & b) << 1
; ret a

sub_binary_optimized:
    push rbp
    mov rbp, rsp
    mov eax, edi
    mov edx, esi

    sub_loop:
        xor eax, edx        ; a ^ b into a
        and edx, eax        ; a & b into b
        shl edx, 1          ; b << 1 into b
        
        test edx, edx
        jnz sub_loop

    pop rbp
    ret