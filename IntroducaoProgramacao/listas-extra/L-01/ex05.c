#include <stdio.h>

int main(int argc, char const *argv[]) {
    
    // Entada dos dados
    float dolar, cotacao;
    printf("Valor em dólar: U$ ");
    scanf("%f", &dolar);
    printf("Cotação atual: R$ ");
    scanf("%f", &cotacao);

    // Converte USD -> BRL
    float result = dolar * cotacao;
    printf("O valor em real é: %.2f\n", result);
    return 0;
}
