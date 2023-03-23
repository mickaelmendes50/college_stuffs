#include "header.h"

void processArrGet(char *l){
  //Imprime a linha sendo traduzida
  printf("\n# %s\n", l);

  char arr[LINESZ];
  char ind[LINESZ];
  char des[LINESZ];

  //Separa os identificadores
  sscanf(l, "get %s index %s to %s", arr, ind, des);
  
  //Expande os argumentos
  expandArg(arr);
  expandArg(ind);
  expandArg(des);

  //Calcula o endereço do índice
  printf("movq %s, %%rax\n", ind);
  printf("imulq $4, %%rax\n");
  if(arr[0] == '-'){
    printf("leaq %s, %%r8\n", arr);
    printf("addq %%r8, %%rax\n");
  }
  else printf("addq %s, %%rax\n", arr);

  //Dereferencia o endereço para o destino
  printf("movl (%%rax), %%r8d\n");
  printf("movl %%r8d, %s\n", des);
}

void processArrSet(char *l){
  //Imprime a linha sendo traduzida
  printf("\n# %s\n", l);

  char arr[LINESZ];
  char ind[LINESZ];
  char val[LINESZ];

  //Separa os identificadores
  sscanf(l, "set %s index %s with %s", arr, ind, val);
  
  //Expande os argumentos
  expandArg(arr);
  expandArg(ind);
  expandArg(val);

  //Calcula o endereço do índice
  printf("movq %s, %%rax\n", ind);
  printf("imulq $4, %%rax\n");
  if(arr[0] == '-'){
    printf("leaq %s, %%r8\n", arr);
    printf("addq %%r8, %%rax\n");
  }
  else printf("addq %s, %%rax\n", arr);

  //Dereferencia o endereço para a atribuição
  if(val[0] == '-'){
    printf("movl %s, %%r8d\n", val);
    printf("movl %%r8d, (%%rax)\n");
  }
  else {
    printf("movl %s, (%%rax)\n", val);
  }
}