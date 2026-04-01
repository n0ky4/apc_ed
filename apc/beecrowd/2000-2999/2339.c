#include <stdio.h>

int main(void) {
    int c, p, f;

    scanf("%d %d %d", &c, &p, &f);

    if (f*c > p) printf("N\n");
    else printf("S\n");

    return 0;
}
