/*
 Estudo sobre alocação de memória.

 Este programa pergunta ao usuário a quantidade de
 números inteiros que ele deseja inserir em um vetor.
 O programa aloca a quantidade necessária de bytes para
 armazenar esses números, e os pergunta em seguida.
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

    // mostrar todos os valores do vetor
    for (int i = 0; i < n; i++)
    {
        printf("ptr[%d] = %d\n", i, ptr[i]);
    }

    // liberar memória
    free(ptr);
    printf("Memória liberada.\n");

    return 0;
}
