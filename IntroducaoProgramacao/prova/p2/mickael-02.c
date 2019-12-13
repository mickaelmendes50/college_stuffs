#include <stdio.h>

main () {
    int cFuncionario, qHoras;
    double vHoraTrabalho, sHora, dsr, sBruto, sLiquido, inss, somaBruto=0, somaINSS=0;

    scanf("%lf", &vHoraTrabalho);

    do {
        scanf("%d %d", &cFuncionario, &qHoras);
        if (cFuncionario != -1 && qHoras != -1) {

            sHora = qHoras * vHoraTrabalho * 4.5;
            dsr = qHoras * vHoraTrabalho * 0.75;
            sBruto = sHora + dsr;

            if (sBruto <= 1659.38) {
                inss = sBruto*0.08;
            } else if (sBruto >= 1659.39 && sBruto <= 2765.66) {
                inss = sBruto*0.09;
            } else if (sBruto >= 2765.67 && sBruto <= 5531.31) {
                inss = sBruto * 0.11;
            } else {
                inss = 5531.31*0.11;
            }

            sLiquido = sBruto - inss;
            somaBruto += sBruto;
            somaINSS += inss;

            printf("%d => %.2lf + %.2lf = %.2lf - %.2lf = %.2lf\n", cFuncionario, sHora, dsr, sBruto, inss, sLiquido);
        }
    } while (cFuncionario != -1 && qHoras != -1);
    printf("SOMA DOS SALARIOS BRUTOS: %.2lf\nSOMA DOS INSS: %.2lf", somaBruto, somaINSS);
}

