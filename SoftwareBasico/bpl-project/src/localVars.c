#include "header.h"

int processVars(int *offset){
  char line[LINESZ] = "";
  long varNum, size;
  int count = 0;
  
  readNextLine(line); //Descarta a linha com "def"
  readNextLine(line); //Lê a primeira linha de variável
  
  while(strcmp(line, "enddef")){
    count++;

    if(line[1] == 'a'){
      *offset = calcOffset(*offset, 1);
      sscanf(line, "var vi%ld", &varNum);
      printf("# vi%ld: %d\n", varNum, *offset);
      varOffsets[count-1][0] = varNum;
      varOffsets[count-1][1] = *offset;
    }
    else {
      sscanf(line, "vet va%ld size ci%ld", &varNum, &size);
      *offset = calcOffset(*offset, size);
      printf("# va%ld: %d\n", varNum, *offset);
      varOffsets[count-1][0] = varNum;
      varOffsets[count-1][1] = *offset;
    }

    readNextLine(line);
  }

  return count;
}

void expandV(char *v){
  long n;
  char c;

  sscanf(v, "v%c%ld", &c, &n); //Extrai o identificador da variável
  for(int i = 0; i < vNum; i++){ //Procura pelo identificador em todos os offsets
    if(varOffsets[i][0] == n){
      n = varOffsets[i][1]; //Salva o valor do offset
      break;
    }
  }

  sprintf(v, "%ld(%%rbp)", n); //Expande o vi para seu endereço relativo na pilha
}