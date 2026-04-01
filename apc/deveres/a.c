#include <stdio.h>

double coef_ang(double x0, double y0, double x1, double y1) {
    return (y1 - y0) / (x1 - x0);
}

int main(void) {
    double x0, y0, x1, y1;
    scanf("%lf %lf %lf %lf", &x0, &y0, &x1, &y1);

    double m = coef_ang(x0, y0, x1, y1);
    printf("%.2lf\n", m);
    
    return 0;
}
