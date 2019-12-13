#include <stdio.h>

double fatorialDuplo(double n) {
    int m = n;
    if (m == 1) {
        return n;
    } else if (m == 2) {
        return 1;
    } else if (m%2 == 0) {
        return (n-1) * fatorialDuplo(n-3);
    } else {
        return n * fatorialDuplo(n-2);
    }
}

int main () {
    double n;
    scanf("%lf", &n);
    printf("%.0lf", fatorialDuplo(n));

    return 0;
}