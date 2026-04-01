#include <stdio.h>

int main(void) {
    float np[6], m = 0;
    int p = 0;

    for (int i = 0; i < 6; i++) {
        float tmp;
        scanf("%f", &tmp);

        if (tmp > 0) {
            np[p] = tmp;
            m += tmp;
            p++;
        }
    }

    m /= (float)p;
    printf("%d valores positivos\n%.1f\n", p, m);

    return 0;
}
