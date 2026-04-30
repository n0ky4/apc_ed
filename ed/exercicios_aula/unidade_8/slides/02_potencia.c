#include <stdio.h>

double potencia(double a, int b) {
    if (b <= 0) return 1;
    return a * potencia(a, b - 1);
}

int main(void) {
    for (int i = 1; i <= 10; i++) {
        printf("2^%d = %lf\n", i, potencia(2, i));
    }
    return 0;
}
