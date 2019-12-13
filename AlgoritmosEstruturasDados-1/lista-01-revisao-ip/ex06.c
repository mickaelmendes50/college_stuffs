#include <stdio.h>

int main () {
    int nRotulos, nTipos, rot[1000];
    puts("Quantidade de rotulos e tipos de rotulos");
    scanf("%d %d", &nRotulos, &nTipos);

    for (int i = 0; i < nRotulos; i++) {
        scanf("%d", &rot[i]);
    }

    for (int i = 0; i < nRotulos; i++) {
        for (int j = 0; j < nRotulos-1; j++) {
            if (rot[i] < rot[j]) {
                int aux = rot[i];
                rot[i] = rot[j];
                rot[j] = aux;
            }    
        }
    }

    int cont[nRotulos];
    for (int i = 0; i < nRotulos; i++) {
        cont[i] = 1;
        if (rot[i] < rot[i+1]) {
            for (int j = 0; j < nRotulos-1; j++) {        
                if (rot[i] == rot[j]) {
                    cont[i]++;
                }
            }
        }
    }
    
    puts("Resultados");
    for (int i = 0; i < nRotulos; i++) {
    //    printf("%d\n", rot[i]);
        printf("%d\n", cont[i]);   
    }
    

    return 0;
}