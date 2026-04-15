#include <stdio.h>
#include <stdlib.h>

void f(int *a, int *b) {
    int c = *a; // c = valor de a
    *a = *b;    // valor de a = valor de b 
    *b = c;     // valor de b = c
}

void g(int **c, int n) {
    *c = malloc(sizeof(int) * n); // modificar o ponteiro c
}

void h(int *h) {
    *h = 100;
}

int main() {
    int a = 1, b = 2, c= 3;
    int **d;

    d = malloc(sizeof(int*));
    if (d == NULL) { // Checar se a memória foi alocada antes de usá-la
        printf("Erro: Não foi possível alocar memória.\n");
        return 1;
    }

    f(&a, &b);
    g(d, 1);

    h(*d);
    
    printf("%d, %d, %d", a, c, d[0][0]);

    free(*d); // liberar int* de d
    free(d);  // liberar d

    return 0;
}
