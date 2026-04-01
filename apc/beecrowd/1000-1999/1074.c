#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (tmp == 0) {
            printf("NULL\n");
            continue;
        }

        if (tmp % 2 == 0) printf("EVEN ");
        else printf("ODD ");

        if (tmp < 0) printf("NEGATIVE\n");
        else printf("POSITIVE\n");
    }

    return 0;
}
