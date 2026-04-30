#include <stdio.h>

int c = 0;
void hanoi(int n, char orig, char dest, char aux) {
    // caso base: n == 0 (não faz nada)
    if (n > 0) {
        hanoi(n - 1, orig, aux, dest);
        printf("move de %c para %c\n", orig, dest);
        c++;
        hanoi(n - 1, aux, dest, orig);
    }
}

int main(void) {
    hanoi(3, 'A', 'C', 'B');
    printf("movimentos: %d\n", c);
    return 0;
}
