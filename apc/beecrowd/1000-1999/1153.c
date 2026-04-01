#include <stdio.h>

int fat(int n) {
    if (n == 1) return 1; // caso base
    return n * fat(n - 1); // loop recursivo
}

int main(void) {
    int n;
    scanf("%d", &n);
    printf("%d\n", fat(n));
    return 0;
}
