.section .rodata
BLUE: .quad 1
RED: .quad 2
fmt: .string "color: %ld, filled: %d\n"

.data
.align 8
c1:
    .zero 32

.text
.globl main
main:
    pushq %rbp
    movq %rsp, %rbp

    movq $c1, %r8
    movl $10, (%r8) // c1.x = 10;

    movl (%r8), %r9d
    imull $2, %r9d
    movl %r9d, 8(%r8) // c1.y = 2 * c1.x;

    movb $1, 16(%r8) // c1.filled = 1;

    cmpl $30, 8(%r8)
    jle second

    movq RED, %r9
    movq %r9, 24(%r8) // c1.color = RED;

second:
    cmpb $1, 16(%r8)
    jne else

    movq RED, %r9
    movq %r9, 24(%r8) // c1.color = RED;
    jmp endif

else:
    movq BLUE, %r9
    movq %r9, 24(%r8) // c1.color = BLUE;

endif:
    movq $fmt, %rdi
    movq 24(%r8), %rsi
    movl 16(%r8), %edx
    movl $0, %eax     # zerar o registrador eax
    call printf

    leave
    ret
