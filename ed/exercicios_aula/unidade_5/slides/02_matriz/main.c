#include <stdio.h>
#include "matriz.h"

void imprimir(const char *label, Matriz m) {
    printf("%s:\n", label);
    matriz_imprimir(m);
}

int main(void) {
    Matriz a = matriz_criar(2, 2);
    a.dados[0][0] = 1; a.dados[0][1] = 2;
    a.dados[1][0] = 3; a.dados[1][1] = 4;

    Matriz b = matriz_criar(2, 2);
    b.dados[0][0] = 5; b.dados[0][1] = 6;
    b.dados[1][0] = 7; b.dados[1][1] = 8;

    Matriz nula = matriz_criar_nula(2, 2);

    imprimir("A", a);
    imprimir("B", b);
    imprimir("Nula 2x2", nula);

    printf("A e B têm mesmo tamanho? %s\n", matriz_mesmo_tamanho(a, b) ? "SIM" : "NÃO");
    printf("A e B são iguais? %s\n", matriz_iguais(a, b) ? "SIM" : "NÃO");
    printf("A e A são iguais? %s\n\n", matriz_iguais(a, a) ? "SIM" : "NÃO");

    Matriz soma = matriz_soma(a, b);
    Matriz sub = matriz_subtracao(b, a);
    Matriz prod = matriz_multiplicacao(a, b);
    Matriz esc = matriz_escalar(a, 3.0);

    imprimir("A + B", soma);
    imprimir("B - A", sub);
    imprimir("A * B", prod);
    imprimir("A * 3.0", esc);

    Matriz c = matriz_criar(2, 3);
    c.dados[0][0] = 1; c.dados[0][1] = 2; c.dados[0][2] = 3;
    c.dados[1][0] = 4; c.dados[1][1] = 5; c.dados[1][2] = 6;

    Matriz ct = matriz_transposta(c);

    imprimir("C (2x3)", c);
    imprimir("C transposta (3x2)", ct);

    return 0;
}
