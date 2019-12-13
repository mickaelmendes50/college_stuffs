#include <stdio.h>

unsigned long int conversor(long int num, long int bin, long int aux) {
    if (num < 2) {
        bin += (num%2)*aux;
        //printf("%d", (num%2)*aux);
        return bin;
    }
    bin += (num%2)*aux;
    //printf("%d", (num%2)*aux);
    return conversor(num/2, bin, aux*10);
}

int main() {
    unsigned long int k, num, bin = 0;
    scanf("%ld", &k);

    while (k > 0) {
        scanf("%ld", &num);
        printf("%ld\n", conversor(num, bin, 1));
        k--;
    }

    return 0;
}