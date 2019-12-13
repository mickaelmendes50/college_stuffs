#include <stdio.h>
#include <string.h>

struct translator {
    char brasil[30];
    char alemanha[30];
    char austria[30];
    char coreia[30];
    char espanha[30];
    char grecia[30];
    char estados_unidos[30];
    char inglaterra[30];
    char australia[30];
    char portugal[30];
    char suecia[30];
    char turquia[30];
    char argentina[30];
    char chile[30];
    char mexico[30];
    char antardida[30];
    char canada[30];
    char irlanda[30];
    char belgica[30];
    char italia[30];
    char libia[30];
    char siria[30];
    char marrocos[30];
    char japao[30];
} translate;

int main() {
    char country[15];
    scanf("%s", country);

    *translate.brasil           = "Feliz Natal!";
    *translate.alemanha         = "Frohliche Weihnachten!";
    *translate.austria          = "Frohe Weihnacht!";
    *translate.coreia           = "Chuk Sung Tan!";
    *translate.espanha          = "Feliz Navidad!";
    *translate.grecia           = "Kala Christougena!";
    *translate.estados_unidos   = "Merry Christmas!";
    *translate.inglaterra       = "Merry Christmas!";
    *translate.australia        = "Merry Christmas!";
    *translate.portugal         = "Feliz Natal!";
    *translate.suecia           = "God Jul!";
    *translate.turquia          = "Mutlu Noeller";
    *translate.argentina        = "Feliz Navidad!";
    *translate.chile            = "Feliz Navidad!";
    *translate.mexico           = "Feliz Navidad!";
    *translate.antardida        = "Merry Christmas!";
    *translate.canada           = "Merry Christmas!";
    *translate.irlanda          = "Nollaig Shona Dhuit!";
    *translate.belgica          = "Zalig Kerstfeest!";
    *translate.italia           = "Buon Natale!";
    *translate.libia            = "Buon Natale!";
    *translate.siria            = "Milad Mubarak!";
    *translate.marrocos         = "Milad Mubarak!";
    *translate.japao            = "Merii Kurisumasu!";

    if (strcmp(country, "brasil") == 0) {
        printf("%s", translate.brasil);
    } else if (strcmp(country, "alemanha") == 0) {
        puts(translate.alemanha);
    } if (strcmp(country, "austria") == 0) {
        puts(translate.austria);
    } else if (strcmp(country, "coreia") == 0) {
        puts(translate.coreia);
    } else if (strcmp(country, "espanha") == 0) {
        puts(translate.espanha);
    } else if (strcmp(country, "grecia") == 0) {
        puts(translate.grecia);
    } else if (strcmp(country, "estados-unidos") == 0) {
        puts(translate.estados_unidos);
    } else if (strcmp(country, "inglaterra") == 0) {
        puts(translate.inglaterra);
    } else if (strcmp(country, "australia") == 0) {
        puts(translate.australia);
    } else if (strcmp(country, "portugal") == 0) {
        puts(translate.portugal);
    } else if (strcmp(country, "suecia") == 0) {
        puts(translate.suecia);
    } else if (strcmp(country, "turquia") == 0) {
        puts(translate.turquia);
    } else if (strcmp(country, "argentina") == 0) {
        puts(translate.argentina);
    } else if (strcmp(country, "chile") == 0) {
        puts(translate.chile);
    } else if (strcmp(country, "mexico") == 0) {
        puts(translate.mexico);
    } else if (strcmp(country, "antartida") == 0) {
        puts(translate.antardida);
    } else if (strcmp(country, "canada") == 0) {
        puts(translate.canada);
    } else if (strcmp(country, "irlanda") == 0) {
        puts(translate.irlanda);
    } else if (strcmp(country, "belgica") == 0) {
        puts(translate.belgica);
    } else if (strcmp(country, "italia") == 0) {
        puts(translate.italia);
    } else if (strcmp(country, "libia") == 0) {
        puts(translate.libia);
    } else if (strcmp(country, "siria") == 0) {
        puts(translate.siria);
    } else if (strcmp(country, "marrocos") == 0) {
        puts(translate.marrocos);
    } else if (strcmp(country, "japao") == 0) {
        puts(translate.japao);
    } else {
        puts("-–NOT FOUND--");
    }


    return 0;
}

