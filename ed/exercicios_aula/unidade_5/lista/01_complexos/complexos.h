#ifndef COMPLEXOS_H
#define COMPLEXOS_H

typedef struct {
    double real, img;
} Complexo;

void complexo_imprimir(Complexo x);
int complexo_iguais(Complexo a, Complexo b);
double complexo_modulo(Complexo x);

Complexo complexo_novo(double real, double img);
Complexo complexo_soma(Complexo a, Complexo b);
Complexo complexo_subtracao(Complexo a, Complexo b);
Complexo complexo_multiplicacao(Complexo a, Complexo b);
Complexo complexo_conjugado(Complexo x);
Complexo complexo_divisao(Complexo a, Complexo b);
Complexo complexo_potencia(Complexo x, int potencia);

#endif // COMPLEXOS_H
