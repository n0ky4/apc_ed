#include <stdio.h>

int main(void) {
    int n, i = 0, o = 0;
    scanf("%d", &n);

    for (int j = 0; j < n; j++) {
        int tmp;
        scanf("%d", &tmp);

        if (tmp >= 10 && tmp <= 20) i++;
        else o++;
    }

    printf("%d in\n%d out\n", i, o);
    return 0;
}
