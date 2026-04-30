#include <stdio.h>

void girar(int deg) { printf("girar(%d)\n", deg); }
void desenhar(double px) { printf("desenhar(%lf)\n", px); }

void koch(int l, double w) {
    // caso base
    if (l == 0) {
        desenhar(w);
        return;
    }

    // caso recursivo
    koch(l - 1, w / 3);
    girar(-60);
    koch(l - 1, w / 3);
    girar(120);
    koch(l - 1, w / 3);
    girar(-60);
    koch(l - 1, w / 3);
}

int main(void) {
    koch(8, 600);
    return 0;
}
