#include <stdio.h>

int main(void) {
    int k;
    int tops[7] = { 1, 3, 5, 10, 25, 50, 100 };
    
    scanf("%d", &k);
    
    for (int i = 0; i < 7; i++) {
        if (k <= tops[i]) {
            printf("Top %d\n", tops[i]);
            break;
        }
    }

    return 0;
}
