.section .rodata
str1: .string "'a' maior do que 'b'\n"
str2: .string "Valor de 'b': %d\n"

.data
a: .byte 97
b: .byte 105

.text

.globl main
main:
   pushq %rbp
   movq  %rsp, %rbp

   # Seu código aqui...
   movb a, %dil
   movb b, %sil
   call maximo

   movl %eax, %ebx # o %ebx é o ret

   cmpb a, %bl # if (ret == a)
   jne else

   movq $str1, %rdi
   call printf
   jmp endif
   
else:
   movq $str2, %rdi
   movsbl b, %esi
   call printf

endif:
   leave
   ret
