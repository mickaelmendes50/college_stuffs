.data
.globl last
.align 8
last: .quad 0

.globl values
.align 8
values: .quad 50,-10,60,-20,70

.text

.globl swap
swap:
    pushq %rbp
    movq  %rsp, %rbp

    # Seu código aqui...
    movl $4, %edx

    # começa o for
    movl $0, %eax # i = 0

    beginfor:
        cmpl %edx, %eax # i >= j
        jge endfor

        movq $values, %r10
        movslq %eax, %r11
        imulq $8, %r11

        addq %r11, %r10
        movq (%r10), %rsi

        incl %eax
        decl %edx
        jmp beginfor

    endfor:    

    leave
    ret


    