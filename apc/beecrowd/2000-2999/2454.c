#include <stdio.h>

int main(void) {
    char p, r;
    scanf("%c %c", &p, &r);

    if (p == '0') {
        printf("C\n");
        return 0;
    }

    if (p == '1' && r == '0') {
        printf("B\n");
        return 0;
    }

    if (p == '1' && r == '1') {
        printf("A\n");
        return 0;
    }

    return 0;
}
