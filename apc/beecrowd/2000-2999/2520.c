#include <stdio.h>

#define abs(x) ((x) > 0 ? (x) : -(x))

int main(void) {
    int m, n;

    while (scanf("%d %d", &m, &n) != EOF) {
        int ax, ay, bx, by;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp;
                scanf("%d", &tmp);

                if (tmp == 2) {
                    ax = i;
                    ay = j;
                }
                
                if (tmp == 1) {
                    bx = i;
                    by = j;
                }
            }
        }

        int segundos = abs(bx - ax) + abs(by - ay);
        printf("%d\n", segundos);
    }

    return 0;
}
