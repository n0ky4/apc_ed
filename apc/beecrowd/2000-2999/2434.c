#include <stdio.h>

int main(void) {
    int dias, saldo, menor_saldo;

    scanf("%d %d", &dias, &saldo);
    menor_saldo = saldo;

    for (int i = 1; i <= dias; i++) {
        int movimentacao;
        scanf("%d", &movimentacao);

        saldo += movimentacao;
        if (saldo < menor_saldo) menor_saldo = saldo;
    }

    printf("%d\n", menor_saldo);

    return 0;
}
