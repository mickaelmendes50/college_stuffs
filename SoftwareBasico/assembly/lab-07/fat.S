.section .rodata
fmt: .string "%d o edi entrou no if\n"

.data

.text
.globl fat
fat:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp          // aloca o espaco na pilha

    movq %rdi, -8(%rbp)     // salva o n

    cmpl $0, %edi           // n > 0 ?
    jle endif               // jump endif
    
    subl $1, %edi           // subtrai 1 de n e mantém no %edi
    call fat                // chama o fat passando o n-1

    imull -8(%rbp), %eax    // multiplica n pelo valor de fat

    leave
    ret

endif:
    movl $1, %eax

    leave
    ret
