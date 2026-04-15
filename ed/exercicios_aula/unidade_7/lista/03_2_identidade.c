#include <stdio.h>
#include <stdlib.h>

#define ERRO_ALOCACAO                                       \
    do {                                                    \
        printf("Erro: Não foi possível alocar memória.\n"); \
        exit(EXIT_FAILURE);                                 \
    } while (0)

typedef struct {
    int m, n;
    double** data;
} Matriz;

// Cria uma matriz m * n
Matriz *matriz_criar(int m, int n) {
    Matriz *A = malloc(sizeof(Matriz));
    if (A == NULL) ERRO_ALOCACAO;
        
    A->m = m;
    A->n = n;

    A->data = malloc(sizeof(double*) * m);
    if (A->data == NULL) ERRO_ALOCACAO;

    for (int i = 0; i < m; i++) {
        A->data[i] = malloc(sizeof(double) * n);
        if (A->data[i] == NULL) ERRO_ALOCACAO;
    }

    return A;
}

// Libera a memória de uma matriz alocada
void liberar_matriz(Matriz **A) {
    for (int i = 0; i < (*A)->m; i++)
        free((*A)->data[i]);
    free((*A)->data);
    free(*A);
    *A = NULL;
}

// Multiplica a matriz A pela matriz B
Matriz *matriz_multiplicar(Matriz *A, Matriz *B) {
    int m = A->m;
    int n = A->n;
    int p = B->n;

    if (B->m != n) {
        printf("Erro: O número de colunas da Matriz A deve ser igual ao número de linhas da Matriz B.\n");
        exit(EXIT_FAILURE);
    }

    Matriz *C = matriz_criar(m, p);

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            C->data[i][j] = 0;
            for (int k = 0; k < n; k++)
                C->data[i][j] += A->data[i][k] * B->data[k][j];
        }
    }

    return C;
}

// Cria uma matriz identidade de ordem n
Matriz *matriz_identidade(int n) {
    Matriz *A = matriz_criar(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) 
            A->data[i][j] = (i == j) ? 1 : 0;
    return A;
}

// Cria uma matriz identidade com as linhas i e j permutadas (Matriz P)
Matriz *matriz_criar_p(int m, int i, int j) {
    // 1. Criar matriz Identidade
    Matriz *P = matriz_identidade(m);

    // 2. P = Matriz Identidade com linhas i e j trocadas
    for (int k = 0; k < m; k++) {
        double tmp = P->data[i][k];
        P->data[i][k] = P->data[j][k];
        P->data[j][k] = tmp;
    }
    
    return P;
}

// Imprime uma matriz A
void imprimir_matriz(Matriz *A) {
    for (int i = 0; i < A->m; i++) {
        printf("[ ");
        for (int j = 0; j < A->n; j++)
            printf("%3.2lf ", A->data[i][j]);
        printf(" ]\n");
    }
}

int main(void) {
    Matriz *A = matriz_criar(3, 3);
    A->data[0][0] = 1; A->data[0][1] = 2; A->data[0][2] = 3;
    A->data[1][0] = 4; A->data[1][1] = 5; A->data[1][2] = 6;
    A->data[2][0] = 7; A->data[2][1] = 8; A->data[2][2] = 9;

    printf("Matriz A:\n");
    imprimir_matriz(A);

    printf("\nMatriz P (permutando linhas 0 e 1):\n");
    Matriz *P = matriz_criar_p(A->m, 0, 1);
    imprimir_matriz(P);

    printf("\nMatriz P × A:\n");
    Matriz *PA = matriz_multiplicar(P, A);
    imprimir_matriz(PA);

    liberar_matriz(&A);
    liberar_matriz(&P);
    liberar_matriz(&PA);

    return 0;
}
