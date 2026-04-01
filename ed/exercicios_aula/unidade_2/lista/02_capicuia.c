#include <stdio.h>

int main() {
    int n, original, invertido = 0;
    scanf("%d", &n);

    original = n;

    while (n > 0) {
        int digito = n % 10;
        invertido = invertido * 10 + digito;
        n /= 10;
    }

    printf("%s CAPICUIA.\n", invertido == original ? "É" : "NÃO É");

    return 0;
}
