.data
.text

# Comment 1
# function f1 pi1 pi2 pi3
.globl f1
f1:

# pi1: -8
# pi2: -16
# pi3: -24

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

# return ci0
movl $0, %eax
leave
ret

########################################

# Comment 2
# function f2 pi1 pi2 pa3
.globl f2
f2:

# pi1: -8
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

# Comment 3
# function f3 pi1 pa2 pi3
.globl f3
f3:

# pi1: -8
# pa2: -16
# pi3: -24

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

# return ci0
movl $0, %eax
leave
ret

########################################

# Comment 4
# function f4 pi1 pa2 pa3
.globl f4
f4:

# pi1: -8
# pa2: -16
# pa3: -24

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

# return ci0
movl $0, %eax
leave
ret

########################################

# Comment 5
# function f5 pa1 pi2 pi3
.globl f5
f5:

# pa1: -8
# pi2: -16
# pi3: -24

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

# return ci0
movl $0, %eax
leave
ret

########################################

# Comment 6
# function f6 pa1 pi2 pa3
.globl f6
f6:

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

# Comment 7
# function f7 pa1 pa2 pi3
.globl f7
f7:

# pa1: -8
# pa2: -16
# pi3: -24

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

# return ci0
movl $0, %eax
leave
ret

########################################

# Comment 8
# function f8 pa1 pa2 pa3
.globl f8
f8:

# pa1: -8
# pa2: -16
# pa3: -24

pushq %rbp
movq %rsp, %rbp
subq $32, %rsp

# return ci0
movl $0, %eax
leave
ret

########################################
