#include <iostream>
#include <bits/stdc++.h>
#include <stdlib.h>
#include <string.h>
#include <vector>

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


/**
 * Conjunto.cpp 
 */
struct conjunto {
    int *elementos;
    int size;
};

int criaConjunto(Conjunto* *c) {
    *c = (Conjunto*)malloc(sizeof(Conjunto));
    if ((*c) != NULL) {
        (*c)->elementos = (int*)malloc(0*sizeof(int));
        (*c)->size = 0;
        return 1;
    }
    return 0;
}

int conjuntoVazio(Conjunto *c) {
    if (c->size == 0) {
        return 1;
    }
    return 0;
}

int insereElementoConjunto(int x, Conjunto *c) {
    if (pertenceConjunto(x, c)) {
        return 0;
    }
    c->size++;
    c->elementos = (int*)realloc(c->elementos, sizeof(int)*(c->size));
    c->elementos[c->size-1] = x;
    return 1;
}

int excluirElementoConjunto(int x, Conjunto *c) {
    if (pertenceConjunto(x, (c))) {
        int i;
        for (i = 0; i < c->size; i++) {
            if (c->elementos[i] == x) {
                int j;
                for (j = i; j < c->size-1; j++) {
                    c->elementos[j] = c->elementos[j+1];
                }
            }
        }
        c->size--;
        c->elementos = (int*)realloc(c->elementos, sizeof(int)*(c->size));
    }
    return 0;
}

int tamanhoConjunto(Conjunto *c) {
    return c->size;
}

int maior(int x, Conjunto *c){
    int m = 0, i;
    for(i = 0; i < c->size; i++){
        if(c->elementos[i] > x){
            m++;
        }
    }
    return m;
}

int menor(int x, Conjunto *c){
    int m = 0, i;
    for(i = 0; i < c->size; i++){
        if(c->elementos[i] < x){
            m++;
        }
    }
    return m;
}

int pertenceConjunto(int x, Conjunto *c) {
    int i;
    for(i = 0; i < c->size; i++){
        if(x == c->elementos[i])
            return 1;
    }
    return 0;
}

/*int conjuntosIdenticos(Conjunto c1, Conjunto c2);

int subconjunto(Conjunto c1, Conjunto c2);

Conjunto complemento(Conjunto c1, Conjunto c2);

Conjunto uniao(Conjunto c1, Conjunto c2);

Conjunto interseccao(Conjunto c1, Conjunto c2);

Conjunto diferenca(Conjunto c1, Conjunto c2);

Conjunto conjuntoPartes(Conjunto c);

void mostraConjunto(Conjunto c, string ordem);

int copiarConjunto(Conjunto c1, Conjunto c2);

int destroiConjunto(Conjunto c);*/

/**
 * Corpo principal 
 */

void menuPrincipal() {
    cout << endl << "Selecione uma opção:" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
    cout << " 0.  Sair do Programa" << endl;
    cout << " 1.  criar conjunto C" << endl; 
    cout << " 2.  verificar se o conjunto C é vazio" << endl; 
    cout << " 3.  incluir o elemento x no conjunto C" << endl; 
    cout << " 4.  excluir o elemento x do conjunto C" << endl; 
    cout << " 5.  calcular a cardinalidade do conjunto C" << endl; 
    cout << " 6.  determinar a quantidade de elementos do conjunto C que são maiores que x" << endl; 
    cout << " 7.  determinar a quantidade de elementos do conjunto C que são menores que x" << endl; 
    cout << " 8.  verificar se o elemento x pertence ao conjunto C" << endl; 
    cout << " 9.  comparar se dois conjuntos, C1 e C2 são idênticos" << endl; 
    cout << " 10. identificar se o conjunto C1 é subconjunto do conjunto C2" << endl;
    cout << " 11. gerar o complemento do conjunto C1 em relação ao conjunto C2" << endl;
    cout << " 12. gerar a união do conjunto C1 com o conjunto C2" << endl;
    cout << " 13. gerar a intersecção do conjunto C1 com o conjunto C2" << endl;
    cout << " 14. gerar a diferença entre o conjunto C1 e o conjunto C2" << endl;
    cout << " 15. gerar o conjunto das partes do conjunto C" << endl;
    cout << " 16. mostrar os elementos presentes no conjunto C" << endl;
    cout << " 17. copiar o conjunto C1 para o conjunto C2" << endl;
    cout << " 18. destruir o conjunto C" << endl;
    cout << "------------------------------------------------------------------------------" << endl;
}

int main() {
    int option = 1, x;
    menuPrincipal();

    do {
        Conjunto *C1, *C2;

        cin >> option;

        switch (option) {
        case 0:
            break;
        
        case 1:
            if (criaConjunto(&C1)) {
                cout << "SUCESSO" << endl;
                break;
            }
            cout << "FALHA" << endl;
            break;

        case 2:
            if (conjuntoVazio(C1)) {
                cout << "TRUE" << endl;
                break;
            }
            cout << "FALSE" << endl;
            break;

        case 3:
            cout << "Digite o elemento: ";
            cin >> x;
            if (insereElementoConjunto(x, C1)) {
                cout << "SUCESSO" << endl;
                break;
            }
            cout << "FALHA" << endl;
            break;

        default:
            cout << "Opção inválida" <<endl;
            break;
        }
    } while (option != 0);
    
    cout << "Finalizado" << endl;

    return 0;
}