#include <stdio.h>

main () {
    int matricula, nDependentes;
    float vSalarioMinimo, vSalarioFuncionario, imposto, bruto, liquido, resultado;
    scanf("%d %f %d %f %f", &matricula, &vSalarioMinimo, &nDependentes, &vSalarioFuncionario, &imposto);

    printf("MATRICULA = %d\n", matricula);

    if ((12*vSalarioMinimo) < vSalarioFuncionario) {
        bruto = vSalarioFuncionario*0.2;
    } else if ((5*vSalarioMinimo) < vSalarioFuncionario) {
        bruto = vSalarioFuncionario*0.08;
    } else {
        bruto = 0;
    }
    printf("IMPOSTO BRUTO = %.2f\n", bruto);

    liquido = bruto - (nDependentes*300);
    printf("IMPOSTO LIQUIDO = %.2f\n", liquido);

    imposto = vSalarioFuncionario*(imposto/100);

    resultado = liquido - imposto;
    printf("RESULTADO = %.2f\n", resultado);
    if (resultado < 0) {
        printf("IMPOSTO A RECEBER");
    } else if (resultado == 0) {
        printf("IMPOSTO QUITADO");
    } else {
        printf("IMPOSTO A PAGAR");
    }
}
