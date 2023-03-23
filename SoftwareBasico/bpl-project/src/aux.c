#include "header.h"

void removeNewline(char *ptr)
{
  while (*ptr) {
    if (*ptr == '\n')
      *ptr = 0;
    else
      ptr++;
  }
}

// Essa especificação não está na documentação da linguagem BPL
// Porém dar suporte a comentários e linhas em branco facilita bastante os testes
int readNextLine(char *l){
  //Lê até o final do arquivo de for o caso
  while(fgets(l, LINESZ, stdin) != NULL){
    removeNewline(l); //Remove o fim de linha

    if(*l == '#'){
      printf("%s\n", l); //Imprime os comentários em BPL
      continue; //Pula a próxima verificação
    }

    if(*l) return 1; //Para caso tenha encontrado um linha não vazia
    printf("\n");
  }
  return 0; //Retorna 0 caso não haja mais linhas na entrada
}

int calcOffset(int offset, int size){
  return offset-4*size;
}

int calcAlloc(int offset){
  int alloc = ceil(((double)-offset)/16.0);
  return alloc*16;
}

void expandC(char *c){
  c[0] = '$';
  strcpy(c+1, c+2); //Substitui "ci" por "$"
}

void expandArg(char *arg){
  switch(arg[0]){
    case 'v':
      expandV(arg);
      break;
    case 'p':
      expandP(arg);
      break;
    case 'c':
      expandC(arg);
      break;
  }
}