#include <stdio.h>
#include <stdlib.h>

#define ERRO_MEMORIA                                        \
    printf("Erro: Não foi possível alocar memória.\n");     \
    exit(EXIT_FAILURE)

double ***matriz3d(int m, int n, int k, double valor_padrao) {
    double ***matriz = malloc(sizeof(double**) * m);
    if (matriz == NULL) { ERRO_MEMORIA; }

    for (int i = 0; i < m; i++) {
        matriz[i] = malloc(sizeof(double*) * n);
        if (matriz[i] == NULL) { ERRO_MEMORIA; }

        for (int j = 0; j < n; j++) {
            matriz[i][j] = malloc(sizeof(double) * k);
            if (matriz[i][j] == NULL) { ERRO_MEMORIA; }

            for (int l = 0; l < k; l++)
                matriz[i][j][l] = valor_padrao;
        }
    }
    return matriz;
}

void liberar_matriz3d(double ****matriz, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            free((*matriz)[i][j]);
        free((*matriz)[i]);
    }
    free(*matriz);
    *matriz = NULL;
}

int main(void) {
    int m = 9, n = 6, k = -3;
    double ***matriz = matriz3d(m, n, k, 6.7);

    for (int i = 0; i < m; i++) {
        printf("Camada %d:\n", i + 1);
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < k; l++)
                printf("%5.1lf ", matriz[i][j][l]);
            printf("\n");
        }
    }

    liberar_matriz3d(&matriz, m, n);

    return 0;
}
