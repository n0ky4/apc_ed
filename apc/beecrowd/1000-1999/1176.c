#include <stdio.h>

int main(void) {
    int t, s = 2;
    long long unsigned int fib[61] = {0, 1};

    // popular array fibonacci
    while (s != 61) {
        fib[s] = fib[s-2] + fib[s-1];
        s++;
    }

    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int k;
        scanf("%d", &k);
        printf("Fib(%d) = %llu\n", k, fib[k]);
    }
    
    return 0;
}
