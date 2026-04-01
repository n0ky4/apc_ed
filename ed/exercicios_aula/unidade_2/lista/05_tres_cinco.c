#include <stdio.h>

int main() {
    int n;
    printf("> ");
    scanf("%d", &n);

    int div = n % 3 == 0 && n % 5 == 0;
    printf("%s divisível por 3 e 5 simultaneamente.\n", div ? "É" : "Não é");

    return 0;
}
