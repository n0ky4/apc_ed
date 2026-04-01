#include <stdio.h>

int main(void) {
    int d, p = 0;
    scanf("%d", &d);

    if (d <= 800) p++;
    else if (d <= 1400) p+= 2;
    else if (d <= 2000) p += 3;

    printf("%d\n", p);

    return 0;
}
