#include <stdio.h>
#include <limits.h>

int d(int xa, int ya, int xb, int yb) {
    int a = (xa-xb);
    int b = (ya-yb);

    // não precisa de raiz quadrada pois não queremos a distância - apenas compará-las 
    return a*a + b*b; 
}

int main(void) {
    int c;

    // printf("Insira casos teste: ");
    scanf("%d", &c);

    for (int i = 0; i < c; i++) {
        int n;
        // printf("Insira n (bolas alem da branca): ");
        scanf("%d", &n);

        int bx, by;

        int mais_proxima = INT_MAX;
        int mais_proxima_indice = 0;

        // printf("Insira coord. branca: ");
        scanf("%d %d", &bx, &by);

        for (int j = 1; j <= n; j++) {
            int x, y;
            // printf("Insira coord. %d: ", j);
            scanf("%d %d", &x, &y);
            
            int dist = d(bx, by, x, y);

            if (dist < mais_proxima) {
                mais_proxima = dist;
                mais_proxima_indice = j;
            }
        }

        printf("%d\n", mais_proxima_indice);
    }

    return 0;
}
