#include <stdio.h>

double potencia(double a, int b) {
    double res = a;
    for (int i = 1; i < b; i++) // b - 1 multiplicações
        res *= a;
    return res;
}

int main(void) {
    double a;
    int b;

    while (1) {
        printf("> ");
        scanf("%lf %d", &a, &b);
        printf("%lf^%d = %lf\n", a, b, potencia(a, b));
    }

    return 0;
}
