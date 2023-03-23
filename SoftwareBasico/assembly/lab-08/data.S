.section .rodata
fmt: .string "%ld\n"

.data

.text
.globl show
show:
    pushq %rbp
    movq %rsp, %rbp

    movl $0, %r8d // i = 0
    leaq 8(%rdi), %r9

for:
    cmpl (%rdi), %r8d
    jge endfor

    # ptr[i] = $ptr + (i * sizeof(long))
    movq %r9, %rax     # salva a posição do vet
    movslq %r8d, %rcx
    imulq $8, %rcx
    addq %rcx, %rax
    movq (%rax), %rsi

    movq $fmt, %rdi
    call printf

    addl $1, %r8d
    jmp for

endfor:
    leave
    ret
