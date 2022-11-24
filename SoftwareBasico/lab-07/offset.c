#include <stdio.h>

struct S {
  long  a;
  char  b;  
  int   c;
  short d;
};

void offsets(struct S *ptr) {
  int size = 0;
  if (sizeof(ptr->a) == 8 || sizeof(ptr->b) == 8 || sizeof(ptr->c) == 8 || sizeof(ptr->d) == 8) {
    size = 8;
  } else if (sizeof(ptr->a) == 4 || sizeof(ptr->b) == 4 || sizeof(ptr->c) == 4 || sizeof(ptr->d) == 4) {
    size = 4;
  } else if (sizeof(ptr->a) == 2 || sizeof(ptr->b) == 2 || sizeof(ptr->c) == 2 || sizeof(ptr->d) == 2) {
    size = 2;
  } else {
    size = 1;
  }

  printf("a = x + %d\n", 0);
  printf("a = x + %d\n", size);
  printf("a = x + %d\n", size*2);
  printf("a = x + %d\n", size*3);
}

//----------------------------------------------
// Cria a variável varS
struct S varS;

int main() {
  offsets(&varS);
  return 0;
}
