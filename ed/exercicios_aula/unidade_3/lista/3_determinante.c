#include <stdio.h>

void ler_matriz(double A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf("Digite o número (%d, %d): ", i, j);
            scanf("%lf", &A[i][j]);
        }
    }
}

double calcular_determinante(double A[3][3]) {
    double a = A[0][0],
           b = A[1][0],
           c = A[2][0],
           d = A[0][1],
           e = A[1][1],
           f = A[2][1],
           g = A[0][2],
           h = A[1][2],
           i = A[2][2];
           
    double s1 = (a*e*i) + (b*f*g) + (c*d*h);
    double s2 = (c*e*g) + (a*f*h) + (b*d*i);
    
    return s1 - s2;
}

void imprimir_matriz(double A[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) 
            printf("%.1f ", A[i][j]);
        printf("\n");
    }
} 

int main(void) {
    double A[3][3];

    ler_matriz(A);
    double det = calcular_determinante(A);

    printf("\nMatriz:\n");
    imprimir_matriz(A);
    
    printf("\nDeterminante: %.2lf\n", det);

    return 0;
}
