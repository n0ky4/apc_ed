#include <stdio.h>
#include <stdlib.h>

int binomio(int n, int k) {
    if (k == 0 || k == n) return 1;
    return binomio(n - 1, k - 1) + binomio(n - 1, k);
}

int main(void) {
    printf("%d\n", binomio(5, 3));
    return 0;
}
