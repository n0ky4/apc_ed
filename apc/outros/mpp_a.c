#include <stdio.h>

int main(void) {
    int w, a, b, c;
    scanf("%d %d %d %d", &w, &a, &b, &c);

    if (a+b+c <= w) printf("S\n");
    else printf("N\n");
    
    return 0;
}
