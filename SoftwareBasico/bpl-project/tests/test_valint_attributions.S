.data
.text

# Esse arquivo testa a tradução das atribuições de valint e dos valores limítrofes das constantes
# function f1 pi1
.globl f1
f1:

# pi1: -8
# vi1: -12
# vi2: -16
# vi3: -20
# vi9223372036854775807: -24

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

# movl $2147483647, %eax
# movl %eax, -12(%rbp)

# vi1 = ci+2147483647
movl $+2147483647, %eax
movl %eax, -12(%rbp)

# movl $-2147483648, %eax
# movl %eax, -16(%rbp)

# vi2 = ci-2147483648
movl $-2147483648, %eax
movl %eax, -16(%rbp)

# movl -12(%rbp), %eax
# movl %eax, -20(%rbp)

# vi3 = vi1 
movl -12(%rbp), %eax
movl %eax, -20(%rbp)

# movl %edi, %eax
# movl %eax, -24(%rbp)

# vi9223372036854775807 = pi1 
movl %edi, %eax
movl %eax, -24(%rbp)

# movl -12(%rbp), %eax

# return vi1
movl -12(%rbp), %eax
leave
ret

########################################
