#include <stdio.h>

main () {
    int n1, n2, choise, media, diferenca, produto;
    printf("Informe dois numeros \n");
    scanf("%d %d", &n1, &n2);
    printf("Escolha uma operacao: \n 1- Média entre os números digitados \n 2- Diferença do maior pelo menor \n 3- Produto entre os números digitados \n\n");
    scanf("%d", &choise);

    switch (choise) {
        case 1:
        media = (n1+n2)/2;
        printf("Média entre os números digitados = %d", media);
        break;

        case 2:
        if (n1>n2) {
            diferenca = (n1-n2);
            printf("Diferença do maior pelo menor = %d", diferenca);
        } else {
            diferenca = (n2-n1);
            printf("Diferença do maior pelo menor = %d", diferenca);
        }
        break;

        case 3:
        produto = n1*n2;
        printf("Produto entre os números digitados = %d", produto);
        break;
    }
}
