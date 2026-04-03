#include "tinta.h"
#include <stdio.h>
#include <math.h>

/* Utilitários e Macros */
#define COR_PRETO ((Cor){1.0, 1.0, 1.0})
#define COR_BRANCO ((Cor){0.0, 0.0, 0.0})
#define EPS 1e-6

int igual(double a, double b) {
    return fabs(a - b) <= EPS;
}

double clamp(double x, double min, double max) {
    return fmin(max, fmax(min, x));
}

/* Implementações */
void cor_imprimir(Cor c) {
    printf("(%lf, %lf, %lf)", c.az, c.ve, c.am);
}

int cor_sao_iguais(Cor a, Cor b) {
    return (
        igual(a.az, b.az) &&
        igual(a.ve, b.ve) &&
        igual(a.am, b.am)
    );
}

int cor_e_preto(Cor c) {
    return cor_sao_iguais(c, COR_PRETO);
}

int cor_e_branco(Cor c) {
    return cor_sao_iguais(c, COR_BRANCO);
}

Cor cor_criar(double az, double ve, double am) {
    return (Cor) {
        clamp(az, 0.0, 1.0),
        clamp(ve, 0.0, 1.0),
        clamp(am, 0.0, 1.0)
    };
}

Cor cor_misturar(Cor a, Cor b) {
    // se uma das cores forem pretas
    if (cor_e_preto(a) || cor_e_preto(b))
        return COR_PRETO;

    // se a ou b forem brancas, retornar a outra cor
    if (cor_e_branco(a)) return b;
    if (cor_e_branco(b)) return a;

    // misturar cor normalmente
    double az = (a.az + b.az) * 0.5,
           ve = (a.ve + b.ve) * 0.5,
           am = (a.am + b.am) * 0.5;
    return cor_criar(az, ve, am);
}
