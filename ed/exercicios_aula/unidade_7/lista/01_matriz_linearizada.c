#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ERRO_ALOCACAO                                       \
    do {                                                    \
        printf("Erro: Não foi possível alocar memória.\n"); \
        exit(EXIT_FAILURE);                                 \
    } while (0)

double* calcular_centroide(int n, int d, double** pontos) {
    // Alocar centroide
    double *centroide = malloc(d * sizeof(double));
    if (!centroide) ERRO_ALOCACAO;

    // Definir todas as coordenadas do centroide para 0
    for (int i = 0; i < d; i++)
        centroide[i] = 0;

    // Calcular centroide
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < d; j++)
            centroide[j] += pontos[i][j];
    }
    for (int i = 0; i < d; i++)
        centroide[i] /= n;

    return centroide;
}

void imprimir_ponto(int d, double* ponto) {
    printf("(");
    for (int i = 0; i < d; i++)
        printf("%.3lf%s", ponto[i], (i == d-1) ? "" : ", ");
    printf(")");
}

double distancia(int d, double *a, double*b) {
    double soma = 0; // Somatório
    for (int i = 0; i < d; i++) {
        double sub = a[i] - b[i]; // Subtrai a coordenada da dimensão `i` de dois pontos
        soma += (sub * sub); // Soma sub² ao somatório
    }
    return sqrt(soma); // Retorna a raiz quadrada do somatório
}

double soma_distancias(int n, int d, double** pontos, double* centroide) {
    double dist = 0;
    for (int i = 0; i < n; i++)
        dist += distancia(d, pontos[i], centroide);
    return dist;
}

int main(void) {
    int d, n;
    printf("Digite a dimensão dos pontos: ");
    scanf("%d", &d);

    printf("Digite a quantidade de pontos: ");
    scanf("%d", &n);

    // Alocar matriz de pontos  
    double **pontos = malloc(n * sizeof(double*));
    if (!pontos) ERRO_ALOCACAO;

    // Ler coordenadas dos pontos
    for (int i = 0; i < n; i++) {
        pontos[i] = malloc(d * sizeof(double));
        if (!pontos[i]) ERRO_ALOCACAO;

        for (int j = 0; j < d; j++) {
            printf("[Ponto %d] Digite a coordenada %d: ", i+1, j+1);
            scanf("%lf", &pontos[i][j]);
        }
    }

    // Calcular centroide
    double* centroide = calcular_centroide(n, d, pontos);

    // Calcular soma das distâncias de cada ponto para o centroide
    double soma_dist = soma_distancias(n, d, pontos, centroide);

    // Imprimir centroide
    printf("Centroide: ");
    imprimir_ponto(d, centroide); printf("\n");

    // Imprimir soma das distâncias
    printf("Soma das distâncias: %.3lf\n", soma_dist);

    // Liberar centroide
    free(centroide);

    // Liberar pontos
    for (int i = 0; i < n; i++)
        free(pontos[i]);
    free(pontos);

    return 0;
}
