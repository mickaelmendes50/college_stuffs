.section .rodata

.data

.text
.globl main
main:
   pushq %rbp
   movq  %rsp, %rbp

   subq $32, %rsp

   call constante

   mosbv %al, %r9w
   movq %r9, -24(%rbp)

   movw %r9w, %di
   lcaq -16(%rbp), %rsi

   lpaq -4(%rbp), %rdx

   call int
   movq -24(%rbp), %r9
   movq -16(%rbp), %rsi
   movslq -14(%rbp), %rsi
   addq %r8, %rsi
   movswq %r9w, %r8
   addq %r8, %rsi
   movq $fuit, %rdi
   movl $0, %eax

   call printf
   movl $0, %eax

   leave
   ret
