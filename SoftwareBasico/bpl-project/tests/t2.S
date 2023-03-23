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
# vi1: -12
# va2: -132
# vi3: -136

pushq %rbp
movq %rsp, %rbp
subq $144, %rsp

# return ci-1
movl $-1, %eax
leave
ret

########################################
# function f3 pa1 pi2
.globl f3
f3:

# pa1: -8
# pi2: -16
# va1: -56
# va2: -136
# vi3: -140

pushq %rbp
movq %rsp, %rbp
subq $144, %rsp

# return ci5
movl $5, %eax
leave
ret

########################################
