.section .rodata
fmt: .string "Hello"

.data
.align 4
val: .int 432

.align 2
age: .word 4

.align 4
r: .int 0

.align 8
err: .quad 2048

.text

.globl main
main:
   pushq %rbp
   movq  %rsp, %rbp

   # sum("Hello", val, age, &r);
   movq $fmt, %rdi
   movl val, %esi
   movw age, %dx
   movq $r, %rcx
   call sum

   # val = sum()
   movl %eax, val

   # show(err, val, r);
   movq err, %rdi
   movl val, %esi
   movl r, %edx
   call show

   leave
   ret
