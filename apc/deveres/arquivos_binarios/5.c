#include <stdio.h>

#define ARQ_ENTRADA "funcionarios_salario_atualizado.bin"
#define ARQ_SAIDA "funcionarios_2.bin"

typedef struct {
    int cod; // Código
    char depto, nome[30]; // Departamento e Nome
    float sal; // Salário
} tipoDadosFunc;

int main(void) {
    FILE* fin = fopen(ARQ_ENTRADA, "rb");
    FILE* fout = fopen(ARQ_SAIDA, "wb");

    if (fin == NULL || fout == NULL) {
        printf("Erro: Não foi possível ler/inicializar um dos arquivos.\n");
        return 1;
    }

    int cod;
    printf("Digite o código do funcionário: ");
    scanf("%d", &cod);

    tipoDadosFunc func;
    int found = 0;
    while (fread(&func, sizeof(tipoDadosFunc), 1, fin) > 0) {
        if (func.cod == cod) {
            float novo_sal;
            printf("Digite o novo salário de '%s' (%d): ", func.nome, func.cod);
            scanf("%f", &novo_sal);

            func.sal = novo_sal;
            found = 1;

            printf("Salário atualizado com sucesso!\n");
        }

        fwrite(&func, sizeof(tipoDadosFunc), 1, fout);
    }

    if (!found) 
        printf("Erro: Funcionário de código %d não encontrado.\n", cod);
    
    fclose(fin);
    fclose(fout);

    return 0;
}
