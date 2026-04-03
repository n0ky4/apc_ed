#ifndef MATRIZ_H
#define MATRIZ_H

#define MATRIZ_MAX 100

typedef struct {
    int linhas, colunas;
    double dados[MATRIZ_MAX][MATRIZ_MAX];
} Matriz;

int matriz_mesmo_tamanho(Matriz a, Matriz b);
int matriz_iguais(Matriz a, Matriz b);
void matriz_imprimir(Matriz a);
Matriz matriz_criar(int linhas, int colunas);
Matriz matriz_criar_nula(int linhas, int colunas);
Matriz matriz_soma(Matriz a, Matriz b);
Matriz matriz_subtracao(Matriz a, Matriz b);
Matriz matriz_multiplicacao(Matriz a, Matriz b);
Matriz matriz_escalar(Matriz a, double escalar);
Matriz matriz_transposta(Matriz a);

#endif // MATRIZ_H
