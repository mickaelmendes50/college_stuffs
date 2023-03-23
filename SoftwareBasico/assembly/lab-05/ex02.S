.data
.globl letters
letters: .string "abcdefghij"

.globl even
.align 4
even: .int 0

.globl odd
.align 4
odd: .int 0 

.text
.globl ex02
ex02:
    pushq %rbp
    movq  %rsp, %rbp

    movl $0, %eax   # unsigned int count = 0;

while:              # while (letters[count]) {
    # letters[count] = &letters + (count * sizeof(char))
    movq $letters, %r8
    movl %eax, %r9d
    imulq $1, %r9
    addq %r8, %r9
    movb (%r9), %r10b

    cmpb $0, %r10b
    je endwhile

    movl %eax, %edx     # salva o valor do count
    incl %eax           # faz o incremento no count

    movl %eax, %r11d
    imulq $1, %r11
    addq %r8, %r11 

    //  if (letters[count++] & 1)
    testb $1, (%r11)
    jz else

    incl odd

else:
    incl even

endif:
    jmp while

endwhile:           # }
    leave
    ret
    