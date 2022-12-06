.section .rodata

.data
.globl a
a: .int 30
.globl b
b: .int 45
.globl c
c: .int -60
.globl d
d: .int 25

.text

.globl ex01

ex01:
   pushq %rbp
   movq  %rsp, %rbp

   # Move as variaveis pra registradores
   # pq não dá pra usar elas diretamente
   # na comparação
   movl a, %eax
   movl b, %ecx

   # Faz a comparação com cmpl e jle (jump less equal)
   cmpl %ecx, %eax
   jle endif
   
   # Troca o sinal do C
   negl c
   # Faz a divisão
   movl c, %eax
   cltd 
   movl $3, %ecx
   idiv %ecx
   movl %eax, d
   ##

   leave
   ret

endif:
   cmpl %eax, b
   jl fim
   
   addl b, %eax
   imull c, %eax
   movl %eax, c
   movl $1024, d
   
   leave
   ret

fim:
   leave
   ret
