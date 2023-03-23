# Esse arquivo testa as chamadas de função
# f1 testa a chamada com 1 salvamento e 1 pi
# f2 testa a chamada com 2 salvamentos e 1 pa e 1 vi
# f3 testa a chamada com 3 salvamentos e 1 va e 1 ci
# f4 testa a chamada com 3 salvamentos e nenhum argumento
# f5 testa a chamada sem salvamentos e 3 vi

function f1 pi1

def
var vi1
enddef

# movq %rdi, -8(%rbp)
# movl -8(%rbp), %edi
# call f250
# movl %eax, -12(%rbp)
# movq -8(%rbp), %rdi
vi1 = call f250 pi1

return vi1
end

function f2 pa1 pi2

def
var vi1
enddef

# movq %rdi, -8(%rbp)
# movq %rsi, -16(%rbp)
# movq -8(%rbp), %rdi
# movl -20(%rbp), %esi
# call f250
# movl %eax, -20(%rbp)
# movq -8(%rbp), %rdi
# movq -16(%rbp), %rsi
vi1 = call f250 pa1 vi1

return vi1
end

function f3 pi1 pi2 pi3

def
var vi1
vet va2 size ci100
enddef

# movq %rdi, -8(%rbp)
# movq %rsi, -16(%rbp)
# movq %rdx, -24(%rbp)
# movq -428(%rbp), %rdi
# movl $10, %esi
# call f250
# movl %eax, -28(%rbp)
# movq -8(%rbp), %rdi
# movq -16(%rbp), %rsi
# movq -24(%rbp), %rdx
vi1 = call f250 va2 ci10

return vi1
end

function f4 pi1 pi2 pi3

def
var vi1
vet va2 size ci100
enddef

# movq %rdi, -8(%rbp)
# movq %rsi, -16(%rbp)
# movq %rdx, -24(%rbp)
# call f250
# movl %eax, -28(%rbp)
# movq -8(%rbp), %rdi
# movq -16(%rbp), %rsi
# movq -24(%rbp), %rdx
vi1 = call f250

return vi1
end

function f5

def
var vi1
var vi2
var vi3
enddef

# movl -4(%rbp), %edi
# movl -8(%rbp), %esi
# movl -12(%rbp), %edx
# call f250
# movl %eax, -4(%rbp)
vi1 = call f250 vi1 vi2 vi3

return vi1
end