#include <stdio.h>

double peso_ideal(double h, char sexo) {
    int k = sexo == 'M' ? 23 : 20; // 23 (H)  |  20 (F)
    return k * (h*h);
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        double altura;
        char sexo;

        scanf("%lf %c", &altura, &sexo);

        double p = peso_ideal(altura, sexo);
        printf("Peso ideal: %.2lf\n", p);
    }

    return 0;
}
