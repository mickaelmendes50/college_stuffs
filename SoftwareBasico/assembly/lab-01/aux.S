# Seção para os dados
# Todas as variáveis são globais pois estão sendo usadas por um arquivo externo
.data
.globl c
c: .byte -20

.globl i
.align 4
i: .int -256

.globl j
.align 4
j: .int 512

.globl l
.align 8
l: .quad 128

.globl us
.align 2
us: .word 111

.globl ui
.align 4
ui: .int 1024

.globl ul
.align 8
ul: .quad 2048

# Seção do código
.text

.globl aux
aux:
    pushq %rbp
    movq  %rsp, %rbp

    # Se necessário, usar apenas os registradores (ou suas variações) abaixo:
    # %rax, %rcx, %rdx, %rdi, %rsi, %r8, %r9, %r10, %r11

    # Atribuições simples
    movl $68000, j # atribui constante a j
    movq $4096, l # atribui constante a l
    # i = j;
    movl j, %eax # move o valor de j para eax
    movl %eax, i # para então mover para i

    # Expressões
    # j = 10 + i - 5;
    addl $10, %eax
    subl $5, %eax
    movl %eax, j
    # i = (i * 2) - (j + 5);
    addl $5, %eax
    movl i, %ebx
    imull $2, %ebx
    subl %eax, %ebx
    movl %ebx, i

    # Casts
    # ui = i;
    movl %ebx, ui
    # j = c;
    movsbl c, %eax
    movl %eax, j
    # ul = ui;
    movl ui, %eax
    movq %rax, ul
    # us = ul;
    movw %ax, us
    # c = i + j;
    movl i, %ebx
    movl j, %ecx
    add %ebx, %ecx
    movb %cl, c

    # Ponteiros
    # *ptr -> %rbx
    movq $l, %rbx       # ptr = &l;
    movq $128, (%rbx)   # *ptr = 128;

    # *iptr -> %rcx
    movq $i, %rcx       # iptr = &i;
    # j = j + *iptr;
    movslq j, %rdx      # extendi j pra 8 bytes e armazenei em %rdx
    addq (%rcx), %rdx   # fiz a soma, salvando o valor no ponteiro iptr
    movl %edx, j        # passei o valor do poteiro para j

    leave
    ret
