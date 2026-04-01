/*
 Estudo sobre alocação de memória.

 Este programa gera matrizes dinâmicas
 utilizando ponteiro de ponteiros (**)
    1. Ler m e n.
    2. Alocar uma matriz m x n dinamicamente.
    3. Preencher com valores.
    4. Imprimir em formato de tabela.
    5. Liberar a memória corretamente.
*/
#include <stdio.h>
#include <stdlib.h>

// função para imprimir a matriz
void imprimir_matriz(int **matriz, int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        int *linha = matriz[i];
        for (int j = 0; j < n; j++)
        {
            printf("%d ", linha[j]);
        }
        printf("\n");
    }
}

// Função para liberar os ponteiros de 0 - `final` da matriz principal
void liberar_ponteiros(int **matriz, int final)
{
    for (int i = 0; i < final; i++)
    {
        free(matriz[i]);
    }
}

int main(void)
{
    int m, n;

    // perguntar o tamanho da matriz ao usuário
    printf("Digite m (linhas) > ");
    scanf("%d", &m);

    printf("Digite n (colunas) > ");
    scanf("%d", &n);

    printf("m = %d\nn = %d\n", m, n);

    // alocar a matriz principal que irá armazenar
    // ponteiros para cada linha. seu tamanho é (int*) * m.
    int **matriz = (int **)malloc(sizeof(int *) * m);

    // checar se a matriz foi alocada com sucesso
    if (matriz == NULL)
    {
        printf("Erro: Não foi possível alocar a matriz!");
        return 1;
    }

    // para cada linha
    for (int i = 0; i < m; i++)
    {
        // ponteiro desta linha
        int *ptr = (int *)malloc(sizeof(int) * n);
        matriz[i] = ptr;

        if (ptr == NULL)
        {
            if (i != 0)
                liberar_ponteiros(matriz, i - 1);
            free(matriz);
            printf("Erro: Não foi possível alocar o ponteiro nº %d\n", i);
            return 1;
        }

        // para cada item da linha (colunas)
        for (int j = 0; j < n; j++)
        {
            ptr[j] =
                i % 2 ? (j % 2 ? 1 : 0) : (j % 2 ? 0 : 1);
        }
    }

    imprimir_matriz(matriz, m, n);

    // cleanup
    liberar_ponteiros(matriz, m);

    // [POR ÚLTIMO!]
    free(matriz);

    return 0;
}
