#include <stdio.h>

#define MAX 100

typedef struct {
    double x, y;
} Ponto;

int ler_n() {
    int n, valid = 0;
    while (!valid) {
        printf("Digite N: ");
        scanf("%d", &n);

        if (n <= 0 || n > MAX) {
            printf("Erro: intervalo inválido.\n");
            continue;
        }

        valid = 1;
    }
    return n;
}

int main(void) {
    Ponto pontos[MAX], centroide;
    int n = ler_n();

    for (int i = 0; i < n; i++) {
        printf("Digite as coordenadas do ponto %d: ", i);
        scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
    }

    centroide.x = centroide.y = 0.0;

    for (int i = 0; i < n; i++) {
        Ponto p = pontos[i];
        centroide.x += p.x / n;
        centroide.y += p.y / n;
    }

    printf("Centroide: (%lf, %lf)\n", centroide.x, centroide.y);

    return 0;
}
