#include <stdio.h>

int main(void) {
    int x, n[10];
    scanf("%d", &x);

    for (int i = 0; i < 10; i++) {
        if (i == 0) n[i] = x;
        else n[i] = n[i-1]*2;
        printf("N[%d] = %d\n", i, n[i]);
    }

    return 0;
}
