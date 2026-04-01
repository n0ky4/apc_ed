#include <stdio.h>

// mín. fótons interpretados pelo cérebro (40.000.000)
#define F_INTERP (40000000)

int main(void) {
    int area_abertura; // a

    // printf("Digite área de abertura (a): ");
    scanf("%d", &area_abertura);

    int qtd_estrelas; // n
    // printf("Digite a quantidade de estrelas (n): ");
    scanf("%d", &qtd_estrelas);

    int estrelas_percebidas = 0;

    for (int i = 0; i < qtd_estrelas; i++) {
        int fotons; // f

        // printf("Digite fótons/s/mm² da estrela %d: ", i);
        scanf("%d", &fotons);

        int percebidos = fotons * area_abertura;
        // printf("Fótons percebidos: %d\n", percebidos);

        if (percebidos >= F_INTERP) {
            estrelas_percebidas++;
            // printf("Estrela %d percebida! (%d)\n", i, estrelas_percebidas);
        }
    }

    printf("%d\n", estrelas_percebidas);
    
    return 0;
}
