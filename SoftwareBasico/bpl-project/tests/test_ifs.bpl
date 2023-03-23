function f1 pi1

def
var vi1
vet va2 size ci10
enddef

# cmpl $0, -12(%rbp)
# je .L1
# movl $0, -12(%rbp)
# .L1:
if vi1
vi1 = ci0
endif

# cmpl $0, %edi
# je .L2
# movq $8, %rax
# imull $4, %rax
# leaq -52(%rbp), %r8
# addq %r8, %rax
# movl (%rax), %r8d
# movl %r8d, -12(%rbp)
# .L2:
if pi1
get va2 index ci8 to vi1
endif

# cmpl $0, $0
# je .L3
# movl -12(%rbp), %eax
# leave
# ret
# .L3:
if ci0
return vi1
endif

# cmpl $0, $0
# je .L4
# .L4:
if ci0
endif

return ci-1
end