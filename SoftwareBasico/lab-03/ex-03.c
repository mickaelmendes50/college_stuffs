#include <stdio.h>
#include <stdint.h>

unsigned int convertB2L(unsigned int x) {
  // escreva seu código aqui
  int b1, b2, b3, b4;
  b1 = (x & 0x000000ff) <<  24;
  b2 = (x & 0x0000ff00) <<  8;
  b3 = (x & 0x00ff0000) >>  8;
  b4 = (x & 0xff000000) >>  24;

  return b1 | b2 | b3 | b4;
}

int main() {
  unsigned int b = 0x12AB34CD;
  unsigned int l = convertB2L(b);

  printf("b = 0x%08X\n", b);
  printf("l = 0x%08X\n", l);

  return 0;
}
