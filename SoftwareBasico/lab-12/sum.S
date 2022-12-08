.data
.globl s
s: .int 0

.globl nums
nums: .int 65,-105,111,34

.text

.globl sum
sum:
    pushq %rbp
    movq  %rsp, %rbp

    # Seu código aqui...
    i: .int 0
    movl i, %ecx

    leave
    ret

loop: 
    cmpl $4, %ecx
    jge after
    
    movq $nums, %rdx
    movswq i, %rcx
    imulq $4, %rcx
    addq %rdx, %rcx
    movl (%rcx), %eax
    addl %eax, s

    incl %ecx
    jmp loop

after:    
    leave
    ret
