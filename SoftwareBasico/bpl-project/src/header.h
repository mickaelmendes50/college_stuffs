#ifndef HEADER_FILE
#define HEADER_FILE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define LINESZ 256
#define MAX_PARAMS 3
#define MAX_VARS 5

extern int pNum; //Número de parâmetros recebidos pelo função
extern int vNum; //Número de variáveis locais
extern long varOffsets[MAX_VARS][2]; //Mapeamento de cada variável local para seu offset na pilha
extern int paramOffsets[MAX_PARAMS]; //Mapeamento dos offsets onde os parâmetros serão salvos, caso necessário

/**
 * @brief Remove o character de fim de linha de uma string
 * 
 * @param ptr A string a ser modificada
 */
void removeNewline(char *ptr);

/**
 * @brief Calcula o offset de um array de inteiros 
 * 
 * @param offset O offset atual
 * @param size O tamanho do array
 * @return int O novo offset
 */
int calcOffset(int offset, int size);

/**
 * @brief Calcula o tamanho em bytes para ser alocado na pilha (múltiplo de 16)
 * 
 * @param offset O último offset da pilha
 * @return int O tamanho em bytes da pilha
 */
int calcAlloc(int offset);

/**
 * @brief Expande os valores vi<num> da linguagem BPL para seus equivalentes em Assembly
 * 
 * @param vi A string contendo o identificador vi<num> que será modificado para assembly
 */
void expandV(char *v);

/**
 * @brief Expande os parâmetros pi<num> de BPL para seus registradores em assembly
 * 
 * @param pi A string contendo pi<num> que será modificada para assembly
 */
void expandP(char *p);

/**
 * @brief Expande as constantes ci<snum> em BPL para assembly
 * 
 * @param ci Uma string contendo a representação ci<snum> que será modificada para assembly
 */
void expandC(char *c);

/**
 * @brief Expande qualquer <arg> em BPL para Assembly.
 * 
 * @param valInt A string contendo o <arg> que será modificada para assembly
 */
void expandArg(char *arg);

/**
 * @brief Traduz o lado direito de uma atribuição simples, colocando o valor a ser atribuído em %rax
 * 
 * @param d A string contendo o <valint> de origem
 */
void processValIntAttr(char *o);

/**
 * @brief Lê o header, cria offsets para salvar cada parâmetro caso necessário e retorna o número de parâmetros
 * 
 * @param offset O offset atual da pilha
 * @param header A linha contendo a declaração da função em BPL
 * @return int A quantidade de parâmetros lida
 */
int processParams(int *offset, char *header);

/**
 * @brief Lê o bloco de variáveis locais, imprime e armazena seus offsets em varOffsets
 * 
 * @param offset O endereço do offset atual da pilha
 * @return int A quantidade de variáveis lidas
 */
int processVars(int *offset);

/**
 * @brief Lê e traduz uma função de BPL para assembly
 * 
 * @param header A primeira linha da função em BPL, contendo seu nome e lista de parâmetros
 */
void processFunc(char *header);

/**
 * @brief Processa uma linha contendo uma atribuição em BPL e imprime sua tradução em stdout
 * 
 * @param l A linha contendo a atribuição
 */
void processAttr(char *l);

/**
 * @brief Imprime o equivalente a atribuição do <arg> contido em o para %rax
 * 
 * @param o 
 */
void processValIntAttr(char *o);

/**
 * @brief Imprime as instruções que realizam a operação indicada pelos parâmetros e deixam o resultado em %rax
 * 
 * @param x O primeiro operando
 * @param op A string indicando a operação a ser realizada (+|-|*|/)
 * @param y O segundo operando
 */
void processExpAttr(char *x, char *op, char *y);

/**
 * @brief Coloca o i-ésimo registrador de passagem de parâmetros inteiros em reg (%rdi, %rsi ou %rdx)
 * 
 * @param reg A string que irá conter o registrador
 * @param i O índice 0-2 do parâmetro que se quer atribuir a reg
 */
void getParamReg(char *reg, int i);

/**
 * @brief Salva o i-ésimo parâmetro em seu local alocado na pilha
 * 
 * @param i O índice do parâmetro a ser salvo
 */
void saveParam(int i);

/**
 * @brief Recupera o i-ésimo parâmetro da pilha
 * 
 * @param i O índice do parâmetro a ser recuperado
 */
void recoverParam(int i);

/**
 * @brief Salva na pilha todos os parâmetros recebidos pela função
 * 
 */
void saveAllParam();

/**
 * @brief Recupera da pilha todos os parâmetros recebidos pela função
 * 
 */
void recoverAllParam();

/**
 * @brief Imprime em stdout as instruções responsáveis por chamar a função f (Salva todos os parâmetros recebidos pela função caller)
 * 
 * @param nArgs O número de argumentos que serão passados para a função chamada (1-3)
 * @param f A string contendo o identificador da função a ser chamada
 * @param a0 O primeiro argumento (caso nArgs >= 1)
 * @param a1 O segundo argumento (caso nArgs >= 2)
 * @param a2 O terceiro argumento (caso nArgs >= 3)
 */
void processCallAttr(int nArgs, char *f, char *a0, char *a1, char *a2);

/**
 * @brief Traduz a atribuição de um índice de um array a uma variável local
 * 
 * @param l A linha contendo a instrução get em BPL
 */
void processArrGet(char *l);

/**
 * @brief Traduz a atribuição de um valor a um índice de um array
 * 
 * @param l A linha contendo a instrução set em BPL
 */
void processArrSet(char *l);

/**
 * @brief Traduz o if em BPL para Assembly
 * 
 * @param l A linha contendo a definição do if em BPL
 */
void processIf(char *l);

/**
 * @brief Finaliza o if atualmente aberto, ou seja, não traduz ifs aninhados já que BPL não possui essa capacidade
 * 
 */
void processEndIf();

int readNextLine(char *l);

#endif