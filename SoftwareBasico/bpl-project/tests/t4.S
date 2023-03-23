.data
.text

# function f1 pi1 pa2
.globl f1
f1:

# pi1: -8
# pa2: -16

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

# return pi1
movl %edi, %eax
leave
ret

########################################
# function f2 pa1
.globl f2
f2:

# pa1: -8
# vi1: -12
# vi2: -16
# va3: -136

pushq %rbp
movq %rsp, %rbp
subq $144, %rsp

# vi1 = ci1
movl $1, %eax
movl %eax, -12(%rbp)

# vi2 = call f1 vi1 va3

# Salva o 1-ésimo parâmetro
movq %rdi, -8(%rbp)

movl -12(%rbp), %edi
movq -136(%rbp), %rsi
call f1

# Recupera o 1-ésimo parâmetro
movq -8(%rbp), %rdi

movl %eax, -16(%rbp)

# vi2 = call f1 ci5 pa1 

# Salva o 1-ésimo parâmetro
movq %rdi, -8(%rbp)

movl $5, %edi
movq -8(%rbp), %rsi
call f1

# Recupera o 1-ésimo parâmetro
movq -8(%rbp), %rdi

movl %eax, -16(%rbp)

# return vi2
movl -16(%rbp), %eax
leave
ret

########################################
