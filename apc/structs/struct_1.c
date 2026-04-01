#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[100];
    int idade;
    int altura;
} Pessoa;

void modificar_pessoa(Pessoa *pessoa, const char *nome, const int idade, const int altura)
{
    strcpy(pessoa->nome, nome);
    pessoa->idade = idade;
    pessoa->altura = altura;
    printf("Idade addr: %p\n", (int *)&(pessoa->idade));
}

void imprimir_pessoa(const Pessoa *pessoa)
{
    printf("Nome: %s\nIdade: %d\nAltura: %d cm\n", pessoa->nome, pessoa->idade, pessoa->altura);
}

int main(void)
{
    Pessoa eu;

    modificar_pessoa(&eu, "Gustavo", 18, 178);
    imprimir_pessoa(&eu);

    return 0;
}
