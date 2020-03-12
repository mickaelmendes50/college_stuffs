/*
	Institui��o: INF/UFG
	Cursos: Engenharia de Software e Sistemas de Informa��o
	Disciplina: Algoritmos e Estrutura de Dados 2 - 2020-1
	Professor: Andr� Luiz Moura
	Exerc�cio: Revis�o sobre Ponteiros e Aloca��o Din�mica
	Finalidade: Implementar o tipo abstrato de dados arrays din�micos. 
	            No c�digo, criou-se um array din�mico do tipo 'int'.
	�ltima altera��o: 10/03/2020 - 19h16
*/
#include <stdlib.h>	// malloc, free, exit, system
#include <stdio.h>	// printf, scanf
#include <malloc.h>	// malloc, realloc

// TAD Array din�mico
// Defini��o de tipo do array unidimensional de inteiros
typedef int* arrayInt;

// Prot�tipo de fun��es 
arrayInt criaArray(int);
int insereElemArray(arrayInt, int, int, int*);
int arrayCheio(int, int);
int aumentaArray(arrayInt, int *);
void imprimaArray(arrayInt, int);
void liberaArray(arrayInt);

int main() 
{
	arrayInt meuArray;
	int tamArray=0, posElem=0, i;
	
	do {
		printf("Tamanho do array: ");
		scanf("%i", &tamArray);
	} while (tamArray < 0);
	
	meuArray = criaArray(tamArray);
	
	posElem = insereElemArray(meuArray, 2, posElem, &tamArray);
	posElem = insereElemArray(meuArray, 3, posElem, &tamArray);
	posElem = insereElemArray(meuArray, 5, posElem, &tamArray);
	posElem = insereElemArray(meuArray, 7, posElem, &tamArray);
	posElem = insereElemArray(meuArray, 11, posElem, &tamArray);
		
	imprimaArray(meuArray, posElem);
	
	liberaArray(meuArray);
	system("pause > nul");
	
	return 0;
}

//
arrayInt criaArray(int n)
{
	arrayInt pArray;
	pArray = malloc(n * sizeof(int));
	return pArray;
}

//
void liberaArray(arrayInt pArray)
{	
	free(pArray);
}

//
int insereElemArray(arrayInt pArray, int valor, int posElem, int *tamArray)
{
	if (arrayCheio(posElem, *tamArray)) {
		aumentaArray(pArray, tamArray);
		printf("Array redimensionado para inserir o elemento %i.\n", valor);
	}
		
	*(pArray + posElem) = valor;
	return (++posElem);
}

//
int arrayCheio(int posElem, int tamArray)
{
	return (posElem > tamArray-1);
}

//
int aumentaArray(arrayInt pArray, int *tamArray)
{
 	pArray = (arrayInt) realloc(pArray, (*tamArray)+1 * sizeof(int));
    if (pArray == NULL) {
        printf("Nao ha memoria suficiente!");
    }
    else {
        (*tamArray)++;
    }
	return *tamArray;	
}


void imprimaArray(arrayInt pArray, int tamArray)
{
	int i;
	printf("\nElementos inseridos no Array:\n");
	for (i=0; i<tamArray; i++) {
		printf("%i ", *(pArray + i));
	}
}
