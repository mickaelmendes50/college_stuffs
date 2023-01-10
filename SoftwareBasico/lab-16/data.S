.section .rodata

.data

.text

.globl show
show:
    pushq %rbp
    movq  %rsp, %rbp

    subq $32, %rsp
    movq %rdi, %r9
    addq $8, %r9
    movl $0, %rd8

loop:
    cmpl (%rdi), %r8d
    jge endloop

    movq %r9, %r10
    movslq %r8d, %r11
    imullq $8, %r11
    addq %r10, %r11

    movq %rdi, -8(%rbp)
    movq %r8, -16(%rbp)
    movq %r9, -24(%rbp)

    movq $str, %rdi
    movq(%r11), %rsi
    movl $0, %eax
    call printf

    movq -8(%rbp), %rdi
    movq -16(%rbp), %r8
    movq -24(%rbp), %r9

    leave
    ret
