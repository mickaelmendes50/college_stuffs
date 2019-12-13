/*****************
 Turmas de alunos
******************/

% Fatos
aluno(joao, calculo).
aluno(maria, calculo).
aluno(joel, programacao).
aluno(joel, estrutura).
frequenta(joao, puc).
frequenta(maria, puc).
frequenta(joel, ufrj).
professor(carlos, calculo).
professor(ana_paula, estrutura).
professor(pedro, programacao).
funcionario(pedro, ufrj).
funcionario(ana_paula, puc).
funcionario(carlos, puc).

% Regras
alunos(X, Y) :- professor(X, Z), aluno(Y, Z).
pessoas(X, Y) :- frequenta(Y, X).
pessoas(X, Y) :- funcionario(Y, X).