.section .rodata
fmt: .string "Dividend: %d\nDivisor: %d\nQuotient: %d\nRest: %d\n"

.data
  .globl pDividend1
  .align 4
  pDividend1: .long 400

  .globl pDivisor1
  .align 4
  pDivisor1: .long 3

.text
  .globl main
  main:
    pushq %rbp
    movq %rsp, %rbp

    # tests if we can divide 2 positive integers using idiv
    movl pDividend1, %eax
    cltd
    idivl pDivisor1

    # calls printf to check the divisions's quotient
    movl %edx, %r8d # Passing the rest as the 5º param
    movl %eax, %ecx # Passing the quotient as the 4º param
    movq $fmt, %rdi # Passing the fmt string as the 1º param
    movl pDividend1, %esi # Passing the dividend as the 2º param
    movl pDivisor1, %edx # Passing the divisor as the 3º param
    movq $0, %rax
    call printf

    leave
    ret