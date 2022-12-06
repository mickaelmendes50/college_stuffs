.section .rodata

.data
.globl a
a: .int 0
.globl b
b: .quad 2

.text
.globl ex02
ex02:
   pushq %rbp
   movq  %rsp, %rbp

   # Seu código aqui...
   movl a, %eax
   cmpl $0, %eax
   je endif
   
   cmpq $5, b
   jge endif

   leave
   ret

endif:
   leave
   ret
