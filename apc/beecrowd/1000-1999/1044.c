#include <stdio.h>

int main(void) {
    int a, b;
    scanf("%d %d", &a, &b);

    if (a > b) {
        int t = b;
        b = a;
        a = t;
    }

    if (b % a == 0) printf("Sao Multiplos\n");
    else printf("Nao sao Multiplos\n");
    
    return 0;
}
