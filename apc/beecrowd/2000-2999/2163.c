#include <stdio.h>

// Função para checar se todos os vizinhos do ponto (x,y) existem
int has_borders(int x, int y, int n, int m) {
    // checa se está fora dos limites da matriz
    if (x < 0 || x >= n || y < 0 || y >= m)
        return 0;

    // checa se tem bordas
    if (x > 0 && x < n - 1 && y > 0 && y < m - 1)
        return 1;

    return 0;
}

int main(void) {
    int n, m;
    scanf("%d %d", &n, &m);

    int matriz[n][m];

    // leitura da matriz
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matriz[i][j]);

    // checagem
    int found = 0;
    for (int i = 0; i < n && !found; i++) {
        for (int j = 0; j < m && !found; j++) {
            if (matriz[i][j] == 42 && has_borders(i, j, n, m)) {

                int a = matriz[i-1][j-1];
                int b = matriz[i][j-1];
                int c = matriz[i+1][j-1];

                int d = matriz[i-1][j];
                int e = matriz[i+1][j];

                int f = matriz[i-1][j+1];
                int g = matriz[i][j+1];
                int h = matriz[i+1][j+1];

                if (
                    a == 7 && b == 7 && c == 7 &&
                    d == 7 && e == 7 &&
                    f == 7 && g == 7 && h == 7
                ) {
                    printf("%d %d\n", i + 1, j + 1);
                    found = 1;
                }
            }
        }
    }

    if (!found)
        printf("0 0\n");

    return 0;
}
