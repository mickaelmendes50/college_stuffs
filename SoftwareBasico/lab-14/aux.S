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
    movq  %rsp, %rbp

    # Seu código aqui...
    subq $32, %rsp # tamanho da pilha

    # esi -> i
    # rdi -> ptr
    # ecx -> x

    movl $0, %ecx

    movq $5, x
    movq $fmt, %rdi

    leave
    ret
