.section .rodata
fmt: .string "Soma %f maior que o limite %f (%d)\n"
.align 8 
C0:.double 0.0

.text
.globl sum
sum:
    pushq %rbp
    movq %rsp, %rbp
    subq $80, %rsp

    # rbx  -> -8  (i) 
    # xmm0 -> -16 (limit) 
    # xmm1 -> -24 (s) 
    # vi   -> -40 
    # vd   -> -72

    movq %rbx, -8(%rbp)  # salva rbx 
    movl $4, %ebx        # i = 4 
    movsd C0, %xmm1      # s = 0.0 
    movl $5, -40(%rbp)   # vi[0] = 5 
    movl $6, -36(%rbp)   # vi[1] = 6 
    movl $7, -32(%rbp)   # vi[2] = 7 
    movl $8, -28(%rbp)   # vi[3] = 8 
    movsd %xmm0, -16(%rbp) # salva limit 
    movsd %xmm1, -24(%rbp) # salva s 
    
    leaq -40(%rbp), %rdi # 1o. param: &vi 
    leaq -72(%rbp), %rsi # 2o. param: &vd 
    movl %ebx, %edx      # 3o. param: i 
    call mult

while:
    cmpl $0, %ebx
    jle endwhile

    decl %ebx

    # vet[i] = &vet + (i * sizeof(t))
    leaq -72(%rbp), %r8
    movq %ebx, %eax
    imull $8, %eax
    addq %rax, %r8 //
    cvtsi2sd %r8, %xmm1

    jmp while

endwhile:

    leave
    ret