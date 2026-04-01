#include <stdio.h>
#include "complexos.h"

int main() {
    Complexo a = complexo_novo(3.0, 4.0);
    Complexo b = complexo_novo(1.0, -2.0);

    printf("a = "); complexo_imprimir(a);
    printf("b = "); complexo_imprimir(b);
    printf("\n");

    printf("Módulo de a: %.2f\n", complexo_modulo(a));
    printf("Conjugado de a: "); complexo_imprimir(complexo_conjugado(a));
    printf("\n");

    printf("a + b = "); complexo_imprimir(complexo_soma(a, b));
    printf("a - b = "); complexo_imprimir(complexo_subtracao(a, b));
    printf("a * b = "); complexo_imprimir(complexo_multiplicacao(a, b));
    printf("a / b = "); complexo_imprimir(complexo_divisao(a, b));
    printf("a ^ 3 = "); complexo_imprimir(complexo_potencia(a, 3));
    printf("\n");
    
    printf("a == b? %s\n", complexo_iguais(a, b) ? "Sim" : "Não");
    printf("a == a? %s\n", complexo_iguais(a, a) ? "Sim" : "Não");

    return 0;
}
