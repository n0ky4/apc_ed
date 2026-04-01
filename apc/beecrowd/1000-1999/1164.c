#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, s = 0;
        scanf("%d", &x);

        for (int j = 1; j < x; j++) if (x % j == 0) s += j;

        if (x == s) printf("%d eh perfeito\n", x);
        else printf("%d nao eh perfeito\n", x);
    }
    
    return 0;
}
