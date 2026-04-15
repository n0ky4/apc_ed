#include <stdio.h>
#include <stdlib.h>

int main(void) {
    double media, *notas;
    int n;

    // ler n  
    scanf("%d", &n);

    // alocar notas
    notas = malloc(n * sizeof(int));
    if (notas == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        return 1;
    }

    // ler notas
    for (int i = 0; i < n; i++)
        scanf("%lf", &notas[i]);
    
    // calcular média
    media = 0;
    for (int i = 0; i < n; i++)
        media += notas[i];
    media /= n;

    // imprimir média
    printf("Média: %.2lf\n", media);
    
    // liberar memória
    free(notas);

    return 0;
}
