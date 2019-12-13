#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

/** 
 * Conjunto.hpp
 */
typedef struct conjunto Conjunto;

int criaConjunto(Conjunto c);

int conjuntoVazio(Conjunto c);

int insereElementoConjunto(int x, Conjunto c);

int excluirElementoConjunto(int x, Conjunto c);

int tamanhoConjunto(Conjunto c);

int maior(int x, Conjunto c);

int menor(int x, Conjunto c);

int pertenceConjunto(int x, Conjunto c);

int conjuntosIdenticos(Conjunto c1, Conjunto c2);

int subconjunto(Conjunto c1, Conjunto c2);

Conjunto complemento(Conjunto c1, Conjunto c2);

Conjunto uniao(Conjunto c1, Conjunto c2);

Conjunto interseccao(Conjunto c1, Conjunto c2);

Conjunto diferenca(Conjunto c1, Conjunto c2);

Conjunto conjuntoPartes(Conjunto c);

void mostraConjunto(Conjunto c, string ordem);

int copiarConjunto(Conjunto c1, Conjunto c2);

int destroiConjunto(Conjunto c);