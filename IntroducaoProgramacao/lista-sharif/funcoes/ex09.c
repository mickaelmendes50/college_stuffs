#include <stdio.h>

int E_Triangulo (float d, float e, float f) {
    if ((d<e+f) && (e<d+f) && (f<d+e)) {
        return 1;
    }

}

float Perimetro (float g, float h, float i) {
    float soma = 0;
    soma = g + h + i;
    return soma;
}

float areaTrapezio (float j, float k, float l) {
    float area = 0;
    area = ((j+k)*l)/2;
    return area;
}

int main () {
    float a, b ,c;
    scanf("%f %f %f", &a, &b, &c);
    if (E_Triangulo(a, b, c) == 1) {
        printf("%.1f", Perimetro(a, b ,c));
    } else {
        printf("%.1f", areaTrapezio(a, b, c));
    }
    return 0;
}
