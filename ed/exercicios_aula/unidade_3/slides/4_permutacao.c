#include <stdio.h>

void ler_matriz_quad(int n, int A[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("Digite o número (%d, %d): ", i, j);
            scanf("%d", &A[i][j]);
        }
    }
}

void imprimir_matriz_quad(int n, int A[n][n]) {
     for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            printf("%3d ", A[i][j]);
        printf("\n");
    }
}

int eh_matriz_permutacao(int n, int A[n][n]) {
    for (int i = 0; i < n; i++) {
        // contadores de 1's (linha e coluna)
        int count_l = 0, count_c = 0;

        for (int j = 0; j < n; j++) {
            // x = percorre linha ; y = percorre coluna
            int x = A[i][j], y = A[j][i];

            // checar se encontrou algum numero
            // diferente de 0 ou 1
            if (
                (x != 0 && x != 1) ||
                (y != 0 && y != 1)
            ) return 0;

            // atualizar contadores se encontrar 1
            if (x == 1) count_l++;
            if (y == 1) count_c++;

            // se algum contador ultrapassar 1, é falso (early exit)
            if (count_l > 1 || count_c > 1) return 0;
        }

        // se algum contador não for igual a 1, é falso
        if (count_l != 1 || count_c != 1) return 0;
    }

    return 1;
}

int main(void) {
    int n;
    printf("Digite N: ");
    scanf("%d", &n);

    int A[n][n];
    ler_matriz_quad(n, A);

    printf("\nMatriz:\n");
    imprimir_matriz_quad(n, A);

    printf("É matriz de permutação? %s\n", eh_matriz_permutacao(n, A) ? "SIM" : "NÃO");

    return 0;
}
