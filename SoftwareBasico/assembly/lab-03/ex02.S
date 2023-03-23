.section .rodata

.data
.globl a
.align 4
a: .int 0

.globl b 
.align 8
b: .quad 2

.text
.globl ex02
ex02:
   pushq %rbp
   movq  %rsp, %rbp

   # Seu código aqui...
   movl a, %eax
   movq b, %rbx

   // if (a) {
   cmpl $0, %eax
   je return

   //   if (b < 5) {
   cmpq $5, %rbx
   jge else
   //     b = (a << 1) + (a * b);
   shll $1, %eax
   imulq a, %rbx

   movslq %eax, %rax # transforma pra 8 bytes
   addq %rax, %rbx

   movq %rbx, b

else:
   //     a = b ^ 0x1FL;
   xorq $0x1FL, %rbx
   movl %ebx, a

return:
   leave
   ret
   