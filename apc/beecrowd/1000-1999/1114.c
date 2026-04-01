#include <stdio.h>

int main(void) {
    while (1) {
        int d;
        scanf("%d", &d);

        if (d == 2002) {
            printf("Acesso Permitido\n");
            break;
        } else printf("Senha Invalida\n");
    }

    return 0;
}
