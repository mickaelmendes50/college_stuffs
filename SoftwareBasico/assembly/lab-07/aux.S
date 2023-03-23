.section .rodata
fmt: .string "Valor: x = %ld, i = %d\n"

.data
.globl x
.align 8
x: .quad 10

.text
.globl aux
aux:
    pushq %rbp
    movq %rsp, %rbp

    subq $16, %rsp          # aloca o espaço na pilha

    movq $5, x              # x = 5

    movq %rdi, -8(%rbp)     # salva o 1 param (i)
    movq %rsi, -16(%rbp)    # salva o 2 param (ptr)

    # printf("Valor: x = %ld, i = %d\n", x, i);
    movl %edi, %edx         # move o i pro 3 param
    movq $fmt, %rdi         # move a string pro 1 param
    movq x, %rsi            # move o x pro 2 param
    movl $0, %eax
    call printf

    movq -8(%rbp), %rdi     # recupera o i 
    movq -16(%rbp), %rsi    # recupera o ptr

    # return x + i + *ptr;
    movslq %edi, %rax
    addq x, %rax
    addq (%rsi), %rax

    leave
    ret
