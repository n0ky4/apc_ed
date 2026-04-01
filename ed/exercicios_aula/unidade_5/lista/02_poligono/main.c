#include <stdio.h>
#include "poligono.h"

int main(void) {
    Ponto pontos_quadrado[4] = {
        (Ponto){0, 0},
        (Ponto){1, 0},
        (Ponto){1, 1},
        (Ponto){0, 1},
    };
    Poligono quadrado = poligono_novo(4, pontos_quadrado);

    Ponto pontos_triangulo[3] = {
        (Ponto){0, 0},
        (Ponto){2, 2},
        (Ponto){-2, 2},
    };
    Poligono triangulo = poligono_novo(3, pontos_triangulo);

    Ponto pontos_ampulheta[4] = {
        (Ponto){0, 0},
        (Ponto){1, 1},
        (Ponto){1, 0},
        (Ponto){0, 1},
    };
    Poligono ampulheta = poligono_novo(4, pontos_ampulheta);

    printf("Quadrado é simples? %s\n", poligono_e_simples(quadrado) ? "SIM" : "NÃO");
    printf("Triângulo é simples? %s\n", poligono_e_simples(triangulo) ? "SIM" : "NÃO");
    printf("Ampulheta é simples? %s\n\n", poligono_e_simples(ampulheta) ? "SIM" : "NÃO");
    
    printf("Área do quadrado: %lf\n", poligono_area(quadrado));
    printf("Área do triângulo: %lf\n", poligono_area(triangulo));
    // Área da ampulheta não calculada pois não é um polígono simples - causa crash

    printf("\nQuadrado antes da translação:\n");
    poligono_imprimir_pontos(quadrado);
    printf("\n");

    printf("Quadrado após translação (-4, 2):\n");
    quadrado = poligono_trasladar(quadrado, -4, 2);
    poligono_imprimir_pontos(quadrado);
    printf("\n");

    return 0;
}
