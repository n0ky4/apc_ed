#include <stdio.h>
#include <assert.h>
#include <math.h>

int eq(double a, double b) {
    return fabs(a - b) <= 1e-9;
}

double potencia(double x, int n) {
	if (n == 0) return 1.0;
	double metade = potencia(x, n / 2);
	if (n % 2 == 0) return metade * metade;
	else return x * metade * metade;
}

double potencia_it(double x, int n) {
	double res = 1.0;
	while (n > 0) {
		if (n % 2 != 0) res *= x;
		x *= x;
		n /= 2;
	}
	return res;
}

int main(void) {
    double a = 5;
    int b = 11;

    printf("%lf %lf", potencia(a, b), potencia_it(a, b));
    assert(eq(potencia(a, b), potencia_it(a, b)));

    return 0;
}
