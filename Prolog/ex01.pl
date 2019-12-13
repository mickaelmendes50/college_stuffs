/*******************
 Relações de gostos
********************/

% Fatos.
passaro(marcelo).
peixe(silvio).
minhoca(ana).
gato('Chuck Norris').
pessoa(eu).

% Regras.
gosta(passaro, X)   :- minhoca(X).
gosta(gato, X)      :- passaro(X).
gosta(gato, X)      :- peixe(X).
gosta(gato, X)      :- pessoa(X).
gosta(pessoa, X)    :- gato(X). 
amigo(X, Y)         :- gosta(X, Y), gosta(Y, X).
come(X, Y)          :- gosta(X, Y), not(pessoa(Y)).
