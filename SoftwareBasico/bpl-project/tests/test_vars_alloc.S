.data
.text

# Alloc: 8+4+4*30+4 -> 144
# Offsets: -8, -12, -132, -136
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

# Alloc: 8+8+40+80+4 -> 144
# Offsets: -8, -16, -56, -136, -140
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

# Alloc: 65536 -> 65536 (maximum array size)
# Offsets: -65536
# function f4
.globl f4
f4:
# va10: -65536

pushq %rbp
movq %rsp, %rbp
subq $65536, %rsp

# return ci-10
movl $-10, %eax
leave
ret

########################################
