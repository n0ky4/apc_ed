#include <stdio.h>
#include <stdlib.h>

int is_diag(int x1, int y1, int x2, int y2) {
    return abs(x1 - x2) == abs(y1 - y2);
}

int main(void) {
    while (1) {
        int x1, y1, x2, y2, m = 0;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        if (x1 == 0 && y1 == 0 && x2 == 0 && y2 == 0) break;

        if (x1 == x2 && y1 == y2) m = 0;
        else if (
            is_diag(x1, y1, x2, y2) ||
            x1 == x2 ||
            y1 == y2
        ) m = 1;
        else m = 2;

        printf("%d\n", m);
    }

    return 0;
}
