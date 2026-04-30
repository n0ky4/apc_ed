#include <stdio.h>

double potencia(double a, int b) {
    if (b <= 0) return 1;
    return a * potencia(a, b - 1);
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
