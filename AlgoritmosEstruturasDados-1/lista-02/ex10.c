#include <stdio.h>

int naturalReverso(int n) {
    if ((n/10) == 0) {
        printf("%d", n);
        return n;
    } else {
        printf("%d", n%10);
        return(naturalReverso(n/10));
    }
}

int main () {
    int n;
    scanf("%d", &n);
    while ((n % 10) == 0) {
        n /= 10;
    }
    naturalReverso(n);
    return 0;
}