#include <stdio.h>

#define par(x) ((x) % 2 == 0)

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int x, y;
        scanf("%d %d", &x, &y);

        // trocar números se x > y
        if (x > y) { int tmp = x; x = y; y = tmp; }

        // definir x e y como primeiro e último ímpar respectivamente (exclusivo)
        if (par((int)x)) x++; else x += 2;
        if (par((int)y)) y--; else y -= 2;

        // checar se não há nenhum ímpar no intervalo
        if (x > y) { printf("0\n"); continue; }

        int t = ((y - x) / 2) + 1; // termos
        int s = t * (x + y) / 2; // soma (PA)

        printf("%d\n", s);
    }
    
    return 0;
}
