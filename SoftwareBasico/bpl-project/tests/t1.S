.data
.text

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
