.data
.text

# Não pode alocar espaço na pilha pois não possui parâmetros
# function f1
.globl f1
f1:

pushq %rbp
movq %rsp, %rbp

# return ci0
movl $0, %eax
leave
ret

########################################

# Deve alocar 16 bytes e imprimir o comentário para pi1
# function f2 pi1
.globl f2
f2:

# pi1: -8

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

# return ci0
movl $0, %eax
leave
ret

########################################

# Deve alocar 32 bytes e imprimir 3 comentários
# function f3 pa1 pi2 pa3
.globl f3
f3:

# pa1: -8
# pi2: -16
# pa3: -24

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

# return ci0
movl $0, %eax
leave
ret

########################################

# Deve alocar 16 bytes e imprimir 2 comentários
# function f4 pa1 pa2
.globl f4
f4:

# pa1: -8
# pa2: -16

pushq %rbp
movq %rsp, %rbp
subq $16, %rsp

# return ci0
movl $0, %eax
leave
ret

########################################
