#include <stdio.h>
#include <math.h>

double calculo_iterativo(double inicial, double mensal, double juros, int meses) {
    double final = inicial;
    double juros_normalizado = 1.0 + (juros / 100.0);
    for (int i = 0; i < meses; i++) {
        final *= juros_normalizado; // aplicar juros
        final += mensal; // aplicar depósito
    }
    return final;
}

double calculo_direto(double inicial, double mensal, double juros, int meses) {
    double i = juros / 100.0; // juros em decimal
    double pot = pow(1 + i, meses);
    double valor_inicial = inicial * pot; // dinheiro inicial + juros n vezes
    double deposito_mensal = mensal * ((pot - 1.0) / i); // depósitos mensais (pg)
    return valor_inicial + deposito_mensal; // final = valor_inicial + deposito_mensal
}

int main(void) {
    double inicial, mensal, juros;
    int meses;

    printf("Digite o depósito inicial: ");
    scanf("%lf", &inicial);

    printf("Digite o depósito mensal: ");
    scanf("%lf", &mensal);
    
    printf("Digite o juros (porcento ao mês): ");
    scanf("%lf", &juros);

    printf("Digite o número de meses: ");
    scanf("%d", &meses);

    printf("Final (iterativo): R$ %.2lf\n", calculo_iterativo(inicial, mensal, juros, meses));
    printf("Final (direto): R$ %.2lf\n", calculo_direto(inicial, mensal, juros, meses));

    return 0;
}
