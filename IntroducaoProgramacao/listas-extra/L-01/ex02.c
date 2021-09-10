#include <stdio.h>

int main(int argc, char const *argv[])
{
    int a = 2+4;
    int b = 10 - 4 > 7;
    int c = (2*3)>(3*2);
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    printf("b: %d\n", c);

    /*
    // Resultado:
    // a = 6
    // b = 0
    // c = 0
    */
    return 0;
}
