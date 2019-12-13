#include <stdio.h>

//Função para definir o grau
int grau(int cc, int dr, int rt) {
    int cont=0; //Definimos um contador
    if (cc < 7) {
        cont++; //Se o Carbono atender ao requesito
    }

    if (dr > 50) {
        cont++; //Se a Dureza atender ao requesito
    }

    if (rt > 80000) {
        cont++; //Se a Resistência atender ao requesito
    }
    //Ao final, 'cont' vai retornar 1 ou 2 ou 3
    return cont;
}

int main() {
    int cc, dr, rt, res;
    scanf("%d %d %d", &cc, &dr, &rt);

    /*res vai receber o valor de 'cont' e vai retornar o grau
    conforme o definido no switch*/
    
    res = grau(cc, dr, rt);
    switch (res) {
        case 1:
        printf("ACO DE GRAU = 8");
        break;

        case 2:
        printf("ACO DE GRAU = 9");
        break;

        case 3:
        printf("ACO DE GRAU = 10");
        break;

        default:
        printf("ACO DE GRAU = 7");
    }
    return 0;
}
