#include <stdio.h>

long long granizo(long long h) {
    if (h == 1) return 1; // caso base
    long long proximo = (h % 2 == 0) ? (h / 2) : (h * 3 + 1);
    long long m = granizo(proximo);
    return (h > m) ? h : m;
}

int main(void) {
    int H;

    while (scanf("%d", &H) == 1 && H != 0) {
        printf("%lld\n", granizo(H));
    }

    return 0;
}
