#include <iostream>

using namespace std;

// Função para comparar dois inteiros e retornar o maior
int max(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
} 

struct Pedido{
    int tempo;
    int pizzas;
};

struct Pedido pedidos[20];
int matriz[20][30];

int main(void) {

    int N; // Numero de pedidos
    int P; // Numero maximo de pizzas que podem ser entregues por Roberto

    do {

        cin >> N;   // entrada 1
        if (N == 0) // Se for igual a zero, saia do laço para encerrar o programa
            break;
        
        // Verifica se o valor de entrada esta no escopo definido pelo exercicio
        if (1 <= N && N <= 20 ) {
            //do {
                cin >> P; // entrada 2                
            //} while (P <= 1 || P >= 30); // Verifica se o valor de entrada esta no escopo definido pelo exercicio
            
            for(int i = 1; i <= N; i++)
                // N entradas contendo o tempo e o numero de pizzas
                cin >> pedidos[i].tempo >> pedidos[i].pizzas;
                
                for(int i = 0; i <= N; i++) {
                    for(int j = 0; j <= P; j++) {
                        if(i == 0 || j == 0) {
                            matriz[i][j] = 0;
                        } else {
                            if(pedidos[i].pizzas > j) {
                                matriz[i][j] = matriz[i-1][j];
                            } else {
                                // Aplica a equação de recorrência do metodo da mochila
                                matriz[i][j] = max(matriz[i-1][j-pedidos[i].pizzas] + pedidos[i].tempo, matriz[i-1][j]);
                            }
                        }
                    }
                }
            cout << matriz[N][P] << " min." << endl;        
        }
    } while (N != 0);

    return 0;
}
