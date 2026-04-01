#include <stdio.h>

int main(void) {
    int par = 0, imp = 0, p = 0, n = 0;

    for (int i = 0; i < 5; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (tmp % 2 == 0) par++;
        else imp++;

        if (tmp > 0) p++;
        if (tmp < 0) n++;
    }

    printf("%d valor(es) par(es)\n", par);
    printf("%d valor(es) impar(es)\n", imp);
    printf("%d valor(es) positivo(s)\n", p);
    printf("%d valor(es) negativo(s)\n", n);

    return 0;
}
