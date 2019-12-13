#include <stdio.h>
#include <stdlib.h>

int main (void){
    float n1, n2, n3, result;
    int p1=1, p2=2, p3=3;
    printf("Primeira nota \n");
    scanf("%f", &n1);
    printf("Segunda nota \n");
    scanf("%f", &n2);
    printf("Terceira nota \n");
    scanf("%f", &n3);

    result = ((n1 * p1) + (n2 * p2) + (n3 * p3))/6;
    printf("nota final %.2f \n", result);
}
