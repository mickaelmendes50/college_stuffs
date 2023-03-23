.section .rodata

.data

.text
.globl calc1
calc1:
    pushq %rbp
    movq %rsp, %rbp

    // xmm0 = a (double) sd
    // xmm1 = b (float) ss

    cvtss2sd %xmm1, %xmm1   // xmm1 = (double)b

    movsd %xmm0, %xmm2      // xmm2 = a
    addsd %xmm1, %xmm2      // xmm2 = a+b

    movsd %xmm0, %xmm3      // xmm3 = a
    subsd %xmm1, %xmm3      // xmm3 = a-b

    mulsd %xmm2, %xmm3      // xmm3 = (a+b)*(a-b)

    // return (double) sd
    movsd %xmm3, %xmm0

    leave
    ret
    