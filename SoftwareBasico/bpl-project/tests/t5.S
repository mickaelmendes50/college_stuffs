.data
.text

# function f1 pi1 pa2
.globl f1
f1:

# pi1: -8
# pa2: -16
# vi1: -20
# va2: -60

pushq %rbp
movq %rsp, %rbp
subq $64, %rsp

# vi1 = pi1 + ci1
movl %edi, %eax
addl $1, %eax
movl %eax, -20(%rbp)

# set va2 index ci5 with ci2 
movq $5, %rax
imulq $4, %rax
leaq -60(%rbp), %r8
addq %r8, %rax
movl $2, (%rax)

# set pa2 index ci0 with vi1 
movq $0, %rax
imulq $4, %rax
addq %rsi, %rax
movl -20(%rbp), %r8d
movl %r8d, (%rax)

# get va2 index ci8 to vi1
movq $8, %rax
imulq $4, %rax
leaq -60(%rbp), %r8
addq %r8, %rax
movl (%rax), %r8d
movl %r8d, -20(%rbp)

# return pi1
movl %edi, %eax
leave
ret

########################################
