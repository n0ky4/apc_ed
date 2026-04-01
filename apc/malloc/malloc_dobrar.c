#include <stdio.h>
#include <stdlib.h>

#define INITIAL_SIZE 2

int main(void)
{
    size_t size = sizeof(int) * INITIAL_SIZE;

    int *arr = (int *)malloc(size);
    int n, len = 0;

    if (arr == NULL)
    {
        printf("Erro: não foi possível alocar a memória.\n");
        return 1;
    }

    do
    {
        printf("Digite um número (%d): ", len);

        scanf("%d", &n);
        arr[len] = n;
        len++;

        size = sizeof(int) * len * 2;
        arr = (int *)realloc(arr, size);

        if (arr == NULL)
        {
            printf("Erro: não foi possível realocar a memória.\n");
            return 1;
        }
    } while (n > 0);

    printf("Itens (%d): ", len);
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\nBytes alocados: %zu\n\n", size);

    free(arr);
    printf("Programa finalizado.\n");

    return 0;
}
