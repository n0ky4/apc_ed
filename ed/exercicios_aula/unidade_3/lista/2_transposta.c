#include <stdio.h>

void ler_matriz(int n, int m, double A[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Digite o número (%d, %d): ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
}

void calcular_transposta(int n, int m, double A[n][m], double B[m][n]) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            B[j][i] = A[i][j];
}

void imprimir_matriz(int n, int m, double A[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) 
            printf("%.1f ", A[i][j]);
        printf("\n");
    }
} 

int main(void) {
    int n, m;
    printf("Digite o tamanho da matriz (n m): ");
    scanf("%d %d", &n, &m);

    double A[n][m], B[m][n];
    ler_matriz(n, m, A);
    calcular_transposta(n, m, A, B);

    printf("\nMatriz:\n");
    imprimir_matriz(n, m, A);
    
    printf("\nTransposta:\n");
    imprimir_matriz(m, n, B);

    return 0;
}
