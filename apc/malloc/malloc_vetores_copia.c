/*
 Estudo sobre alocação de memória.

 Este programa é o mesmo que malloc_vetores.c,
 mas copia o vetor para um outro vetor.
*/

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define INT_SIZE (sizeof(int))
#define MAX_ARRAY_LENGTH (1000)

int main(void)
{
    // n       => tamanho do vetor (quantidade, length)
    // *ptr    => ponteiro do vetor
    // memsize => tamanho do vetor (memória, bytes)
    int n, *ptr;
    size_t memsize;

    // perguntar o valor de n
    printf("Digite a quantidade de números > ");
    scanf("%d", &n);

    // checar o tamanho de n
    if (n <= 0 || n > MAX_ARRAY_LENGTH)
    {
        printf("Erro: Tamanho do vetor inválido! Deve estar entre 1-%d\n", MAX_ARRAY_LENGTH);
        return 1;
    }

    // definir o tamanho do vetor (size_t)
    memsize = n * INT_SIZE;

    // alocar a memória do vetor
    ptr = (int *)malloc(memsize);

    // checar se o vetor não pôde ser alocado (pointer NULL)
    if (ptr == NULL)
    {
        printf("Erro: Não foi possível alocar a memória!");
        return 1;
    }

    // mostrar a memória alocada (%zu para size_t)
    printf("Memória alocada (n): %zu bytes\n", memsize);

    // perguntar os números e defini-los no
    for (int i = 0; i < n; i++)
    {
        printf("Digite o número %d > ", i);
        scanf("%d", &ptr[i]); // &ptr[i] => endereço do índice `i` do vetor
    }

    // inicializar segundo vetor
    printf("Inicializando segundo vetor...\n");
    int *ptr2 = (int *)malloc(memsize);

    if (ptr2 == NULL)
    {
        printf("Erro: Não foi possível alocar a memória do segundo vetor!");
        return 1;
    }

    // copiar elementos do primeiro vetor para o segundo
    for (int i = 0; i < n; i++)
    {
        ptr2[i] = ptr[i];
    }

    // imprimir primeiro vetor:
    printf("ptr (1): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", ptr[i]);
    }

    // imprimir segundo vetor:
    printf("\nptr (2): ");
    for (int i = 0; i < n; i++)
    {
        printf("%d, ", ptr2[i]);
    }

    // liberar memória
    free(ptr);
    free(ptr2);
    printf("\nMemória liberada dos dois vetores.\n");

    return 0;
}
