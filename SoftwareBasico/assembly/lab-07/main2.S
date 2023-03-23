.section .rodata
fmt: .string "rdi = %d, esi = %d\n"

.data
.align 2
.globl v1
v1: .word 1, 2

.align 8
.globl v2
v2: .quad 1, 2, 3

.text
.globl aux
aux:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movl $2, -8(%rbp)       // i = 2
for:
    cmp $0, -8(%rbp)        // i >= 0
    jl endfor               // se i for menor, pula pro endfor
    
    movq $v2, %rdx
    movl -8(%rbp), %ecx

    call sum

    subl $1, -8(%rbp)       // i--
    jmp for

endfor:

    leave
    ret

.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movl $0, -8(%rbp)       // i = 0
while:
    cmp $2, -8(%rbp) 
    jge endwhile

    movq $v1, %rdi
    movl -8(%rbp), %esi
    call aux

    addl $1, -8(%rbp) 
    jmp while

endwhile:
    movl $0, %eax
    leave
    ret
