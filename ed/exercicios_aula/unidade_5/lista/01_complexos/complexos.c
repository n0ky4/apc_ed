#include "complexos.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPSILON 1e-6

void complexo_imprimir(Complexo x) {
    if (x.img < 0)
        printf("%lf - %lfi\n", x.real, -x.img);
    else
        printf("%lf + %lfi\n", x.real, x.img);
}   

int complexo_iguais(Complexo a, Complexo b) {
    return fabs(a.real - b.real) <= EPSILON &&
           fabs(a.img - b.img) <= EPSILON;
}

Complexo complexo_novo(double real, double img) {
    return (Complexo) {
        real,
        img
    };
}

Complexo complexo_soma(Complexo a, Complexo b) {
    return (Complexo) {
        a.real + b.real,
        a.img + b.img
    };
}

Complexo complexo_subtracao(Complexo a, Complexo b) {
    return (Complexo) {
        a.real - b.real,
        a.img - b.img
    };
}

Complexo complexo_multiplicacao(Complexo a, Complexo b) {
    return (Complexo) {
        a.real * b.real - a.img * b.img,
        a.real * b.img + a.img * b.real
    };
}

Complexo complexo_conjugado(Complexo x) {
    return (Complexo) {
        x.real,
        -x.img
    };
}

Complexo complexo_divisao(Complexo a, Complexo b) {
    if (b.real == 0.0 && b.img == 0.0) {
        fprintf(stderr, "Erro: divisao por zero em (%lf + %lfi)\n", b.real, b.img);
        exit(EXIT_FAILURE);
    }

    double denominador = b.real * b.real + b.img * b.img;
    return (Complexo) {
        (a.real * b.real + a.img * b.img) / denominador,
        (a.img * b.real - a.real * b.img) / denominador
    };
}

double complexo_modulo(Complexo x) {
    return sqrt(x.real * x.real + x.img * x.img);
}

Complexo complexo_potencia(Complexo x, int potencia) {
    if (x.img == 0 && x.real == 0) {
        if (potencia == 0) {
            fprintf(stderr, "Erro: 0^0 indefinido em (%lf + %lfi)\n", x.real, x.img);
            exit(EXIT_FAILURE);
        } else if (potencia < 0) {
            fprintf(stderr, "Erro: 0 elevado a potencia negativa em (%lf + %lfi)\n", x.real, x.img);
            exit(EXIT_FAILURE);
        }
    }
    
    double r = complexo_modulo(x);
    double theta = atan2(x.img, x.real);
    double rpow = pow(r, potencia);

    double real = rpow * (cos(potencia * theta));
    double img = rpow * (sin(potencia * theta));

    if (fabs(real) < EPSILON) real = 0;
    if (fabs(img) < EPSILON) img = 0;

    return (Complexo) {
        real,
        img
    };
}
