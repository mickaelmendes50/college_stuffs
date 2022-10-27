#include <ctype.h>
#include <stdio.h>

int string2num(char *s, int base) {
  int a = 0;

  for ( ; *s; s++) {
    if (*s <= 57)
      a = a*base + (*s - '0');

    if (*s >= 97 && *s <= 122)
      a = a*base + (*s - 'a');
    //printf("Valor de *s: %d - Valor de a: %d\n", *s, a);
  }

  return a;
}



int main () {

  //printf("==> %d\n", string2num("1234"));
  //printf("==> %d\n", string2num("1234") + 1);
  //printf("==> %d\n", string2num("1234") + string2num("1"));
  printf("%d\n", string2num("777", 8));
  printf("%d\n", string2num("777", 10));
  printf("%d\n", string2num("1010", 2));
  printf("%d\n", string2num("1a", 16));
printf("%d\n", string2num("a09b", 16));
printf("%d\n", string2num("k09b", 36));

  return 0;
}
