#include <stdio.h>

int toggle(int value, int bit) {
	value ^= (1 << bit);
	return value;
}

int main() {
  int value;

  value = 0x00000000;
  toggle(value, 0);
  printf("0x00000001 == 0x%08X\n", toggle(value, 0));

  value = 0xF0000000;
  toggle(value, 31);
  printf("0x70000000 == 0x%08X\n", toggle(value, 31));

  value = 0xF002000F;
  toggle(value, 16);
  printf("0xF003000F == 0x%08X\n", toggle(value, 16));

  return 0;

}
