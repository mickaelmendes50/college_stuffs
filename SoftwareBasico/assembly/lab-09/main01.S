.section .rodata
fmt: .string "Soma: %ld\n"

.data

.text
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    # s = %bx
    movl $0, -8(%rbp)
    movq $0, -16(%rbp)

    call constante
    movw %ax, %bx

    movw %ax, %di
    leaq -16(%rbp), %rsi
    leaq -8(%rbp), %rdx
    call init

    movq $fmt, %rdi
    addq -8(%rbp), %rbx
    addq -16(%rbp), %rbx
    movq %rbx, %rsi
    call printf

    leave
    ret
