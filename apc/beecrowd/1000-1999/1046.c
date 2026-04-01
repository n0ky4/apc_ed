#include <stdio.h>

int output(int h) {
    printf("O JOGO DUROU %d HORA(S)\n", h);
    return 0;
}

int main(void) {
    int inicio, fim;
    scanf("%d %d", &inicio, &fim);

    if (inicio == fim) return output(24);
    
    int total = 0;
    while (inicio != fim) {
        total++;
        inicio++;
        if (inicio >= 24) inicio = 0;
    }

    return output(total);
}
