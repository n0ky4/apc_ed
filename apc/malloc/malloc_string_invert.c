/*
 Estudo sobre alocação de memória.

 Este programa pega uma string de
 tamanho arbitrário e a inverte.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int realloc_err(void *ptr)
{
    printf("Erro de alocação!");
    free(ptr);
    return 1;
}

int main(void)
{
    // *str  => ponteiro para a string inicial
    // *temp => ponteiro temporário para realocação e inversão (para a string final)
    // len   => tamanho de caracteres da string (aumenta dinamicamente)
    // ch    => char para iteração dos caracteres até formar a string inicial
    char *str = NULL, *temp = NULL;
    int len = 0;
    char ch;

    printf("Digite um texto > ");

    // para cada caractere no buffer (até que seja \n ou EOF)
    // (seta `ch` pelo último caractere no buffer)
    while ((ch = getchar()) != '\n' && ch != EOF)
    {
        // realocar o ponteiro `str` para len + 1
        // [como len é 0, len + 1 = 1, então alocamos +1 a cada caractere]
        // usamos `temp` para checar se a realocação foi bem sucedida.
        temp = realloc(str, len + 1);

        if (!temp)
        {
            // aqui damos free em str -- e não em temp -- porque a realocação
            // falhou. consequentemente, não haveria sentido em dar free numa
            // realocação que nem mesmo ocorreu.
            return realloc_err(str);
        }

        // a realocação foi bem sucedida, transformar str em temp.
        str = temp;

        // escrever o caractere em str
        str[len] = ch;

        // aumentar o tamanho
        len++;
    }

    // realocar str para +1 caractere (\0, fim de string)
    temp = realloc(str, len + 1);

    // novamente, checar se a realocação foi bem sucedida.
    if (!temp)
        return realloc_err(str);

    // realocação bem sucedida, transformar str em temp e adicionar o \0.
    str = temp;
    str[len] = '\0';

    // inicializar vetor final, que armazenará a string invertida.
    // tamanho len + 1 para, novamente, acrescentar o \0 no final.
    temp = (char *)malloc(len + 1);
    if (!temp)
    {
        printf("Erro de alocação do array final.");
        return 1;
    }

    // para cada letra
    for (int i = 0; i < len; i++)
    {
        temp[i] = str[(len - 1) - i];
        // temp[i] (que vai de 0 à len) recebe str[(len-1) - i],
        // que é uma contagem decrescente:
        // | [i] | [len] | [len-1] | [(len-1) - i] |
        // |  0  |  5    |    4    |       4       |
        // |  1  |  5    |    4    |       3       |
        // |  2  |  5    |    4    |       2       |
        // |  3  |  5    |    4    |       1       |
        // |  4  |  5    |    4    |       0       |
    }

    // acrescentar o \0 no final
    temp[len] = '\0';

    printf("Você digitou: %s\n", str);
    printf("Inversa: %s\n", temp);

    // liberar memória
    free(str);
    free(temp);

    printf("Memória liberada.\n");

    return 0;
}
