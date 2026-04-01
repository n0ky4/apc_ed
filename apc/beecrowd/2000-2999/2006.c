#include <stdio.h>

int main(void) {
    int x, n[5], c = 0;

    scanf("%d", &x);
    scanf("%d %d %d %d %d", &n[0], &n[1], &n[2], &n[3], &n[4]);

    for (int i = 0; i < 5; i++) if (n[i] == x) c++;

    printf("%d\n", c);

    return 0;
}
