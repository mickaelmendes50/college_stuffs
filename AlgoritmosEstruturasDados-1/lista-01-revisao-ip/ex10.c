#include <stdio.h>
#include <math.h>
#define PI 3.14159265

int main () {
    char option;
    int quant, i, aux;
    double r, R, h, result;
    //puts("Quantas formas geometricas?");
    scanf("%d", &quant);

    if (quant >= 1) {
        for (i = 0; i < quant; i++) {
            //puts("Escolha uma opcao");
            //puts(" C - Circulo");
            //puts(" E - Elipse");
            //puts(" T - Triangulo");
            //puts(" Z - Trapezio");
            scanf("%c", &option);
            //printf("%c", option);

            if (option == 'C') {
                //puts("Insira o raio");
                scanf("%lf", &r);
                result = PI*(r*r);
                aux = result;
                if (result + 0.5 >= aux+1) {
                    printf("%d", aux+1);
                } else {
                    printf("%d", aux);
                }
                //printf("%.4lf\n", result);
            } else if (option == 'E') {
                //puts("Insira os dois raios");
                scanf("%lf %lf", &r, &R);
                result = r*R*PI;
                aux = result;
                if (result + 0.5 >= aux+1) {
                    printf("%d", aux+1);
                } else {
                    printf("%d", aux);
                }
                //printf("%.4lf\n", r*R*PI);
            } else if (option == 'T') {
                //puts("Insira a base e a altura");
                scanf("%lf %lf", &r, &R);
                result = (r*R)/2;
                aux = result;
                if (result + 0.5 >= aux+1) {
                    printf("%d", aux+1);
                } else {
                    printf("%d", aux);
                }
                //printf("%.4lf\n", (r*R)/2);
            } else if (option == 'Z') {
                //puts("Insira as duas bases");
                scanf("%lf %lf", &r, &R);
                //puts("insira a altura");
                scanf("%lf", &h);
                result = ((r+R)*h)/2;
                aux = result;
                if (result + 0.5 >= aux+1) {
                    printf("%d", aux+1);
                } else {
                    printf("%d", aux);
                }
                //printf("%.4lf\n", ((r+R)*h)/2);
            }
        }
    }
    
    return 0;
}