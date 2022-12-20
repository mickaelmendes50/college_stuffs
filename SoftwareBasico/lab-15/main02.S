.section .rodata

.data
.globl v1
.align 2
v1: .short 1,2

.globl v2
.align 8
v2: .quad 1,2,3

.text
.globl aux
aux:
    pushq %rbp
    movq  %rsp, %rbp

    subq $32, %rsp

    movq %rbx, -24(%rbp) # salvando
    movl $2, %ebx        # i = 2

for:
    cmpl $0, %ebx
    jl endfor

    # salva os parametros da função
    movq %rdi, -8(%rbp)
    movq %rsi, -16(%rbp)

    # salva as variáveis
    movq $v2, %rdx
    movl %ebx, %ecx

    # chama a função sum
    call sum

    # decrementa o i
    decl %ebx
    jmp endfor

endfor:
    # retorna
    movq -24(%rbp), %rbx

    leave
    ret

.globl main
main:
    pushq %rbp
    movq  %rsp, %rbp

    subq $16, %rsp
    movq %r12, -8(%rbp)

    movl $0, %r12d   # i = 0
while:
    cmpl $2, %r12d
    jge endwhile

    movq $v1, %rdi
    movl %r12d, %esi
    call aux

    incl %r12d
    jmp while

endwhile:
    movl $0, %eax
    movq -8(%rbp), %r12

    leave
    ret