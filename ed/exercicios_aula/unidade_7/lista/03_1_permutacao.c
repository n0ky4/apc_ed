#include <stdio.h>
#include <stdlib.h>

void permutar_linha(int n, double matriz[n][n], int i, int j) {
    for (int k = 0; k < n; k++) {
        double tmp = matriz[i][k];
        matriz[i][k] = matriz[j][k];
        matriz[j][k] = tmp;
    }
}

void imprimir_matriz(int n, double matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        printf("[ ");
        for (int j = 0; j < n; j++)
            printf("%5.1lf ", matriz[i][j]);
        printf(" ]\n");
    }
}

int main(void) {
    double matriz[4][4] = {
        {1, 2, 4, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12},
        {13, 14, 15, 16},
    };

    printf("Antes:\n");
    imprimir_matriz(4, matriz);
    permutar_linha(4, matriz, 0, 1);

    printf("\nDepois:\n");
    imprimir_matriz(4, matriz);
    
    return 0;
}
