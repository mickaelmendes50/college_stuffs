.section .rodata
str1: .string "Iteração %d, v = %d\n"

.data

.align 4
i: .int 0

.align 2
v: .word 0

.align 2
vetA: .word 28,42,16,23,47

.align 4
vetB: .int 0,0,0,0,0

.text

.globl main
main:
    pushq %rbp
    movq %rsp, %rbp

while:
    cmpl $5, i      # while (i < 5) {
    jge endwhile

                    # v = vetA[i] << 2;
    # vetA[i] = &vet + (i * sizeof(short))
    movq $vetA, %r10
    movslq i, %r11
    imulq $2, %r11
    addq %r10, %r11

    movw (%r11), %r12w
    shlw $2, %r12w  # vetA[i] << 2
    movw %r12w, v

    # printf("Iteração %d, v = %d\n", i, (int)v);
    movq $str1, %rdi
    movl i, %esi
    movswl v, %edx
    movl $0, %eax
    call printf

    # vetB[i] = &vetB + (i * sizeof(int))
    movq $ vetB, %r10
    movslq i, %r11
    imulq $4, %r11
    addq %r10, %r11

    # process(i, v, &vetB[i]);
    movl i, %edi
    movw v, %si
    movl %r11d, %edx
    call process

    
    incl i          # i++; 
    jmp while

endwhile:
    # show(vetB, 5);
    movq $vetB, %rdi
    movq $5, %rsi
    call show
    
    movl $0, %eax       # return 0
    leave
    ret
