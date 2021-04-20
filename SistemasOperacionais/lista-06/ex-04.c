#include <stdio.h>
#include <stdbool.h>

int main(int argc, char const *argv[]) {
    int turn;
    bool flag[2];

    int i; // i representa o processo atual
    int j; // j representa o outro processo

    while (true) {
        flag[i] = true;
        turn = j;
        while (flag[j] && turn == j);
        /* secao critica */
        flag[i] = false;
        /* secao nao critica */
    }    
    return 0;
}
