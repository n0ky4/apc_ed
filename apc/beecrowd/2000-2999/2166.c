#include <stdio.h>

double frac(int n) {
    // Caso Base: Quando n for 0, resultado é 0.
    if (n == 0) return 0.0;
    return 1.0 / (2.0 + frac(n - 1));
}

int main(void) {
    int n;
    scanf("%d", &n);

    double res = 1.0 + frac(n);

    printf("%.10lf\n", res);
    return 0;
}
