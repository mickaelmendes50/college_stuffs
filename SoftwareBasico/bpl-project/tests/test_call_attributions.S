.data
.text

# Esse arquivo testa as chamadas de função
# f1 testa a chamada com 1 salvamento e 1 pi
# f2 testa a chamada com 2 salvamentos e 1 pa e 1 vi
# f3 testa a chamada com 3 salvamentos e 1 va e 1 ci
# f4 testa a chamada com 3 salvamentos e nenhum argumento
# f5 testa a chamada sem salvamentos e 3 vi

# function f1 pi1
.globl f1
f1:

# pi1: -8

# vi1: -12

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

# movq %rdi, -8(%rbp)
# movl -8(%rbp), %edi
# call f250
# movl %eax, -12(%rbp)
# movq -8(%rbp), %rdi

# vi1 = call f250 pi1

# Salva o 1-ésimo parâmetro
movq %rdi, -8(%rbp)

movl -8(%rbp), %edi
call f250

# Recupera o 1-ésimo parâmetro
movq -8(%rbp), %rdi

movl %eax, -12(%rbp)


# return vi1
movl -12(%rbp), %eax
leave
ret

########################################

# function f2 pa1 pi2
.globl f2
f2:

# pa1: -8
# pi2: -16

# vi1: -20

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

# movq %rdi, -8(%rbp)
# movq %rsi, -16(%rbp)
# movq -8(%rbp), %rdi
# movl -20(%rbp), %esi
# call f250
# movl %eax, -20(%rbp)
# movq -8(%rbp), %rdi
# movq -16(%rbp), %rsi

# vi1 = call f250 pa1 vi1

# Salva o 1-ésimo parâmetro
movq %rdi, -8(%rbp)


# Salva o 2-ésimo parâmetro
movq %rsi, -16(%rbp)

movq -8(%rbp), %rdi
movl -20(%rbp), %esi
call f250

# Recupera o 1-ésimo parâmetro
movq -8(%rbp), %rdi


# Recupera o 2-ésimo parâmetro
movq -16(%rbp), %rsi

movl %eax, -20(%rbp)


# return vi1
movl -20(%rbp), %eax
leave
ret

########################################

# function f3 pi1 pi2 pi3
.globl f3
f3:

# pi1: -8
# pi2: -16
# pi3: -24

# vi1: -28
# va2: -428

pushq %rbp
movq %rsp, %rbp
subq $432, %rsp

# movq %rdi, -8(%rbp)
# movq %rsi, -16(%rbp)
# movq %rdx, -24(%rbp)
# movq -428(%rbp), %rdi
# movl $10, %esi
# call f250
# movl %eax, -28(%rbp)
# movq -8(%rbp), %rdi
# movq -16(%rbp), %rsi
# movq -24(%rbp), %rdx

# vi1 = call f250 va2 ci10

# Salva o 1-ésimo parâmetro
movq %rdi, -8(%rbp)


# Salva o 2-ésimo parâmetro
movq %rsi, -16(%rbp)


# Salva o 3-ésimo parâmetro
movq %rdx, -24(%rbp)

movq -428(%rbp), %rdi
movl $10, %esi
call f250

# Recupera o 1-ésimo parâmetro
movq -8(%rbp), %rdi


# Recupera o 2-ésimo parâmetro
movq -16(%rbp), %rsi


# Recupera o 3-ésimo parâmetro
movq -24(%rbp), %rdx

movl %eax, -28(%rbp)


# return vi1
movl -28(%rbp), %eax
leave
ret

########################################

# function f4 pi1 pi2 pi3
.globl f4
f4:

# pi1: -8
# pi2: -16
# pi3: -24

# vi1: -28
# va2: -428

pushq %rbp
movq %rsp, %rbp
subq $432, %rsp

# movq %rdi, -8(%rbp)
# movq %rsi, -16(%rbp)
# movq %rdx, -24(%rbp)
# call f250
# movl %eax, -28(%rbp)
# movq -8(%rbp), %rdi
# movq -16(%rbp), %rsi
# movq -24(%rbp), %rdx

# vi1 = call f250

# Salva o 1-ésimo parâmetro
movq %rdi, -8(%rbp)


# Salva o 2-ésimo parâmetro
movq %rsi, -16(%rbp)


# Salva o 3-ésimo parâmetro
movq %rdx, -24(%rbp)

call f250

# Recupera o 1-ésimo parâmetro
movq -8(%rbp), %rdi


# Recupera o 2-ésimo parâmetro
movq -16(%rbp), %rsi


# Recupera o 3-ésimo parâmetro
movq -24(%rbp), %rdx

movl %eax, -28(%rbp)


# return vi1
movl -28(%rbp), %eax
leave
ret

########################################

# function f5
.globl f5
f5:

# vi1: -4
# vi2: -8
# vi3: -12

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

# movl -4(%rbp), %edi
# movl -8(%rbp), %esi
# movl -12(%rbp), %edx
# call f250
# movl %eax, -4(%rbp)

# vi1 = call f250 vi1 vi2 vi3
movl -4(%rbp), %edi
movl -8(%rbp), %esi
movl -12(%rbp), %edx
call f250
movl %eax, -4(%rbp)


# return vi1
movl -4(%rbp), %eax
leave
ret

########################################
