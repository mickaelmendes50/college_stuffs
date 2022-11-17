#include <stdio.h>

struct S {
  long  a;
  char  b;  
  int   c;
  short d;
};

void offsets(struct S *ptr) {
  //&ptr->a - ptr;
   unsigned long i = (unsigned long) ptr;
   unsigned long ea = (unsigned long) &ptr->a;
   printf("%d\n", ea-i);

   unsigned char j = (unsigned char) ptr;
   unsigned long eb = (unsigned long) &ptr->b;
   printf("%d\n", eb-j);
}

//----------------------------------------------
// Cria a variável varS
struct S varS;

int main() {
  offsets(&varS);
  return 0;
}
