#include <stdio.h>

int funcaoAckermann(int m, int n) {
    if (m == 0) {
        return n + 1;
    } else if (n == 0 && m > 0) {
        return funcaoAckermann(m-1, 1);
    } else {
        return funcaoAckermann(m-1, funcaoAckermann(m, n-1));
    }
}

int main () {
    int m, n;
    scanf("%d %d", &m, &n);
    printf("%d", funcaoAckermann(m, n));
    return 0;
}