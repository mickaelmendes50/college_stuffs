#include "header.h"

int processParams(int *offset, char *header){
  char t[3];
  int n, j;

  j = sscanf(header, "function f%d p%c%d p%c%d p%c%d", &n, t, &n, t+1, &n, t+2, &n);
  
  if(j == 1) j = 0;
  else j = ceil(((double) j)/3.0);

  if(j) printf("\n");

  n = 2; //Por simplicidade iremos alinhar todos os parâmetros em 8 e salvar o registradores inteiros
  for(int i = 0; i < j; i++){
    *offset = calcOffset(*offset, n);
    paramOffsets[i] = *offset;
    printf("# p%c%d: %d\n", t[i], i+1, *offset);
  }

  return j;
}

void expandP(char *p){
  char reg[5];
  switch(p[2]){
    case '1':
      strcpy(reg, "%edi");
      break;
    case '2':
      strcpy(reg, "%esi");
      break;
    case '3':
      strcpy(reg, "%edx");
      break;
  }
  if(p[1] == 'a') reg[1] = 'r';
  strcpy(p, reg);
}

void getParamReg(char *reg, int i){
  //Para garantir que a função não irá causar erro de segmentação
  //0 -> 1
  //1 -> 2
  //2 -> 3
  //3 -> 1
  i = (i%3)+1;

  switch(i){
    case 1:
      strcpy(reg, "%rdi");
      break;
    case 2:
      strcpy(reg, "%rsi");
      break;
    default:
      strcpy(reg, "%rdx");
  }
}

void saveParam(int i){
  char reg[5];
  getParamReg(reg, i);
  printf("\n# Salva o %d-ésimo parâmetro\n", i+1);
  printf("movq %s, %d(%%rbp)\n\n", reg, paramOffsets[i]);
}

void recoverParam(int i){
  char reg[5];
  getParamReg(reg, i);
  printf("\n# Recupera o %d-ésimo parâmetro\n", i+1);
  printf("movq %d(%%rbp), %s\n\n", paramOffsets[i], reg);
}

void saveAllParam(){
  for(int i = 0; i < pNum; i++){
    saveParam(i);
  }
}

void recoverAllParam(){
  for(int i = 0; i < pNum; i++){
    recoverParam(i);
  }
}
