#include <stdio.h>

int main() {
    int x, maior = 0, menor = 0, flag = 0;
    printf("Digite uma lista: ");
    
    while (scanf("%d", &x) == 1) {
        if (flag == 0) {
            maior = x;
            menor = x;  
            flag = 1;
        } else {
            if (x > maior) maior = x;
            if (x < menor) menor = x;
        }

        if (getchar() == '\n') break;
    }

    int diff = maior - menor;
    printf("Diferença absoluta é %d.\n", diff);

    return 0;
}
