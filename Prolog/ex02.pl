/******************
 Relacoes afetivas
*******************/

% Fatos
bonito(maria).
bonito(marcos).
bonito(fabiano).
rico(marcos).
rico(ana).
forte(ana).
forte(fabiano).
forte(silvio).
amavel(silvio).
mulher(maria).
mulher(ana).
homem(marcos).
homem(fabiano).

% Regras
gosta(homem, Y) :- mulher(Y), bonito(Y).
gosta(ana, X)   :- homem(X), gosta(X, ana).
gosta(maria, X) :- homem(X), rico(X), amavel(X), forte(X), gosta(X, maria).
gosta(maria, X) :- homem(X), rico(X), bonito(X), forte(X), gosta(X, maria).
feliz(X)        :- homem(X), rico(X).
feliz(X)        :- mulher(Y), homem(X), gosta(mulher, X), homem(gosta, Y).
feliz(X)        :- homem(X), mulher(Y), gosta(homem, Y), gosta(mulher, X).
