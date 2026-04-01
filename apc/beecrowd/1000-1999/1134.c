#include <stdio.h>

int main(void) {
    int a = 0, g = 0, d = 0;

    while (1) {
        int x;
        scanf("%d", &x);

        if (x == 4) break;

        switch (x) {
            case 1: a++; break;
            case 2: g++; break;
            case 3: d++; break;
        }
    }

    printf("MUITO OBRIGADO\nAlcool: %d\nGasolina: %d\nDiesel: %d\n", a, g, d);
    return 0;
}
