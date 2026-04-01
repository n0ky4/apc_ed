#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        float a, b, c;
        scanf("%f %f %f", &a, &b, &c);
        printf("%.1f\n", (2*a+3*b+5*c)/10.0);
    }

    return 0;
}
