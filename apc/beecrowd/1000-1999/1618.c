#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int ax, ay, bx, by, cx, cy, dx, dy, x, y;

        scanf(
            "%d %d %d %d %d %d %d %d %d %d",
            &ax, &ay, &bx, &by, &cx, &cy, &dx, &dy, &x, &y
        );

        if (
            x >= ax &&
            y >= ay &&
            x <= bx &&
            y >= by &&
            x >= dx &&
            y <= dy &&
            x <= cx &&
            y <= cy
        ) printf("1\n");
        else printf("0\n");
    }
    
    return 0;
}
