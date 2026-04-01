// Aproximação com retângulos da área da função f(x) no intervalo [0, 1] 
#include <stdio.h>
#include <math.h>

double f(double x) {
    return sin(x);
}

int main(void) {
    int n;
    printf("Digite a quantidade de retângulos: ");
    scanf("%d", &n);

    double somatorio = 0;
    double deltax = 1.0 / n; // base

    printf("Δx = %.4lf\n", deltax);

    for (int k = 1; k <= n; k++) {
        double altura = f((double)k / n); // extremo direito onde x = k/n
        double area = deltax * altura;
        printf("[RET %d] Altura : %.4lf , Área : %.4lf\n", k, altura, area);
        somatorio += area;
    }

    printf("Área aproximada: %.4lf\n", somatorio);
    
    return 0;
}
