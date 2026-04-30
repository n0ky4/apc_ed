#include <stdio.h>

int fat_rec(int n) {
    if (n <= 1) return 1;
    return n * fat_rec(n - 1); // n - 1 multiplicações
}

int fat_it(int n) {
    int res = n;
    for (int i = n - 1; i > 0; i--) 
        res *= i; // n - 1 multiplicações 
    return res; 
}

int main(void) {
    int n;

    while (1) {
        printf("> ");
        scanf("%d", &n);
        if (n == -1) break;

        printf("%d! (rec) = %d\n", n, fat_rec(n));
        printf("%d! (ite) = %d\n", n, fat_it(n));
    }

    return 0;
}
