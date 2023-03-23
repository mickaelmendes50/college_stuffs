.data
.globl s
.align 4
s: .int 0

.align 4
nums: .int 65, -105, 111, 34
.text

.globl sum
sum:
    pushq %rbp
    movq  %rsp, %rbp

    # O %r8d vai ser o int i = 0;
    movl $0, %r8d

while:
    cmp $4, %r8d        # Compara o (i < 4)
    jge endwhile

    # s = s + nums[i];
    # nums[i] = &nums + (i * sizeof(int))
    movq $nums, %rax
    movslq %r8d, %r9
    imulq $4, %r9
    addq %r9, %rax

    movl (%rax), %ebx
    addl %ebx, s

    # i++
    incl %r8d
    jmp while

endwhile:
    leave
    ret
