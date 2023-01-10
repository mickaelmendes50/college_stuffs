.section .rodata

.data

.align 8
c1:
    .int 0
    .int 0
    .byte 0
    .zero 7
    .quad 0

.text
.globl main
main:
    pushq %rbp
    movq  %rsp, %rbp

    movq $c1, %r8
    movl $10, (%r8) # c1.x = 10
    movl (%r8), %eax
    imull $2, %eax # aex = c1.x * 2
    movl %eax, 4(%r8) # c1.y = eax
    movb $1, 8(%r8) # filler = 1

    cmpl $30, 4(%r8)
    jg bloco
    cmpb $1, 8(%r8)
    jne else

bloco:
    movq $2, 16(%r8)
    jmp endif

else:
    movq $1, 16(%r8)

endif:
    leave
    ret
