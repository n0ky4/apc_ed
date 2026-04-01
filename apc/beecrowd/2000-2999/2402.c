#include <stdio.h>
#include <math.h>

int primo(long long n) {
    if (n < 2) return 0;
    if (n == 2) return 1;
    if (n % 2 == 0) return 0;

    long long raiz = (long long)sqrt(n);
    for (long long i = 3; i <= raiz; i += 2) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main(void) {
    long long n;

    scanf("%lld", &n);

    if (primo(n)) {
        printf("N\n");
    } else {
        printf("S\n");
    }

    return 0;
}
