# Esse arquivo testa a tradução das atribuições de valint e dos valores limítrofes das constantes
function f1 pi1
def
var vi1
var vi2
var vi3
var vi9223372036854775807
enddef

# movl $2147483647, %eax
# movl %eax, -12(%rbp)
vi1 = ci+2147483647

# movl $-2147483648, %eax
# movl %eax, -16(%rbp)
vi2 = ci-2147483648

# movl -12(%rbp), %eax
# movl %eax, -20(%rbp)
vi3 = vi1 

# movl %edi, %eax
# movl %eax, -24(%rbp)
vi9223372036854775807 = pi1 

# movl -12(%rbp), %eax
return vi1
end