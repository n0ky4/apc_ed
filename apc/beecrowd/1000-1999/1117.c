#include <stdio.h>

int main(void) {
    int v = 0;
    float m = 0;

    while (v != 2) {
        float n;
        scanf("%f", &n);

        if (n < 0 || n > 10) {
            printf("nota invalida\n");
            continue;
        }

        m += n;
        v++;
    }

    m /= 2.0;
    printf("media = %.2f\n", m);

    return 0;
}
