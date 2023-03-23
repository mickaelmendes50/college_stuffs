.data
.text

# Esse arquivo testa as instruções de acesso aos arrays

# function f1 pi1 pa2
.globl f1
f1:

# pi1: -8
# pa2: -16

# vi1: -20
# va2: -40

pushq %rbp
movq %rsp, %rbp
subq $48, %rsp

# movq $0, %rax
# imulq $4, %rax
# leaq -40(%rbp), %r8
# addq %r8, %rax
# movl $2, (%rax)

# set va2 index ci0 with ci2 
movq $0, %rax
imulq $4, %rax
leaq -40(%rbp), %r8
addq %r8, %rax
movl $2, (%rax)

# movq $5, %rax
# imulq $4, %rax
# addq %rsi, %rax
# movl -20(%rbp), %r8d
# movl %r8d, (%rax)

# set pa2 index ci5 with vi1
movq $5, %rax
imulq $4, %rax
addq %rsi, %rax
movl -20(%rbp), %r8d
movl %r8d, (%rax)

# movq $10, %rax
# imulq $4, %rax
# leaq -40(%rbp), %r8
# addq %r8, %rax
# movl %edi, (%rax)

# set va2 index ci10 with pi1 
movq $10, %rax
imulq $4, %rax
leaq -40(%rbp), %r8
addq %r8, %rax
movl %edi, (%rax)

# movq $0, %rax
# imulq $4, %rax
# leaq -40(%rbp), %r8
# addq %r8, %rax
# movl (%rax), %r8d
# movl %r8d, -20(%rbp)

# get va2 index ci0 to vi1
movq $0, %rax
imulq $4, %rax
leaq -40(%rbp), %r8
addq %r8, %rax
movl (%rax), %r8d
movl %r8d, -20(%rbp)

# movq $5, %rax
# imulq $4, %rax
# addq %rsi, %rax
# movl (%rax), %r8d
# movl %r8d, -20(%rbp)

# get pa2 index ci5 to vi1
movq $5, %rax
imulq $4, %rax
addq %rsi, %rax
movl (%rax), %r8d
movl %r8d, -20(%rbp)


# return pi1
movl %edi, %eax
leave
ret

########################################
