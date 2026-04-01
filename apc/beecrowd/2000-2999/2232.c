#include <stdio.h>
#include <math.h>

int soma_linha(int i) {
    return (int)pow(2.0, (double)i);
}

int soma_triangulo(int n) {
    if (n == 1) return 1;
    return soma_linha(n - 1) + soma_triangulo(n - 1);
}

int main(void) {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int tmp;
        scanf("%d", &tmp);
        printf("%d\n", soma_triangulo(tmp));
    }
    
    return 0;
}
