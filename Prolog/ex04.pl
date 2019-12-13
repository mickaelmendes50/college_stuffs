/****************
 Situacao dos alunos
*****************/

% Fatos
nota(joao,5.0).
nota(maria,6.0).
nota(joana,8.0).
nota(mariana,9.0).
nota(cleuza,8.5).
nota(jose,6.5).
nota(jaoquim,4.5).
nota(mara,4.0).
nota(mary,10.0).

% Regras
situacao(X, aprovado)       :- nota(X, Y), Y=<10.0, Y>=7.0.
situacao(X, recuperacao)    :- nota(X, Y), Y=<6.9, Y >=5.0.
situacao(X, reprovado)      :- nota(X, Y), Y<5.0, Y>=0.0.