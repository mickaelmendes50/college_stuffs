.data
# Não precisa do align pois o alinhamento é 1
.globl str
str: .string "BEBAMUITOCAFE"

.text
.globl process
process:
   pushq %rbp
   movq  %rsp, %rbp

   # ptr = str
   movq $str, %r8 # %r8 será o ptr

beginwhile:
   cmpb $0, (%r8)
   je endwhile            # while() {

   # Bloco do while
   addl $32, (%r8)
   inc %r8

   jmp beginwhile         # }
endwhile:
   leave
   ret
