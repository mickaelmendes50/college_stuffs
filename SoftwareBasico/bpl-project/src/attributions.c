#include "header.h"

void processAttr(char *l){
  //Imprime a linha sendo traduzida
  printf("\n# %s\n", l);

  //A estratégia aqui será usar o %rax como se todo valor a ser atribuído fosse retorno de uma função
  //Ou seja, mesmo que o lado direito da igualdade seja uma expressão, as funções que processam esse lado irão colocar o retorno em %rax
  
  char d[LINESZ]; //string contendo o destino
  char exp[5][LINESZ]; //Até 5 strings contendo as palavras que formam a expressão
  int nArgs;

  //vi<num> = <valint> 
  //vi<num> = <valint> <op> <valint>
  //vi<num> = call f<num> <arg> <arg> <arg>  (Sabemos que as funções em BPL tem no máximo 3 parâmetros)
  nArgs = sscanf(l, "%s = %s %s %s %s %s", d, exp[0], exp[1], exp[2], exp[3], exp[4]);

  //Chama uma função para processar o valor da atribuição
  if(nArgs == 2){
    //vi<num> = <valint> 
    processValIntAttr(exp[0]);
  }
  else if(nArgs == 4 && strcmp(exp[0], "call")){
    //vi<num> = <valint> <op> <valint>
    processExpAttr(exp[0], exp[1], exp[2]);
  }
  else {
    //vi<num> = call f<num> <arg> <arg> <arg>
    processCallAttr(nArgs-3, exp[1], exp[2], exp[3], exp[4]);
  }

  //Finaliza a atribuição usando o registrador acumulador
  expandV(d);
  printf("movl %%eax, %s\n", d);
}

void processValIntAttr(char *o){
  expandArg(o);
  printf("movl %s, %%eax\n", o);
}

void processExpAttr(char *x, char *op, char *y){
  //<valint> <op> <valint>
  //   x      op     y

  expandArg(x);
  expandArg(y);

  //movl <valint>, %eax
  printf("movl %s, %%eax\n", x);

  switch(op[0]){
    case '+':
      printf("addl %s, %%eax\n", y);
      break;
    case '-':
      printf("subl %s, %%eax\n", y);
      break;
    case '*':
      printf("imull %s, %%eax\n", y);
      break;
    case '/':
      // Como em BPL somente o tipo signed int pode ser operado, usaremos idiv para as operações de divisão
      // Salva %edx
      if(pNum >= 3) saveParam(2);

      printf("cltd\n");
      if(*y == '$'){ //idiv não aceita constante como parâmetro
        printf("movl %s, %%ecx\n", y);
        printf("idivl %%ecx\n");
      }
      else printf("idivl %s\n", y);
      
      //Recupera %edx
      if(pNum >= 3) recoverParam(2);

      break;
  }

}

void processCallAttr(int nArgs, char *f, char *a0, char *a1, char *a2){
  // Dúvida: Eu devo salvar todos os parâmetros independentemente de quantos a função chamada realmente vai utilizar?
  // Ou eu devo salvar apenas os que a função aceita?
  // Vou seguir a regra do slide e salvar todos os caller-saved em uso
  saveAllParam();

  char reg[5];
  char inst[5] = "movq";
  int i;

  // Atribui os parâmetros para a chamada
  // Observe que nesse caso, p%c<num> é expandido para seu endereço na pilha (pois os registradores estão sendo alterados)
  if(nArgs >= 1){
    getParamReg(reg, 0);
    if(a0[1] == 'i'){
      reg[1] = 'e'; //Modifica o registrador de destino para apenas 4 bytes
      inst[3] = 'l'; //Modifica a instrução para apenas 4 bytes
    }
    else inst[3] = 'q'; //getParamReg já traz o registrador inteiro %r...

    if(a0[0] == 'p'){ //Busca o dado na pilha, pois o registrador de parâmetro não é mais seguro
      printf("%s %d(%%rbp), %s\n", inst, paramOffsets[a0[2]-'1'], reg);
    }
    else { //Traduz vi<num>, ci<snum> e va<num> e imprime a instrução
      expandArg(a0);
      printf("%s %s, %s\n", inst, a0, reg);
    }
  }

  if(nArgs >= 2){
    getParamReg(reg, 1);
    if(a1[1] == 'i'){
      reg[1] = 'e'; //Modifica o registrador de destino para apenas 4 bytes
      inst[3] = 'l'; //Modifica a instrução para apenas 4 bytes
    }
    else inst[3] = 'q'; //getParamReg já traz o registrador inteiro %r...

    if(a1[0] == 'p'){ //Busca o dado na pilha, pois o registrador de parâmetro não é mais seguro
      printf("%s %d(%%rbp), %s\n", inst, paramOffsets[a1[2]-'1'], reg);
    }
    else { //Traduz vi<num>, ci<snum> e va<num> e imprime a instrução
      expandArg(a1);
      printf("%s %s, %s\n", inst, a1, reg);
    }
  }

  if(nArgs >= 3){
    getParamReg(reg, 2);
    if(a2[1] == 'i'){
      reg[1] = 'e'; //Modifica o registrador de destino para apenas 4 bytes
      inst[3] = 'l'; //Modifica a instrução para apenas 4 bytes
    }
    else inst[3] = 'q'; //getParamReg já traz o registrador inteiro %r...

    if(a2[0] == 'p'){ //Busca o dado na pilha, pois o registrador de parâmetro não é mais seguro
      printf("%s %d(%%rbp), %s\n", inst, paramOffsets[a2[2]-'1'], reg);
    }
    else { //Traduz vi<num>, ci<snum> e va<num> e imprime a instrução
      expandArg(a2);
      printf("%s %s, %s\n", inst, a2, reg);
    }
  }

  // Chama a função
  printf("call %s\n", f); //O retorno já está no %eax para que seja utilizado na atribuição

  // Recupera os parâmetros
  recoverAllParam(); 
}


