.section .rodata
fmt: .string "%d\n"

.data

.text
.globl show
show:
    pushq %rbp
    movq  %rsp, %rbp

    # Seu código aqui...
    subq $32, %rsp # tamanho da pilha

    # rdi -> v
    # esi -> size
    # ecx -> i

    movl $0, %ecx

begin_for:
    cmp  %esi, %ecx # if ()
    jge end_for

    movq %rdi, -8(%rbp)
    movq %rsi, -16(%rbp)
    movq %rcx, -24(%rbp)

    # printf
    # rdi -> &v
    movslq %ecx, %r8
    imulq $4, %r8
    addq %rdi, %r8 # r8 = &vet[i]
    movl (%r8), %esi

    movq $fmt, %rdi

    movl $0, %eax
    call printf

    movq -8(%rbp), %rdi
    movq -16(%rbp), %rsi
    movq -24(%rbp), %rcx

    incl %ecx
    jmp begin_for

end_for:

   leave
   ret
