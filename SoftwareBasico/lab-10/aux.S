.data

# Definição da variável 'str' aqui...
.globl str
.align 1
    str: .string "BEBAMUITOCAFE"

.text

.globl process

process:
   pushq %rbp
   movq  %rsp, %rbp

   # Inicialização de 'ptr' aqui...
   # ptr = str
   movq $str, (%r8)

beginwhile:
   cmpb $0, (%r8)
   je endwhile            # while() {
   
   # Bloco do while
   addb $32, (%r8)
   incq (%r8)
   
   jmp beginwhile         # }

endwhile:
   leave
   ret
