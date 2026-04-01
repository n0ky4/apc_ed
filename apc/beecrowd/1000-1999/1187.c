#include <stdio.h>

#define SIZE 12

void pegar_numeros(double matriz[SIZE][SIZE]) {
    int coluna = 0, linha = 0;
    for (int i = 0; i < (SIZE*SIZE); i++) {
        scanf("%lf", &matriz[coluna][linha]);

        linha++;
        if (linha > (SIZE-1)) {
            linha = 0;
            coluna++;
        }
    }
}

int main(void) {
    char op;

    scanf("%c", &op);

    double res = 0;
    double matriz[SIZE][SIZE];
    int count = 0;

    pegar_numeros(matriz);

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int a = (SIZE-1) - i;

            if (j < a && j > i) {
                res += matriz[i][j];
                count++;
            }
        }
    }

    if (op == 'M') res /= count;

    printf("%.1lf\n", res);
    
    return 0;
}
