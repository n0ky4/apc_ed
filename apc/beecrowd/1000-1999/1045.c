#include <stdio.h>

int main(void) {
    float a, b, c, tmp, a_sqr, sum_sqr;
    scanf("%f %f %f", &a, &b, &c);

    // ordenar
    if (b > a) {
        tmp = a;
        a = b;
        b = tmp;
    }
    if (c > a) {
        tmp = a;
        a = c;
        c = tmp;
    }
    if (c > b) {
        tmp = b;
        b = c;
        c = tmp;
    }

    a_sqr = a*a;
    sum_sqr = b*b + c*c;

    if (a >= (b+c)) {
        printf("NAO FORMA TRIANGULO\n");
        return 0;
    }

    if (a_sqr == sum_sqr) {
        printf("TRIANGULO RETANGULO\n");
    }

    if (a_sqr > sum_sqr) {
        printf("TRIANGULO OBTUSANGULO\n");
    }

    if (a_sqr < sum_sqr) {
        printf("TRIANGULO ACUTANGULO\n");
    }

    if (a == b && b == c) {
        printf("TRIANGULO EQUILATERO\n");
    } else if (a == b || a == c || b == c) {
        printf("TRIANGULO ISOSCELES\n");
    }

    return 0;
}
