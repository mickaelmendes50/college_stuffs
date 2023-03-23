.data
.text

# function f1 pi1
.globl f1
f1:

# pi1: -8

# vi1: -12
# va2: -52

pushq %rbp
movq %rsp, %rbp
subq $64, %rsp

# cmpl $0, -12(%rbp)
# je .L1
# movl $0, -12(%rbp)
# .L1:

#Linha: if vi1
cmpl $0, -12(%rbp)
je .L1

# vi1 = ci0
movl $0, %eax
movl %eax, -12(%rbp)
.L1:

# cmpl $0, %edi
# je .L2
# movq $8, %rax
# imull $4, %rax
# leaq -52(%rbp), %r8
# addq %r8, %rax
# movl (%rax), %r8d
# movl %r8d, -12(%rbp)
# .L2:

#Linha: if pi1
cmpl $0, %edi
je .L2

# get va2 index ci8 to vi1
movq $8, %rax
imulq $4, %rax
leaq -52(%rbp), %r8
addq %r8, %rax
movl (%rax), %r8d
movl %r8d, -12(%rbp)
.L2:

# cmpl $0, $0
# je .L3
# movl -12(%rbp), %eax
# leave
# ret
# .L3:

#Linha: if ci0
movl $0, %eax
cmpl $0, %eax
je .L3

# return vi1
movl -12(%rbp), %eax
leave
ret
.L3:

# cmpl $0, $0
# je .L4
# .L4:

#Linha: if ci0
movl $0, %eax
cmpl $0, %eax
je .L4
.L4:


# return ci-1
movl $-1, %eax
leave
ret

########################################
