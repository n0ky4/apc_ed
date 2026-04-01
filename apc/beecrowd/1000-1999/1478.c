#include <stdio.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

void imprimir_matriz(int n, int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j == 0) {
                printf("%3d", matriz[i][j]);
            } else {
                printf("%4d", matriz[i][j]);
            }
        }
        printf("\n");
    }
    printf("\n");
}

void gerar_matriz(int n, int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int num = abs(i-j) + 1; // |i-j| + 1 (dist. da diagonal principal)
            matriz[i][j] = num;
        }
    }
}

int main(void) {
    while (1) {
        int n;
        // printf("Entrada: ");
        scanf("%d", &n);
        
        if (n == 0) break;
        else if (n == 1) {
            printf("  1\n\n");
            continue;
        }

        int matriz[n][n];
        gerar_matriz(n, matriz);
        imprimir_matriz(n, matriz);
    }

    return 0;
}
