.section .rodata
fmt: .string "%d\n"

.text
.globl show
show:
    pushq %rbp
    movq %rsp, %rbp

    subq $32, %rsp

    movl $0, %ecx           # i = 0
for:
    cmpl %esi, %ecx
    jge endfor

    movq %rdi, -8(%rbp)     # v salvo na pilha
    movq %rsi, -16(%rbp)    # size salvo na pilha
    movq %rcx, -24(%rbp)    # i salvo na pilha

    # printf("%d\n", v[i]);
    # v[i] = &v + (i * sizeof(int))
    movq $vet, %r9
    movslq %ecx, %r10
    imulq $4, %r10
    addq %r9, %r10

    movq $fmt, %rdi    # primeiro param do printf
    movl (%r10d), %esi # segundo param do printf
    movl $0, %eax      # nenhum ponto flutuante

    call printf

    movq -8(%rbp), %rdi     # v recuperado da pilha
    movq -16(%rbp), %rsi    # size recuperado da pilha
    movq -24(%rbp), %rcx    # i recuperado da pilha

    incl %ecx               # i++
    jmp for                 # repete o for

endfor:
    leave
    ret
