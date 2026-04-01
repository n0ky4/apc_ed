#include <stdio.h>

int main(void) {
    int d; 
    scanf("%d", &d);

    for (int i = 1; i <= d; i++) if (d % i == 0) printf("%d\n", i);

    return 0;
}
