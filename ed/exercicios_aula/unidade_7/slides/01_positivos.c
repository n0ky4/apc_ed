#include <stdio.h>
#include <stdlib.h>

int *positivos(int* v, int n, int* tam) {
    int *k = malloc(sizeof(int) * n);
    *tam = 0;
    for (int i = 0; i < n; i++)
        if (v[i] >= 0) k[(*tam)++] = v[i];
    if (*tam == 0) return NULL;
    if (*tam != n)
        k = realloc(k, sizeof(int) * (*tam));
    return k;
}

int main(void) {
    int v[] = { -4, -3, -2, -1, 0, 1, 2, 3, 4, 5 };
    int tam = 0;
    int *pos = positivos(v, 10, &tam);

    printf("Positivos: ");
    for (int i = 0; i < tam; i++)
        printf("%d ", pos[i]);
    printf("\n");

    free(pos);
}
