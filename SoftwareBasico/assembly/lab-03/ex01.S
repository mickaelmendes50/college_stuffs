.section .rodata

.data
.globl a
.align 4
a: .int 30

.globl b 
.align 4
b: .int 45

.globl c
.align 4
c: .int -60

.globl d
.align 4
d: .int 25

.text
.globl ex01
ex01:
   pushq %rbp
   movq  %rsp, %rbp

   # Move as variaveis pra registradores
   # pq não dá pra usar elas diretamente
   # na comparação
   movl a, %r8d
   movl b, %r9d

   # Faz o if (a > b)
   cmpl %r9d, %r8d
   jle next
   
   negl c # Troca o sinal do c
   
   # A divisão d = c / 3 -> o C vai pra eax
   movl c, %eax 
   cltd           # completa o edx com o bit do sinal de c
   movl $3, %ecx
   idiv %ecx      # efetua a divisão
   movl %eax, d   # salva o valor na variavel

next:
   # Faz o if (b >= a)
   cmp %r8d, %r9d
   jl endifs
      
   # c = (a + b) * c;
   addl %r8d, %r9d
   movl c, %r10d
   imull %r9d, %r10d
   movl %r10d, c

   movl $1024, d # d = 1024;

endifs:
   leave
   ret
