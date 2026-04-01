#include <stdio.h>

// constantes
#define W (200)
#define H (100)
#define AREA_TOTAL ((W*3) * H)

// função auxiliar para retornar o valor máximo entre 2 valores
int max(int a, int b) {
    return a > b ? a : b;
}

// função auxiliar para ordenar 3 números em ordem crescente
void ordenar_numeros(int* a, int* b, int* c) {
    int tmp;
    if (*a > *b) { tmp = *a; *a = *b; *b = tmp; }
    if (*a > *c) { tmp = *a; *a = *c; *c = tmp; }
    if (*b > *c) { tmp = *b; *b = *c; *c = tmp; }
}

int main(void) {
    int f1, f2, f3;
    scanf("%d %d %d", &f1, &f2, &f3);

    // ordenar posições iniciais
    ordenar_numeros(&f1, &f2, &f3);

    // calcular a posição final de cada folha (pos_inicial + comprimento)
    int end_f1 = f1 + W;
    int end_f2 = f2 + W;
    int end_f3 = f3 + W;

    int acumulado = 0; // acumulado é a união do comprimento de todas as folhas

    int inicio = f1;
    int fim = end_f1;

    // checar f2
    if (f2 <= fim) {
        // sobrepõe
        fim = max(fim, end_f2);
    } else {
        // não sobrepõe
        acumulado += fim - inicio;
        inicio = f2;
        fim = end_f2;
    }

    // checar f3
    if (f3 <= fim) {
        // sobrepõe
        fim = max(fim, end_f3);
    } else {
        // não sobrepõe
        acumulado += fim - inicio;
        inicio = f3;
        fim = end_f3;
    }

    // adicionar o último intervalo
    acumulado += fim - inicio;

    // calcular a área das folhas e da janela aberta
    int area = acumulado * H;
    int area_aberta = AREA_TOTAL - area;
    
    printf("%d\n", area_aberta);

    return 0;
}
