#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} Ponto;

void ler_pontos(int n, Ponto* pontos) {
    for (int i = 0; i < n; i++)
        scanf("%lf %lf", &pontos[i].x, &pontos[i].y);
}

void calcular_centroide(int n, Ponto* pontos, Ponto* centroide) {
    centroide->x = centroide->y = 0;

    for (int i = 0; i < n; i++) {
        centroide->x += pontos[i].x;
        centroide->y += pontos[i].y;
    }

    centroide->x /= n;
    centroide->y /= n;
}

int main(void) {
    Ponto centro;
    int n;

    // ler n
    scanf("%d", &n);

    // alocar pontos
    Ponto *pontos = malloc(n * sizeof(Ponto));
    if (pontos == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return 1;
    }

    // ler pontos
    ler_pontos(n, pontos);

    // calcular centroide
    calcular_centroide(n, pontos, &centro);

    // imprimir centroide
    printf("Centroide: (%lf, %lf)\n", centro.x, centro.y);

    // liberar memória
    free(pontos);

    return 0;
}
