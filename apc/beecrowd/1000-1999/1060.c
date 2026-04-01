#include <stdio.h>

int main(void) {
    int p = 0;

    for (int i = 0; i < 6; i++) {
        float tmp;
        scanf("%f", &tmp);
        if (tmp > 0.0) p++;
    }

    printf("%d valores positivos\n", p);

    return 0;
}
