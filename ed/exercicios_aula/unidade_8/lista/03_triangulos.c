#include <stdio.h>

void desenhar(int x) { printf("desenhar(%d)\n", x); }
void girar(int x) { printf("girar(%d)\n", x); }

void desenhar_lados(int n, int w) {
    if (n <= 0) return;

    girar(-60);
    desenhar(w);
    girar(120);
    desenhar(w);
    girar(-60);

    desenhar_lados(n - 1, w);
}

void desenhar_base(int n, int w) {
    if (n <= 0) return;

    desenhar(w);
    desenhar_base(n - 1, w);
}

void desenhar_triangulo(int n, int w) {
    if (n <= 0) return;

    desenhar_lados(n, w);

    girar(-180);
    desenhar_base(n, w);

    girar(120);
    desenhar(w);
    girar(60);

    desenhar_triangulo(n - 1, w);
}

int main(void) {
    printf("clearscreen rt 90 ");
    desenhar_triangulo(50, 6);

    return 0;
}
