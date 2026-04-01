#include <stdio.h>

int main(void) {
    float total = 0, coelhos = 0, ratos = 0, sapos = 0;
    int n;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int qtd;
        char tipo;

        scanf("%d %c", &qtd, &tipo);

        switch (tipo) {
            case 'C':
                coelhos += qtd;
                break;
            case 'R':
                ratos += qtd;
                break;
            case 'S':
                sapos += qtd;
                break;
        }

        total += qtd;
    }

    printf("Total: %d cobaias\n", (int)total);

    printf("Total de coelhos: %d\n", (int)coelhos);
    printf("Total de ratos: %d\n", (int)ratos);
    printf("Total de sapos: %d\n", (int)sapos);

    printf("Percentual de coelhos: %.2f %%\n", (coelhos / total)*100.0);
    printf("Percentual de ratos: %.2f %%\n", (ratos / total)*100.0);
    printf("Percentual de sapos: %.2f %%\n", (sapos / total)*100.0);

    return 0;
}
