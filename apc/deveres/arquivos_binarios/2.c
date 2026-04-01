#include <stdio.h>
#include <string.h>

#define ARQUIVO "funcionarios.bin"

typedef struct {
    int cod; // Código
    char depto, nome[30]; // Departamento e Nome
    float sal; // Salário
} tipoDadosFunc;

// Função para limpar o buffer (evita problemas de leitura posteriores)
void limpar_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler uma string (e remover \n do final, se houver)
void ler_string(char* str, int size) {
    fgets(str, size, stdin);
    int l = strlen(str) - 1;
    if (l >= 0 && str[l] == '\n') str[l] = '\0';
}

// Função para perguntar dados de um funcionário e retorná-lo
tipoDadosFunc perguntar_func(int indice) {
    tipoDadosFunc f;
    
    printf("[FUNCIONÁRIO %d] Digite o código do funcionário: ", indice);
    scanf("%d", &f.cod);
    limpar_buffer();

    printf("[FUNCIONÁRIO %d] Digite o departamento: ", indice);
    scanf("%c", &f.depto);
    limpar_buffer();

    printf("[FUNCIONÁRIO %d] Digite o nome do funcionário: ", indice);
    ler_string(f.nome, sizeof(f.nome));

    printf("[FUNCIONÁRIO %d] Digite o salário do funcionário: ", indice);
    scanf("%f", &f.sal);
    limpar_buffer();

    return f;
}

// Função para perguntar se o usuário deseja cadastrar outro funcionário
int perguntar_continuar(void) {
    char tmp[2];

    printf("Deseja cadastrar outro funcionário? (S/n): ");
    ler_string(tmp, sizeof(tmp));

    if (tmp[0] == 'n' || tmp[0] == 'N') return 0;
    return 1;
}

int main(void) {
    int continuar = 1, i = 0;
    FILE* fp = fopen(ARQUIVO, "wb");

    if (fp == NULL) {
        printf("Erro: Não foi possível inicializar o arquivo.\n");
        return 1;
    }

    while (continuar) {
        // Perguntar dados do funcionário
        tipoDadosFunc func = perguntar_func(++i);

        // Gravar no arquivo
        fwrite(&func, sizeof(tipoDadosFunc), 1, fp);

        printf("Funcionário '%s' cadastrado com sucesso!\n", func.nome);

        // Perguntar se o usuário deseja continuar
        if (!perguntar_continuar()) continuar = 0;
    }

    // Finalizar arquivo corretamente
    fclose(fp);

    printf("%d funcionários cadastrados com sucesso.\n", i);
    
    return 0;
}
