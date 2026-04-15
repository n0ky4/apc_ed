#include <stdio.h>
#include <stdlib.h>

double* aloca_zera(int n) {
    double* v = malloc(n * sizeof(double));
    for (int i = 0; i < n; i++)
        v[i] = 0.0;
    return v;
}

void print_vec(int n, double* v) {
    printf("[INÍCIO] ");
    for (int i = 0; i < n; i++)
        printf("%.2lf (%d)%s", v[i], i, (i == n - 1) ? " [FIM]" : ", ");
    printf("\n");
}

int main(void) {
    int n = 10;
    double* v = aloca_zera(n);
    print_vec(n, v);

    // liberar memória
    free(v);

    return 0;
}
