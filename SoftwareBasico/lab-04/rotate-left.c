#include <stdio.h>

unsigned char rotate_left(unsigned char x, int n) {
	unsigned char b1 = (x >> 8-n);
	unsigned char b2 = (x << n);
	//printf("0x%08B\n", x);
	//printf("0x%08B\n", b1);
	//printf("0x%08B\n", b2);

	return b1 | b2;
}

int main() {
	char valor = 0x61;
	printf("0x%08X\n", rotate_left(valor, 1));
	printf("0x%08X\n", rotate_left(valor, 2));
	printf("0x%08X\n", rotate_left(valor, 7));

	return 0;
}
