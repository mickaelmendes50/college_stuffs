function f1 pa1 pa2 pi3
def
var vi1
var vi2
var vi3
var vi4
vet va5 size ci10
enddef

# cltd apaga pi3 (edx) -> idivl %edx (incorreto)
vi1 = vi1 / pi3

# problema com constante
# ok
vi1 = ci1
# incorreto
vi1 = ci1024
# ok
return ci-2222
# incorreto
return ci-2048

# Passage de 'va' usando 'movq' em vez de 'leaq'
vi1 = call f2 va5

return ci0
end
