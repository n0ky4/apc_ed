#include <stdio.h>
#include <stdlib.h>

void f(int a, int b) {
    int c = a;
    a = b;
    b = c;
}

void g(int *c, int n) {
    c = malloc(sizeof(int) * n);
}

void h(int *h) {
    printf("Endereço: %p\n", h);
    *h = 100;
}

int main() {
    int a = 1, b = 2, c= 3;
    int **d;

    d = malloc(sizeof(int*));
    f(a, b);
    g(d[0], 1);

    printf("SEGFAULT HERE?\n"); h(*d); printf("NOPE.\n");
    free(d);

    printf("%d, %d, %d", a, c, d[1][1]);
    return 0;
}
