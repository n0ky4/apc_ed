#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

int matriz_mesmo_tamanho(Matriz a, Matriz b) {
    return (a.linhas == b.linhas && a.colunas == b.colunas);
}

int matriz_iguais(Matriz a, Matriz b) {
    if (!matriz_mesmo_tamanho(a, b)) return 0;
    for (int i = 0; i < a.linhas; i++)
        for (int j = 0; j < a.colunas; j++)
            if (a.dados[i][j] != b.dados[i][j]) return 0;
    return 1;
}

void matriz_imprimir(Matriz a) {
    for (int i = 0; i < a.linhas; i++) {
        for (int j = 0; j < a.colunas; j++)
            printf("%5.2f ", a.dados[i][j]);
        printf("\n");
    }
}

Matriz matriz_criar(int linhas, int colunas) {
    if (linhas > MATRIZ_MAX || colunas > MATRIZ_MAX) {
        fprintf(stderr, "Erro: O número de linhas ou colunas ultrapassou o tamanho máximo.\n");
        exit(EXIT_FAILURE);
    }
    Matriz a;
    a.linhas = linhas;
    a.colunas = colunas;
    return a;
}

Matriz matriz_criar_nula(int linhas, int colunas) {
    Matriz a = matriz_criar(linhas, colunas);

    for (int i = 0; i < linhas; i++)
        for (int j = 0; j < colunas; j++)
            a.dados[i][j] = 0;

    return a;
}

Matriz matriz_soma(Matriz a, Matriz b) {
    if (!matriz_mesmo_tamanho(a, b)) {
        fprintf(stderr, "Erro: Não é possível somar matrizes de tamanhos diferentes.\n");
        exit(EXIT_FAILURE);
    }

    Matriz s = matriz_criar(a.linhas, a.colunas);

    for (int i = 0; i < a.linhas; i++)
        for (int j = 0; j < a.colunas; j++)
            s.dados[i][j] = a.dados[i][j] + b.dados[i][j];

    return s;
}

Matriz matriz_subtracao(Matriz a, Matriz b) {
    if (!matriz_mesmo_tamanho(a, b)) {
        fprintf(stderr, "Erro: Não é possível somar matrizes de tamanhos diferentes.\n");
        exit(EXIT_FAILURE);
    }

    Matriz s = matriz_criar(a.linhas, a.colunas);

    for (int i = 0; i < a.linhas; i++)
        for (int j = 0; j < a.colunas; j++)
            s.dados[i][j] = a.dados[i][j] - b.dados[i][j];

    return s;
}

Matriz matriz_multiplicacao(Matriz a, Matriz b) {
    if (a.colunas != b.linhas) {
        fprintf(stderr, "Erro: O número de linhas de B deve ser igual ao número de colunas de A.\n");
        exit(EXIT_FAILURE);
    }

    Matriz s = matriz_criar_nula(a.linhas, b.colunas);

    for (int i = 0; i < a.linhas; i++)
        for (int j = 0; j < b.colunas; j++)
            for (int k = 0; k < a.colunas; k++)
                s.dados[i][j] += a.dados[i][k] * b.dados[k][j];

    return s;
}

Matriz matriz_escalar(Matriz a, double escalar) {
    Matriz s = matriz_criar(a.linhas, a.colunas);
    
    for (int i = 0; i < a.linhas; i++)
        for (int j = 0; j < a.colunas; j++)
            s.dados[i][j] = escalar * a.dados[i][j];
            
    return s;
}

Matriz matriz_transposta(Matriz a) {
    Matriz t = matriz_criar(a.colunas, a.linhas);

    for (int i = 0; i < a.linhas; i++)
        for (int j = 0; j < a.colunas; j++)
            t.dados[j][i] = a.dados[i][j];

    return t;
}
