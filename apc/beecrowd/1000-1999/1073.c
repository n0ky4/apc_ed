#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 1; i <= n / 2; i++) {
        int j = 2*i;
        printf("%d^2 = %d\n", j, j*j);
    }

    return 0;
}
