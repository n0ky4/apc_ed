#include <stdio.h>

// Função para checar se um arquivo existe
int arquivo_existe(const char* arquivo) {
    FILE* tmp = fopen(arquivo, "r");
    if (tmp == NULL) return 0;
    return 1;
}

// Função para ler uma string com espaços
void ler_string(char* str) {
    scanf(" %[^\n]", str);
}

// Função para limpar o buffer de entrada (evita problemas em leituras posteriores)
void limpar_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF); // Executa getchar até encontrar \n ou EOF
}

int main(void) {
    char nome_arquivo[50];
    int qtd_alunos;
    FILE* fd;

    printf("Digite o nome do arquivo: ");
    ler_string(nome_arquivo);

    if (!arquivo_existe(nome_arquivo)) {
        printf("Erro: O arquivo não existe.\n");
        return 1;
    }

    fd = fopen(nome_arquivo, "a");
    if (fd == NULL) {
        printf("Erro: Não foi possível inicializar o arquivo.\n");
        return 1;
    }

    // Pegar quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf("%d", &qtd_alunos);
    limpar_buffer();

    
    // Para cada aluno
    for (int i = 0; i < qtd_alunos; i++) {
        char nome[30];
        int codigo;
        float notas[3];

        printf("[ALUNO %d] Digite o nome do aluno: ", i+1);
        ler_string(nome);

        printf("[ALUNO %d] Digite o código do aluno: ", i+1);
        scanf("%d", &codigo);
        limpar_buffer();

        // Perguntar as 3 notas
        for (int p = 0; p < 3; p++) {
            printf("[ALUNO %d] Digite a nota %d: ", i+1, p+1);
            scanf("%f", &notas[p]);
        }

        limpar_buffer(); // Limpar buffer após todas as leituras numéricas

        // Armazenar no arquivo
        fprintf(fd, "%s %d %f %f %f\n", nome, codigo, notas[0], notas[1], notas[2]);
    }

    printf("Notas escritas com sucesso!\n");
    
    // Fechar arquivo corretamente
    fclose(fd);
    
    return 0;
}
