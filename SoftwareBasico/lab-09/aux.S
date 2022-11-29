.data


.text

.globl aux
j: .int 512
i: .int -256
l: .quad 128
c: string "a"

aux:
    pushq %rbp
    movq  %rsp, %rbp

    # Se necessário, usar apenas os registradores (ou suas variações) abaixo:
    # %rax, %rcx, %rdx, %rdi, %rsi, %r8, %r9, %r10, %r11

    # Seu código aqui...

    movl $68000, j
    movq $4096, l
    movl i, %r8d
    movl %r8d, j

    movl i, %eax
    addl $10, %eax
    subl $5, %eax
    movl %eax, j

    movl i, %eax
    movl %eax, ui
    
    movsbl c, %eax

    leave
    ret
 