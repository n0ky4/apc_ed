#include <stdio.h>

int main(void) {
    int n, cq = 0; // bandeijas, copos quebrados
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int l, c;
        scanf("%d %d", &l, &c);

        if (l > c) cq += c;
    }

    printf("%d\n", cq);
    
    return 0;
}
