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
    int linha;
    char op;

    scanf("%d %c", &linha, &op);

    double res = 0;
    double matriz[SIZE][SIZE];
    pegar_numeros(matriz);

    for (int j = 0; j < SIZE; j++) {
        double x = matriz[linha][j];
        res += x;
    }

    if (op == 'M') res /= SIZE;

    printf("%.1lf\n", res);
    
    return 0;
}
