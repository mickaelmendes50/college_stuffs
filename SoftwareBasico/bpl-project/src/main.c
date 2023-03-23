#include "header.h"

int vNum; //Número de variáveis locais
int pNum; //Número de parâmetros recebidos pelo função
int paramOffsets[MAX_PARAMS]; //Mapeamento dos offsets onde os parâmetros serão salvos, caso necessário
long varOffsets[MAX_VARS][2]; //Mapeamento de cada variável local para seu offset na pilha

int main(){
  char line[LINESZ] = "";

  //Imprime o início do arquivo .S
  printf(".data\n.text\n\n");
  //Segundo o enunciado do trabalho não existem variáveis globais, nem constantes que precisam ser colocadas em .rodata

  //Lê todas as funções definidas no programa
  //Chama processFunc que retorna quando encontra a linha "end"
  while (readNextLine(line)) processFunc(line);

  return 0;
}

void processFunc(char *header){
  char line[LINESZ] = "";
  int fNum; //Identificador numérico da função
  int offset = 0;

  printf("# %s\n", header);
  //Processa o header
  sscanf(header, "function f%d", &fNum); //Lê o número da função
  printf(".globl f%d\nf%d:\n", fNum, fNum); //Declara a função como global e inicia sua definição
  //Como todos os parâmetros começam com 'p' e são numerados sequencialmente, não é necessário criar um dicionário para eles
  //Assumiremos que não serão acessados parâmetros que não foram passados
  //Apenas precisamos medir eles para salvá-los na pilha
  pNum = processParams(&offset, header); //pNum é o número de parâmetros

  //Processa as variáveis locais
  vNum = processVars(&offset); //Imprime os comentários e atualiza o offset
  offset = calcAlloc(offset); // Arredonda o offset para múltiplo de 16
  
  //Inicia a função
  printf("\npushq %%rbp\n");
  printf("movq %%rsp, %%rbp\n");
  if(offset) printf("subq $%d, %%rsp\n", offset);

  //Processa as operações
  while(strcmp(line, "end")){

    switch(line[0]){
      case 'v': //Caso a operação seja uma atribuição
        processAttr(line);
        break;
      case 'g': //Caso seja um acesso a um array
        processArrGet(line);
        break;
      case 's': //Caso seja uma atribuição a um elemento de um array
        processArrSet(line);
        break;
      case 'i': //Caso seja um if
        processIf(line);
        break;
      case 'e': //Caso "endif"
        processEndIf();
        break;
      case 'r': //Caso "return <valint>"
        char ret[LINESZ];
        sscanf(line, "return %s", ret);
        printf("\n# %s\n", line);
        processValIntAttr(ret);
        //Finaliza a função
        printf("leave\nret\n");
        break;
    }
    readNextLine(line);
  }
  
  //Imprime um separador entre as funções traduzidas
  printf("\n########################################\n");
}