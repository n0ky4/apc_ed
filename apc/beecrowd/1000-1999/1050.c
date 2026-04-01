#include <stdio.h>

// solução usando array -> complexidade O(1)
int main(void) {
    int n;
    char *ddd[72] = { NULL };

    ddd[61] = "Brasilia";
    ddd[71] = "Salvador";
    ddd[11] = "Sao Paulo";
    ddd[21] = "Rio de Janeiro";
    ddd[32] = "Juiz de Fora";
    ddd[19] = "Campinas";
    ddd[27] = "Vitoria";
    ddd[31] = "Belo Horizonte";

    scanf("%d", &n);

    if (n <= 71 && ddd[n] != NULL) {
        printf("%s\n", ddd[n]);
        return 0;
    }

    printf("DDD nao cadastrado\n");
    return 0;
}
