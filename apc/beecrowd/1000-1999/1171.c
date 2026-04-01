#include <stdio.h>

int main(void) {
    int x, n, count[2001] = { 0 };
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        count[x]++;
    }

    for (int i = 0; i <= 2000; i++) {
        if (count[i] > 0)
            printf("%d aparece %d vez(es)\n", i, count[i]);
    }

    return 0;
}
