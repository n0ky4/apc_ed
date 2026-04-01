#include <stdio.h>

long long potencia(int x, int y) {
    if (x != 0 && y == 0) return 1;
    long long tmp = x;
    for (int i = 1; i < y; i++) tmp *= x;
    return tmp;
}

int main(void) {
    int x, y;
    scanf("%d %d", &x, &y);

    if (y < 0) {
        printf("Ainda nao lidamos com expoentes negativos.\n");
        return 0;
    }

    printf("%lld\n", potencia(x, y));

    return 0;
}
