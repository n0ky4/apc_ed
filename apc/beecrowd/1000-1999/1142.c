#include <stdio.h>

int main(void) {
    int n, c = 1;
    scanf("%d", &n);

    for (int i = 1; i <= n; i++) {
        printf("%d %d %d PUM\n", c, c+1, c+2);
        c += 4;
    }
    
    return 0;
}
