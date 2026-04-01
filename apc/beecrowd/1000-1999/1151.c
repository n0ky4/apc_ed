#include <stdio.h>

typedef unsigned long long llu;

int main(void) {
    int n;
    scanf("%d", &n);

    llu a = 0, b = 1;

    for (int i = 0; i < n; i++) {
        printf("%llu", a);
        if (i != n - 1) printf(" ");

        llu fib = a + b;
        a = b;
        b = fib;
    }

    return 0;
}
