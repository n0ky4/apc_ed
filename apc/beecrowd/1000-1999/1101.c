#include <stdio.h>

int main(void) {
    while (1) {
        int m, n;
        scanf("%d %d", &m, &n);

        if (m <= 0 || n <= 0) break;

        // trocar de posicao se m > n  
        if (m > n) { int tmp = m; m = n; n = tmp; }

        int s = 0;
        for (int i = m; i <= n; i++) {
            printf("%d ", i);
            s += i;
        }
        printf("Sum=%d\n", s);
    }

    return 0;
}
