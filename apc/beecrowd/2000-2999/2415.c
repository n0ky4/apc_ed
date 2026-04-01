#include <stdio.h>

int main(void) {
    int x, n, anterior, atual = 1, maior = 1;
    scanf("%d", &n);

    // ler o primeiro número e armazená-lo como anterior
    scanf("%d", &anterior);

    // iniciar o loop no índice 1
    // (já armazenamos o anterior)
    for (int i = 1; i < n; i++) {
        // ler número atual
        scanf("%d", &x);

        // se x for igual ao anterior,
        // acrescentar 1 ao atual
        if (x == anterior) atual++;
        else atual = 1; // se não for, resetar atual para 1

        // se atual for maior que o maior consecutivo,
        // setar maior como atual.
        if (atual > maior) maior = atual;

        // setar o número atual como `anterior`
        // para a próxima iteração
        anterior = x;
    }

    printf("%d\n", maior);
    return 0;
}
