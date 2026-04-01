#include <stdio.h>

int main(void) {
    float x, y;
    scanf("%f %f", &x, &y);

    if (x == 0 && y == 0) {
        printf("Origem\n");
        return 0;
    }

    if (x == 0) {
        printf("Eixo Y\n");
    }
    if (y == 0) {
        printf("Eixo X\n");
    }
    
    if (x > 0 && y > 0) {
        printf("Q1\n");
        return 0;
    }

    if (x < 0 && y > 0) {
        printf("Q2\n");
        return 0;
    }

    if (x < 0 && y > 0) {
        printf("Q1\n");
        return 0;
    }

    if (x < 0 && y < 0) {
        printf("Q3\n");
        return 0;
    }

    if (x > 0 && y < 0) {
        printf("Q4\n");
        return 0;
    }

    return 0;
}
