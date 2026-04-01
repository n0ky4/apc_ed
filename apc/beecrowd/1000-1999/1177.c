#include <stdio.h>

int main(void) {
    int t, n[1000], j;

    scanf("%d", &t);
    j = 0;

    for (int i = 0; i < 1000; i++) {
        if (j == t) j = 0;
        n[i] = j;
        printf("N[%d] = %d\n", i, n[i]);
        j++;
    }

    return 0;
}
