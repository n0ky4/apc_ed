#include <stdio.h>

const int CENTAVOS[12] = {
    10000,5000,2000,1000,500,200, // notas
    100,50,25,10,5,1 // moedas
};

int main(void) {
    double r;
    int i, y;

    scanf("%lf", &r);
    y = (int)(r * 100.0);

    printf("NOTAS:\n");
    for (i = 0; i < 12; i++) {
        if (i == 6) printf("MOEDAS:\n");

        if (i <= 5) printf("%d nota", y / CENTAVOS[i]);
        else printf("%d moeda", y / CENTAVOS[i]);

        printf("(s) de R$ %.2f\n", CENTAVOS[i] / 100.0);
        y %= CENTAVOS[i];
    }

    return 0;
}
