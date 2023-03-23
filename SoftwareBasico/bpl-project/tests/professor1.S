.data
.text

# function f1 pa1 pa2 pi3
.globl f1
f1:

# pa1: -8
# pa2: -16
# pi3: -24
# vi1: -28
# vi2: -32
# vi3: -36
# vi4: -40
# va5: -80

pushq %rbp
movq %rsp, %rbp
subq $80, %rsp

# cltd apaga pi3 (edx) -> idivl %edx (incorreto)

# vi1 = vi1 / pi3
movl -28(%rbp), %eax

# Salva o 3-ésimo parâmetro
movq %rdx, -24(%rbp)

cltd
idivl %edx

# Recupera o 3-ésimo parâmetro
movq -24(%rbp), %rdx

movl %eax, -28(%rbp)

# problema com constante
# ok

# vi1 = ci1
movl $1, %eax
movl %eax, -28(%rbp)
# incorreto

# vi1 = ci1024
movl $1244, %eax
movl %eax, -28(%rbp)
# ok

# return ci-2222
movl $-2222, %eax
leave
ret
# incorreto

# return ci-2048
movl $-2448, %eax
leave
ret

# Passage de 'va' usando 'movq' em vez de 'leaq'

# vi1 = call f2 va5

# Salva o 1-ésimo parâmetro
movq %rdi, -8(%rbp)


# Salva o 2-ésimo parâmetro
movq %rsi, -16(%rbp)


# Salva o 3-ésimo parâmetro
movq %rdx, -24(%rbp)

movq -80(%rbp), %rdi
call f2

# Recupera o 1-ésimo parâmetro
movq -8(%rbp), %rdi


# Recupera o 2-ésimo parâmetro
movq -16(%rbp), %rsi


# Recupera o 3-ésimo parâmetro
movq -24(%rbp), %rdx

movl %eax, -28(%rbp)


# return ci0
movl $0, %eax
leave
ret

########################################
