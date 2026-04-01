#include "poligono.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#pragma region Utilitários
int orientacao(Ponto A, Ponto B, Ponto C) {
    double cross = (B.x - A.x) * (C.y - A.y) -
                   (B.y - A.y) * (C.x - A.x);
    if (cross > 0) return 1; // sentido horário
    if (cross < 0) return -1; // sentido anti-horário
    return 0; // colineares
}

int ponto_no_segmento(Ponto P, Ponto A, Ponto B) {
    return (
        P.x <= fmax(A.x, B.x) && P.x >= fmin(A.x, B.x) &&
        P.y <= fmax(A.y, B.y) && P.y >= fmin(A.y, B.y)
    );
}

int segmentos_se_cruzam(Ponto A, Ponto B, Ponto C, Ponto D) {
    int o1 = orientacao(A, B, C),
        o2 = orientacao(A, B, D),
        o3 = orientacao(C, D, A),
        o4 = orientacao(C, D, B);

    // pontos ficam em lados opostos:
    if (o1 != o2 && o3 != o4) return 1;

    // colineares e sobrepostos:
    if (o1 == 0 && ponto_no_segmento(C, A, B)) return 1;
    if (o2 == 0 && ponto_no_segmento(D, A, B)) return 1;
    if (o3 == 0 && ponto_no_segmento(A, C, D)) return 1;
    if (o4 == 0 && ponto_no_segmento(B, C, D)) return 1;

    return 0;
}
#pragma endregion

#pragma region Implementações

void poligono_imprimir_pontos(Poligono p) {
    for (int i = 0; i < p.lados; i++)
        printf("(%lf, %lf)\n", p.pontos[i].x, p.pontos[i].y);
}

Poligono poligono_novo(int lados, Ponto pontos[]) {
    if (lados > MAX_PONTOS) {
        fprintf(stderr, "Erro: O número de lados é maior que o tamanho máximo\n");
        exit(EXIT_FAILURE);
    }

    Poligono p;
    p.lados = lados;

    for (int i = 0; i < lados; i++)
        p.pontos[i] = pontos[i];

    return p;
}

int poligono_e_simples(Poligono p) {
    int n = p.lados;

    for (int i = 0; i < n; i++) {
        // Aresta i: do vértice i ao vértice (i+1)
        Ponto A = p.pontos[i];
        Ponto B = p.pontos[(i + 1) % n];

        for (int j = i + 2; j < n; j++) {
            // Pula o par adjacente (última aresta com a primeira)
            if (i == 0 && j == n - 1) continue;

            // Aresta j: do vértice j ao vértice (j+1)
            Ponto C = p.pontos[j];
            Ponto D = p.pontos[(j+1) % n];

            if (segmentos_se_cruzam(A, B, C, D))
                return 0; // Encontrou um cruzamento
        }
    }

    return 1; // Nenhum cruzamento - é simples
}


double poligono_area(Poligono p) {
    if (!poligono_e_simples(p)) {
        fprintf(stderr, "Erro: O poligono deve ser simples para calcular a area\n");
        exit(EXIT_FAILURE);
    }

    int n = p.lados;
    double soma = 0;
    for (int i = 0; i < n; i++) {
        int j = (i + 1) % n;
        double a = p.pontos[i].x * p.pontos[j].y;
        double b = p.pontos[i].y * p.pontos[j].x;
        soma += a - b;
    }

    return fabs(soma) / 2.0;
}

Poligono poligono_trasladar(Poligono p, double tx, double ty) {
    Poligono q = p;
    for (int i = 0; i < q.lados; i++)
        q.pontos[i] = (Ponto){ q.pontos[i].x + tx, q.pontos[i].y + ty };
    return q;
}
#pragma endregion
