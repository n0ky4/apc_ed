#include <stdio.h>

int main(void) {
    while (1) {
        int d;
        scanf("%d", &d);

        if (d == 0) break;
        for (int i = 1; i < d; i++) printf("%d ", i);

        printf("%d\n", d);
    }
    
    return 0;
}
