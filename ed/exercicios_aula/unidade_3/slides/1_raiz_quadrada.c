#include <stdio.h>
#include <math.h>

#define ERRO (1e-12)

double raiz_quadrada(double x) {
    double y = x;
    int erro_pequeno = 0;
    while (!erro_pequeno) {
        double anterior = y;
        y = (y + x / y) / 2.0;
        if (fabs(anterior - y) <= ERRO)
            erro_pequeno = 1;
    }
    return y;
}

int main(void) {
    double n;
    printf("Digite um número: ");
    scanf("%lf", &n);

    printf("Raiz quadrada: %.2lf\n", raiz_quadrada(n));

    return 0;
}
