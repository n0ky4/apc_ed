#include <stdio.h>

int main(void) {
    int maior = 0, pos;

    for (int i = 1; i <= 100; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (tmp > maior) {
            maior = tmp;
            pos = i;
        }
    }

    printf("%d\n%d\n", maior, pos);

    return 0;
}
