#include <stdio.h>

int main(void) {
    int n, atual, escadinhas = 1;
    scanf("%d", &n);

    int x[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &x[i]);
    }

    atual = x[1] - x[0];

    for (int i = 1; i < (n-1); i++) {
        int diff = x[i+1] - x[i];
        if (diff != atual) {
            escadinhas++;
            atual = diff;
        }
    }

    printf("%d\n", escadinhas);

    return 0;
}
