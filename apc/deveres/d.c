#include <stdio.h>

double x, y;

void LePonto(void) {
    scanf("%lf %lf", &x, &y);
}

double coef_ang(double x0, double y0, double x1, double y1) {
    return (y1 - y0) / (x1 - x0);
}

int main(void) {
    double x0, y0, x1, y1;

    // Primeiro ponto
    LePonto();
    x0 = x;
    y0 = y;
    
    // Segundo ponto
    LePonto();
    x1 = x;
    y1 = y;

    // Checar se as abcissas são iguais (erro)
    if (x0 == x1) {
        printf("Nao eh possivel determinar o coeficiente angular.\n");
        return 0;
    }

    // Calcular coeficiente angular
    double m = coef_ang(x0, y0, x1, y1);
    printf("%.2lf\n", m);

    return 0;
}
