# Alloc: 8+4+4*30+4 -> 144
# Offsets: -8, -12, -132, -136
function f2 pi1
def
var vi1
vet va2 size ci30
var vi3
enddef
return ci-1
end

# Alloc: 8+8+40+80+4 -> 144
# Offsets: -8, -16, -56, -136, -140
function f3 pa1 pi2
def
vet va1 size ci10
vet va2 size ci20
var vi3
enddef
return ci5
end

# Alloc: 65536 -> 65536 (maximum array size)
# Offsets: -65536
function f4
def
vet va10 size ci16384
enddef
return ci-10
end