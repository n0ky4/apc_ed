#include <stdio.h>

int main(void) {
    int teste = 1;
    while (1) {
        int n, res;

        scanf(" %d", &n);
        
        if (n == 0) break;
        printf("Teste %d\n", teste);

        for (int i = 1; i <= n; i++) {
            int tmp;
            scanf(" %d", &tmp);
            if (tmp == i) res = i;
        }

        printf("%d\n\n", res);

        teste++;
    }

    return 0;
}
