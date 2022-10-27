#include <stdio.h>

int odd_ones(unsigned int x) {
  int contador = 0;
  while (x) {
    contador ^= x & 1;
    x >>= 1;
  }

  return contador;
}


int main() {
  unsigned int v;

  v = 0x01010101;
  printf("%X tem número %s de bits\n", v, odd_ones(v) ? "impar" : "par");

  v = 0x01030101;
  printf("%X tem número %s de bits\n", v, odd_ones(v) ? "impar" : "par");

  return 0;
}