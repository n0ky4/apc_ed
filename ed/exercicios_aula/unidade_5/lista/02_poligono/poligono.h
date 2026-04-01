#ifndef POLIGONO_H
#define POLIGONO_H

#define MAX_PONTOS 100

typedef struct {
    double x, y;
} Ponto;

typedef struct {
    int lados;
    Ponto pontos[MAX_PONTOS];
} Poligono;

void poligono_imprimir_pontos(Poligono p);
Poligono poligono_novo(int lados, Ponto pontos[]);
int poligono_e_simples(Poligono p);
double poligono_area(Poligono p);
Poligono poligono_trasladar(Poligono p, double tx, double ty);

#endif // POLIGONO_H
