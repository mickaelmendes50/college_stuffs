#include <stdio.h>

void dump(void *addr, int n) {
  unsigned char *p = (unsigned char *)addr;

  while (n--) {
    printf("%p - %02x\n", p, *p);
    p++;
  }
}

int main() {

  //int i = 10000;
  //long i = 10000;
  //short i = 10000;
  //char i = '1';
  char i[] = "12345";
  dump(&i, sizeof(i));
  return 0;

}
