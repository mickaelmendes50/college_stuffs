.data
.globl vet
.align 2
vet: .word 50, 10, 67, 42

.globl max
.align 2
max: .word 0

.text
.globl ex01
ex01: 
    pushq %rbp
    movq  %rsp, %rbp

    # char i vai ser o %r8b
    movb $0, %r8b
for:
    cmpb $4, %r8b # (i < 4)
    jge endfor

    # vet[i] = $vet + (i * sizeof(short))
    movq $vet, %rax     # salva a posição do vet
    movsbq %r8b, %rcx
    imulq $2, %rcx
    addq %rcx, %rax
    movw (%rax), %dx

    cmpw max, %dx # (vet[i] > max)
    jle endif

    movw %dx, max # max = vet[i];

endif:
    incb %r8b
    jmp for

endfor:
    leave
    ret
