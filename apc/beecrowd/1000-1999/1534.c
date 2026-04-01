#include <stdio.h>

int is_primary(int x, int y) { return x == y; }
int is_secondary(int x, int y, int n) { return y == ((n-1) - x); }

void gerar_matriz(int n, int matriz[n][n]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (is_secondary(i, j, n)) matriz[i][j] = 2;
            else if (is_primary(i, j)) matriz[i][j] = 1;
            else matriz[i][j] = 3;

            printf("%d", matriz[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        int matriz[n][n];
        gerar_matriz(n, matriz);
    }
    
    return 0;
}
