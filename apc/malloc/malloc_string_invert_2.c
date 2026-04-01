/*
 Estudo sobre alocação de memória.

 Este programa pega uma string de tamanho arbitrário
 e a inverte (de forma mais eficiente que o primeiro)
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

    // iteramos apenas len / 2, pois trocamos letras de lugar 2 vezes por vez.
    // caso len seja ímpar, len / 2 será a metade arredondada para baixo (floor),
    // pois é uma divisão inteira, e a letra do meio não será trocada (pois já está no meio).
    for (int i = 0; i < len / 2; i++)
    {
        ch = str[i]; // armazenar caractere temporariamente (para conseguirmos trocar)
        // trocar as duas letras de lugar:
        str[i] = str[(len - 1) - i];
        str[(len - 1) - i] = ch;
    }

    printf("Inversa: %s\n", str);

    // liberar memória
    free(str);

    printf("Memória liberada.\n");

    return 0;
}
