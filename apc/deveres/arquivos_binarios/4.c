#include <stdio.h>
#include <string.h>

#define ARQ_ENTRADA "funcionarios.bin"
#define ARQ_SAIDA "funcionarios_salario_atualizado.bin"

typedef struct {
    int cod; // Código
    char depto, nome[30]; // Departamento e Nome
    float sal; // Salário
} tipoDadosFunc;

float novo_salario_mult(float sal) {
    if (sal <= 1000) return 1.3;
    if (sal > 1000 && sal < 5000) return 1.2;
    return 1.1;
}

int main(void) {
    FILE* fin = fopen(ARQ_ENTRADA, "rb");
    FILE* fout = fopen(ARQ_SAIDA, "wb");

    if (fin == NULL || fout == NULL) {
        printf("Erro: Não foi possível ler/inicializar um dos arquivos.\n");
        return 1;
    }

    tipoDadosFunc func;
    int i = 0;
    while (fread(&func, sizeof(tipoDadosFunc), 1, fin) > 0) {
        float mult = novo_salario_mult(func.sal);
        float novo = func.sal * mult;
        float pct = (mult - 1) * 100;

        printf("[%d] R$ %.2f -> R$ %.2f (%.0f%%)\n", func.cod, func.sal, novo, pct);
        
        func.sal = novo;
        fwrite(&func, sizeof(tipoDadosFunc), 1, fout);
        i++;
    }
    
    fclose(fin);
    fclose(fout);

    printf("Total de empregados: %d\n", i);
    
    return 0;
}
