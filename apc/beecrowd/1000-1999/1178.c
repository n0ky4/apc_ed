#include <stdio.h>

int main(void) {
    long double n[100];

    scanf("%Lf", &n[0]);

    for (int i = 0; i < 100; i++) {
        if (i != 0) n[i] = n[i-1] / 2.0;
        printf("N[%d] = %.4Lf\n", i, n[i]);
    }

    return 0;
}
