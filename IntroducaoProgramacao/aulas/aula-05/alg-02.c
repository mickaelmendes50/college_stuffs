#include <stdio.h>

main () {
    float preco, aVista, cheque, cCredito2x, cCredito3x;
    int pagamento;
    printf("Adicione o preco do produto \n");
    scanf("%f", &preco);
    printf("Selecione a forma de pagamento: \n 1 - A Vista \n 2 - Cheque \n 3 - Cartao de Credito 2x \n 4 - Cartao de Credito 3x \n 5 - Negociar \n\n");
    scanf("%d", &pagamento);

    switch (pagamento) {
    case 1:
    aVista = preco-(preco * 0.25);
    printf("O preco com desconto e de R$%.2f", aVista);
    break;

    case 2:
    cheque = preco-(preco * 0.2);
    printf("O preco com desconto e de R$%.2f", cheque);
    break;

    case 4:
    cCredito2x = preco-(preco * 0.1);
    printf("O preco com desconto e de R$%.2f", cCredito2x);
    break;

    case 5:
    cCredito3x = preco-(preco * 0.05);
    printf("O preco com desconto e de R$%.2f", cCredito3x);
    break;

    default:
        printf("Sem desconto \nPreco padrao de %f", preco);
    }

}
