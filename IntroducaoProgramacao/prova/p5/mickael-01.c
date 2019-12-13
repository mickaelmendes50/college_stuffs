#include <stdio.h>

int main () {
    int nAlunos, mPresenca, mPontuais = 0, mAtrasados = 0;
    scanf("%d %d", &nAlunos, &mPresenca);

    int mHorario[nAlunos];

    for (int i = 0; i < nAlunos; i++) {
        scanf("%d", &mHorario[i]);

        if (mHorario[i] > 0) {
            mAtrasados++;
        } else {
            mPontuais++;
        }
    }

    if ((mAtrasados - mPresenca) < 0) {
        printf("SIM");
    } else {
        printf("NAO\n");
        for (int i = nAlunos-1; i >= 0; i--) {
            if (mHorario[i] <= 0) {
                printf("%d\n", i+1);
            }
        }
    }

    return 0;
}
