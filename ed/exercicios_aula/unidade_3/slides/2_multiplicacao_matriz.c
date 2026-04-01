#include <stdio.h>

void ler_matriz_quadrada(const int n, int mtx[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite o número (%d, %d): ", i, j);
            scanf("%d", &mtx[i][j]);
        }
    }    
}

void multiplicar_matrizes(const int n, const int a[n][n], const int b[n][n], int c[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int soma = 0;
            for (int k = 0; k < n; k++) {
                int xa = a[i][k];
                int xb = b[k][j];
                soma += xa * xb;
            }
            c[i][j] = soma;
        }
    }
}

void imprimir_matriz_quadrada(const int n, const int mtx[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", mtx[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Digite o valor de N: ");
    scanf("%d", &n);

    int a[n][n], b[n][n], c[n][n];

    printf("[MATRIZ A]\n");
    ler_matriz_quadrada(n, a);
    imprimir_matriz_quadrada(n, a);

    printf("[MATRIZ B]\n");
    ler_matriz_quadrada(n, b);
    imprimir_matriz_quadrada(n, b);

    multiplicar_matrizes(n, a, b, c);

    printf("\nResultado:\n");
    imprimir_matriz_quadrada(n, c);

    return 0;
}
