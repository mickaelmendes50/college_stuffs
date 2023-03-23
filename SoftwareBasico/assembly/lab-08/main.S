.section .rodata
fmt: .string "Diferença em %d/%d: %ld\n"

.data
# prods[SIZE]; SIZE = 2
.align 8
prods:
    # prods[0]
    .byte 0
    .zero 7
    .quad 0
    .int 0
    .zero 4
    # prods[1]
    .byte 0
    .zero 7
    .quad 0
    .int 0
    .zero 4

.text
.globl media
media:
    pushq %rbp
    movq %rsp, %rbp

    movl $0, %r12d      # i = 0
    movq $0, %r13       # soma = 0

for:
    movslq %r12d, %rbx # rbx = (long)i
    cmpq %rsi, %rbx
    jge endfor

    # vet[i] = &vet + (i * sizeof(T))
    imulq $24, %rbx
    addq %rdi, %rbx     # rbx = vet[i]
    addq 8(%rbx), %r13

    incl %r12d
    jmp for

endfor:
    movq %r13, %rax      # rax = soma 
    cqto                # rdx = sinal 
    idivq %rsi          # rax = quociente

    leave
    ret

.globl main
main:
    pushq %rbp
    movq %rsp, %rbp
    subq $16, %rsp

    movl $0, %r8d            # i = 0
    
    movq $prods, %r10        # r10 = &prods[0]
    movb $1, (%r10)          # prods[0].mes   = JAN;
    movq $100, 8(%r10)       # prods[0].preco = 100;
    movl $2020, 16(%r10)     # prods[0].ano   = 2020;
    movb $2, 24(%r10)        # prods[1].mes   = FEV;
    movq $120, 32(%r10)      # prods[1].preco = 120;
    movl $2020, 40(%r10)     # prods[1].ano   = 2020;

    movq %r8, -8(%rbp)       # salva o i

    movq $prods, %rdi
    movq $2, %rsi
    call media

    movq -8(%rbp), %r8       # recupera o i

    movq %rax, %r9           # long m = media(prods, SIZE);

while:
    cmpl $2, %r8d
    jge endwhile

    movq %r8, -8(%rbp)       # salva o i
    movq %r9, -16(%rbp)      # salva o m

    # vet[i] = &vet + (i * sizeof(T))
    movq $prods, %r10        # r10 = &prods
    movslq %r8d, %r11         # r11 = i
    imulq $24, %r11          # i * sizeof(struct)   que tem tam. 24
    addq %r10, %r11          # r11 = &vet + r11 --- ou seja ---- r11 = vet[i]

    # (int)prods[i].mes, prods[i].ano, prods[i].preco - m
    movq $fmt, %rdi          # passa a string como 1 param
    movsbl (%r11), %esi      # passa o 2 param
    movl 16(%r11), %edx      # passa o 3 param
    movq 8(%r11), %rcx
    subq %r9, %rcx           # preco - m
    movl $0, %eax
    call printf

    movq -8(%rbp), %r8       # recupera o i
    movq -16(%rbp), %r9      # recupera o m

    incl %r8d
    jmp while

endwhile:
    movl $0, %eax

    leave
    ret