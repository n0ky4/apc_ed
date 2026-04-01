#include <stdio.h>

int main(void) {
    int a, b, c, P1, P2, P3;
    scanf("%d %d %d", &a, &b, &c);

    P1 = a;
    P2 = b;
    P3 = c;

    if (P1 > P2) {
        int t = P1;
        P1 = P2;
        P2 = t;
    }
    if (P1 > P3) {
        int t = P1;
        P1 = P3;
        P3 = t;
    }
    if (P2 > P3) {
        int t = P3;
        P3 = P2;
        P2 = t;
    }

    printf("%d\n%d\n%d\n\n", P1, P2, P3);
    printf("%d\n%d\n%d\n", a, b, c);

    return 0;
}
