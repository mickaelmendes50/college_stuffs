#include <stdio.h>
#include <string.h>

int main () {
    char pais[20], brasil[20] = "brasil", alemanha[20] = "alemanha", austria[20] = "austria", coreia[20] = "coreia", espanha[20] = "espanha";

    scanf("%s", pais);

    if (strcmp(pais, brasil) == 0) {
        printf("Feliz Natal!");
    } else if (strcmp(pais, alemanha) == 0) {
        printf("Frohliche Weihnachten!");
    } else if (strcmp(pais, austria) == 0) {
        printf("Frohe Weihnacht!");
    } else if (strcmp(pais, coreia) == 0) {
        printf("Chuk Sung Tan!");
    } else if (strcmp(pais, espanha) == 0) {
        printf("Feliz Navidad!");
    } else {
        printf("-- NOT FOUND --");
    }

    return 0;
}
