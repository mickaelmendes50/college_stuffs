.section .rodata

.data

.align 4
i: .int 0

.align 8
bias: .quad 256

vet: .byte 12, 3, 20, 8

.text

.globl main
main:
   pushq %rbp
   movq  %rsp, %rbp

for:                                # for (i = 0; i < LEN; i++) {
    cmp $4, i
    jge endfor
    
    # bias = filtro(vet[i], LIM, bias);
    # vet[i] = &vet + (i * sizeof(char))
    movq $vet, %r10
    movslq i, %r11
    addq %r11, %r10
    
    movb (%r10), %dil   # Passo o valor direto pra %dil pq vai ser usado na chamda de funcao
    movw $10, %si       # segundo parametro
    movq bias, %rdx     # terceiro parametro
    call filtro         # chama a funcao

    movq %rax, bias     # faz a atribuição do bias

    incl i
    jmp for

endfor:                             # }
   leave
   ret
