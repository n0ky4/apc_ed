#include <stdio.h>

void ler_matriz(int n, int m, double A[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("Digite o número (%d, %d): ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
}

void imprimir_matriz(int n, int m, double A[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5.1f ", A[i][j]);
        printf("\n");
    }
}

void multiplicar_matriz(int an, int am, int bn, int bm, double A[an][am], double B[bn][bm], double C[an][bm]) {
    for (int i = 0; i < an; i++) { // percorre a linha A
        for (int j = 0; j < bm; j++) { // percorre a coluna B
            C[i][j] = 0;
            for (int k = 0; k < am; k++) // somatório
                C[i][j] += A[i][k] * B[k][j];
        }
    }
}

int main(void) {
    int an, am, bn, bm;
    printf("Digite o tamanho da matriz A (n m): ");
    scanf("%d %d", &an, &am);

    printf("Digite o tamanho da matriz B (n m): ");
    scanf("%d %d", &bn, &bm);

    if (am != bn) {
        printf("Erro: O número de colunas da matriz A deve ser igual ao número de linhas da matriz B!\n");
        return 1;
    }

    double A[an][am], B[bn][bm], C[an][bm];

    printf("\n[Matriz A (%d x %d)]:\n", an, am);
    ler_matriz(an, am, A);

    printf("\n[Matriz B (%d x %d)]:\n", bn, bm);
    ler_matriz(bn, bm, B);

    printf("\n[Matriz C (%d x %d)]:\n", an, bm);
    multiplicar_matriz(an, am, bn, bm, A, B, C);
    imprimir_matriz(an, bm, C);

    return 0;
}

