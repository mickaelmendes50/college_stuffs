.section .rodata
fmt: .string "a = %f, b = %f, e = %f\n"

.data

.text
.globl calc2
calc2:  // (float a = xmm0, float b = xmm1)
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    # a -> -4(%rbp) 
    # b -> -8(%rbp) 
    movss %xmm0, -4(%rbp) # salva 'a' 
    movss %xmm1, -8(%rbp) # salva 'b'

    // double e = a + cos(b);
    cvtss2sd %xmm1, %xmm0 // passei o b pro xmm0
    call cos              // chamei a func 

    # salva o retorno em outro registrador 
    movsd %xmm0, %xmm3 # xmm3 = cos(b)

    movss -4(%rbp), %xmm0  # recupera 'a' 
    movss -8(%rbp), %xmm1  # recupera 'b'

    cvtss2sd %xmm0, %xmm0
    cvtss2sd %xmm1, %xmm1
    addsd %xmm0, %xmm3

    // printf("a = %f, b = %f, e = %f\n", a, b, e);
    movq $fmt, %rdi
    movsd %xmm3, %xmm2
    movl $3, %eax
    call printf

    // return b; (float)
    movss -8(%rbp), %xmm0

    leave
    ret