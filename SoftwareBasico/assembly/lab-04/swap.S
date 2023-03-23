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

    # o int i vai ser o %eax
    movl $4, %ebx # int j = 4;

    # começando o for
    movl $0, %eax
for:
    cmpl %ebx, %eax # i < j
    jge endfor

    # o %rcx vai ser o tmp
    # o endereco inicial de values será o %r8
    movq $values, %r8

    # long tmp = values[i];
    # values[i] = &values + (i * sizeof(long))
    movslq %eax, %r9
    imulq $8, %r9
    addq %r8, %r9
    movq (%r9), %rcx # o valor de values[i] foi salvo no tmp (%rcx)

    # values[i] = values[j];
    # values[j] = &values + (j * sizeof(long))
    movslq %ebx, %r10
    imulq $8, %r10
    addq %r8, %r10
    movq (%r10), %rdx   # move o valor do values[j] pra um registrador
    movq %rdx, (%r9)    # atribui o valor do values[j] no values[i]

    # values[j] = tmp;
    movq %rcx, (%r10)   # atribui o valor do tmp (%rcx) no values[j]

    incl %eax           # incrementa o i
    decl %ebx           # decrementa o j
    jmp for

endfor:
    # last = values[4];
    # values[4] = &values + (4 * sizeof(long))
    movabs $4, %r11
    imulq $8, %r11
    addq %r8, %r11
    movq (%r11), %rsi
    movq %rsi, last

    leave
    ret
