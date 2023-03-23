.section .rodata
fmt: .string "Soma: %ld\n"

.data
.align 8
sum: .quad 0

.align 8
vet: .quad 10, 20, 30, 40, 50

.text

.globl main
main:
   pushq %rbp
   movq  %rsp, %rbp

   # Inicializações de 'i' e 'ptr' aqui...
   movl $0, %ecx
   movq $vet, %r8

beginwhile:
   cmpl $5, %ecx
   jge  endwhile      # while() {

   # Bloco do while aqui...
   movq (%r8), %rax
   addq %rax, sum

   addq $8, %r8
   inc %ecx

   jmp beginwhile     # }
endwhile:

   movq $fmt, %rdi    # printf()
   movq sum, %rsi
   movl $0, %eax
   call printf

   movl $0, %eax      # return 0
   leave
   ret
