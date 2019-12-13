#include <stdio.h>

main () {
    int qPessoas, tEscola, mEtnia, l1=0, l2=0, l3=0, l4=0, nCotista=0;
    float rBruta, rpc;

    do {
        scanf("%f %d %d %d", &rBruta, &qPessoas, &tEscola, &mEtnia);
        rpc = rBruta/qPessoas;

        if (rBruta != -1 && qPessoas != -1 && tEscola != -1 && mEtnia != -1) {
            if (tEscola == 2 && rpc <= (937*1.5) && mEtnia >= 4) {
                printf("ALUNO COTISTA (L1)\n");
                l1++;
            } else if (tEscola == 2 && rpc <= (937*1.5) && mEtnia < 4) {
                printf("ALUNO COTISTA (L2)\n");
                l2++;
            } else if (tEscola == 2 && rpc > (937*1.5) && mEtnia >= 4) {
                printf("ALUNO COTISTA (L3)\n");
                l3++;
            } else if (tEscola == 2 && rpc > (937*1.5) && mEtnia < 4) {
                printf("ALUNO COTISTA (L4)\n");
                l4++;
            } else {
                printf("ALUNO NAO COTISTA\n");
                nCotista++;
            }
        }
    } while (rBruta != -1 && qPessoas != -1 && tEscola != -1 && mEtnia != -1);
    printf("TOTAL (L1): %d\nTOTAL (L2): %d\nTOTAL (L3): %d\nTOTAL (L4): %d\nTOTAL NAO COTISTA: %d", l1, l2, l3, l4, nCotista);
}
