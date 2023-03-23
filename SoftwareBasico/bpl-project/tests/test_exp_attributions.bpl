# Esse aquivo testa as operações aritméticas
# f1 retorna uma soma mais 10
# f2 retorna uma subtração vezes -1 mais 1
# f3 retorna uma multiplicação vezes 4 (pi1*pi2*4)
# f4 retorna uma divisão por 4 ((pi1/pi2)/4)

function f1 pi1 pi2

def
var vi3
enddef

# movl %edi, %eax
# addl %esi, %eax
# movl %eax, -20(%rbp)
vi3 = pi1 + pi2

# movl $-15, %eax
# addl -20(%rbp), %eax
# movl %eax, -20(%rbp)
vi3 = ci-15 + vi3

# movl -20(%rbp), %eax
# addl $25, %eax
# movl %eax, -20(%rbp)
vi3 = vi3 + ci25

# movl -20(%rbp), %eax
return vi3
end

function f2 pi1 pi2

def
var vi3
var vi4
enddef

# movl $esi, %eax
# movl %eax, -20(%rbp)
vi3 = pi2

# movl %edi, %eax
# subl -20(%rbp), %eax
# movl %eax, -24(%rbp)
vi4 = pi1 - vi3

# movl $0, %eax
# subl -24(%rbp), %eax
# movl %eax, -24(%rbp)
vi4 = ci0 - vi4

# movl -24(%rbp), %eax
# subl $-1, %eax
# movl %eax, -24(%rbp)
vi4 = vi4 - ci-1

# movl -24(%rbp), %eax
return vi4
end

function f3 pi1 pi2

def
var vi3
var vi4
enddef

# movl %edi, %eax
# movl %eax, -20(%rbp)
vi3 = pi1

# movl -20(%rbp), %eax
# imull %esi, %eax
# movl %eax, -24(%rbp)
vi4 = vi3 * pi2

# movl -24(%rbp), %eax
# imull $2, %eax
# movl %eax, -24(%rbp) 
vi4 = vi4 * ci2

# movl $2, %eax
# imull -24(%rbp), %eax
# movl %eax, -24(%rbp) 
vi4 = ci2 * vi4

# movl -24(%rbp), %eax
return vi4
end

function f4 pi1 pi2

def
var vi3
var vi4
enddef

# movl %edi, %eax
# movl %eax, -20(%rbp)
vi3 = pi1

# movl -20(%rbp), %eax
# cltd
# idivl %esi
# movl %eax, -20(%rbp)
vi3 = vi3 / pi2

# movl $-200, %eax
# cltd
# idivl $-25
# movl %eax, -24(%rbp)
vi4 = ci-200 / ci-25

# movl -24(%rbp), %eax
# cltd
# idivl $2
# movl %eax, -24(%rbp)
vi4 = vi4 / ci2

# movl -20(%rbp), %eax
# cltd
# idivl -24(%rbp)
# movl %eax, -24(%rbp)
vi4 = vi3 / vi4

# movl -24(%rbp), %eax
return vi4
end