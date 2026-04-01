#include <stdio.h>

void ler_matriz(int n, int m, double A[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Digite o número (%d, %d): ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
}

int eh_simetrica(int n, double A[n][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            if (A[i][j] != A[j][i]) return 0;
    return 1;
}

void imprimir_matriz(int n, int m, double A[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            printf("%.1f ", A[i][j]);
        printf("\n");
    }
} 

int main(void) {
    int n;
    printf("Digite o tamanho da matriz quadrada (n): ");
    scanf("%d", &n);

    double A[n][n];
    ler_matriz(n, n, A);
    imprimir_matriz(n, n, A);

    printf("É simétrica? %s\n", eh_simetrica(n, A) ? "SIM" : "NÃO");

    return 0;
}
