#include <stdio.h>

int maximo(int *v, int n) {
    // caso base
    if (n == 1) return v[0];

    // caso recursivo
    int atual = v[n - 1];
    int restante = maximo(v, n - 1);

    return (atual > restante) ? atual : restante;
}

int main(void) {
    int v[] = { 3, 200, 1, 99, 9  };
    int n = sizeof(v) / sizeof(v[0]);

    int maior = maximo(v, n);
    printf("maior: %d\n", maior);

    return 0;
}
