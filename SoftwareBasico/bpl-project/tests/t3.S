.data
.text

# function f1 pi1
.globl f1
f1:

# pi1: -8
# vi1: -12
# vi2: -16

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

# vi1 = ci1
movl $1, %eax
movl %eax, -12(%rbp)

# vi2 = vi1 
movl -12(%rbp), %eax
movl %eax, -16(%rbp)

# vi1 = pi1 + vi2
movl %edi, %eax
addl -16(%rbp), %eax
movl %eax, -12(%rbp)

# vi2 = vi1 * ci-5
movl -12(%rbp), %eax
imull $-5, %eax
movl %eax, -16(%rbp)

# return vi1
movl -12(%rbp), %eax
leave
ret

########################################
