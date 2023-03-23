char str[] = "BEBAMUITOCAFE";

void process() {
   char *ptr = str; // o ponteiro aponta pra primeira posição de str
   while (*ptr) {   // ao final da string, o ptr se tornará um '\0' que ira finalizar o while
      *ptr += 32;   // com o *, acesso o valor o qual o ponteiro está se referenciando, ou seja, a string
      ptr++;        // no final, a gente incrementa o valor da posição de memória que o ponteiro faz a referencia
   }
}
