.data
.text

# function f1
.globl f1
f1:
# vi1: -4
# va2: -44

pushq %rbp
movq %rsp, %rbp
subq $48, %rsp

# vi1 = ci3
movl $3, %eax
movl %eax, -4(%rbp)

#Linha: if vi1
cmpl $0, -4(%rbp)
je .L1

# vi1 = ci0
movl $0, %eax
movl %eax, -4(%rbp)
.L1:

#Linha: if vi1
cmpl $0, -4(%rbp)
je .L2

# get va2 index ci8 to vi1
movq $8, %rax
imulq $4, %rax
leaq -44(%rbp), %r8
addq %r8, %rax
movl (%rax), %r8d
movl %r8d, -4(%rbp)
.L2:

#Linha: if vi1
cmpl $0, -4(%rbp)
je .L3

# return vi1
movl -4(%rbp), %eax
leave
ret
.L3:

# return ci-1
movl $-1, %eax
leave
ret

########################################
