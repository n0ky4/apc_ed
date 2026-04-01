#include <stdio.h>
#include <string.h>

#define ARQUIVO "funcionarios.bin"
#define SEP "+--------------+-------+--------------------------------+-------------+\n"

typedef struct {
    int cod; // Código
    char depto, nome[30]; // Departamento e Nome
    float sal; // Salário
} tipoDadosFunc;

int main(void) {
    FILE* fp = fopen(ARQUIVO, "rb");

    if (fp == NULL) {
        printf("Erro: Não foi possível abrir o arquivo binário.\n");
        return 1;
    }

    printf(SEP);
    printf("| Código       | Depto | Nome                           | Salário     |\n");
    printf(SEP);

    tipoDadosFunc func;
    int i = 0;
    while (fread(&func, sizeof(tipoDadosFunc), 1, fp) > 0) {
        printf(
            "| %-12d |   %-3c | %-30s | R$ %-8.2f |\n",
            func.cod,
            func.depto,
            func.nome,
            func.sal
        );
        i++;
    }
    fclose(fp);
    
    printf(SEP);
    printf("Total de empregados: %d\n", i);
    
    return 0;
}
