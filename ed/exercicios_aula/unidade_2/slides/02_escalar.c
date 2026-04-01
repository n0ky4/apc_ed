#include <stdio.h>
#include <stdlib.h>

#define MAX_NUMBERS 100
#define ERRO_ENTRADA -1

/**
 * @brief Pergunta ao usuário `n` inteiros e os armazena em `vetor`
 * @param caractere Caractere que representa o vetor (ex: u, v...)
 * @param n Quantidade de elementos a serem perguntados
 * @param vetor Vetor a ser preenchido
 * @note Retorna ERRO_ENTRADA caso haja erros
 */
int obter_numeros_vetor(const char caractere, const int n, int *vetor) {
    for (int i = 0; i < n; i++) {
        printf("[vetor %c] Digite o número %d: ", caractere, i + 1);
        if (scanf("%d", &vetor[i]) != 1) return ERRO_ENTRADA;
    }
    return 0;
}

/**
 * @brief Calcula e retorna o Produto Escalar dos vetores `u` e `v`
 * @param n Quantidade de elementos
 * @param u Vetor u
 * @param v Vetor v
 */
int calcular_produto_escalar(const int n, const int *u, const int *v) {
    int escalar = 0;
    for (int i = 0; i < n; i++) 
        escalar += u[i] * v[i];
    return escalar;
}

/**
 * @brief Pergunta e checa a quantidade de elementos do vetor
 * @return Inteiro representando a quantidade de elementos
 * @note Retorna ERRO_ENTRADA caso haja erros
 */
int perguntar_n() {
    int n;
    printf("Digite a quantidade de números dos vetores (n): ");
    
    if (scanf("%d", &n) != 1) {
        printf("Erro: Entrada inválida.\n");
        return ERRO_ENTRADA;
    }

    if (n <= 0 || n > MAX_NUMBERS) {
        printf("Erro: A quantidade de números deve estar entre 1 e %d.\n", MAX_NUMBERS);
        return ERRO_ENTRADA;
    }

    return n;
}

/**
 * @brief Imprime os elementos de um vetor com título
 * @param titulo Título/nome do vetor
 * @param vetor Vetor
 * @param n Quantidade de elementos do vetor
 */
void imprimir_vetor(const char* titulo, const int n, const int* vetor) {
    printf("%s = [", titulo);
    for (int i = 0; i < n; i++) 
        printf("%d%s", vetor[i], i == n-1 ? "" : ", ");
    printf("]\n");
}

/**
 * @brief Libera memória de 2 vetores especificados
 * @param a Vetor 1
 * @param b Vetor 2
 */
void liberar_memoria(int *a, int *b) {
    free(a);
    free(b);
}

int main() {
    // Perguntar e checar N
    int n = perguntar_n();
    if (n == ERRO_ENTRADA) return 1;

    // Alocar vetores u e v
    int *u = malloc(n * sizeof(int));
    int *v = malloc(n * sizeof(int));

    if (u == NULL || v == NULL) {
        liberar_memoria(u, v);
        printf("Erro: Não foi possível alocar memória.\n");
        return 1;
    }

    // Perguntar números do vetor u 
    if (obter_numeros_vetor('u', n, u) == ERRO_ENTRADA) {
        liberar_memoria(u, v);
        printf("Erro: Entrada inválida.\n");
        return 1;
    }
    // Perguntar números do vetor v
    if (obter_numeros_vetor('v', n, v) == ERRO_ENTRADA) {
        liberar_memoria(u, v);
        printf("Erro: Entrada inválida.\n");
        return 1;
    }

    // Calcular Produto de Hadamard
    int escalar = calcular_produto_escalar(n, u, v);
    printf("Produto Escalar = %d\n", escalar);

    // Liberar memória
    liberar_memoria(u, v);

    return 0;
}
