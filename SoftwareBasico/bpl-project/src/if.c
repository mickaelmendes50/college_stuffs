#include "header.h"

int label = 0;

void processIf(char *l){
  //Imprime a linha sendo traduzida
  printf("\n#Linha: %s\n", l);

  char val[LINESZ];
  label++; //Cria uma nova label

  //Separa o <valint>
  sscanf(l, "if %s", val);
  expandArg(val);

  if(val[0] == '$') {
    printf("movl %s, %%eax\n", val);
    printf("cmpl $0, %%eax\n");
  }
  else printf("cmpl $0, %s\n", val);
  printf("je .L%d\n", label); //Pula o comando caso if seja igual a 0
}

void processEndIf(){
  printf(".L%d:\n", label);
}