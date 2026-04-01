#include <stdio.h>
#include <string.h>

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
    FILE *fd;
    char nome_arquivo[50];
    int qtd_alunos;

    // Pegar nome do arquivo
    printf("Digite o nome do arquivo (ex: arquivo.txt): ");
    ler_string(nome_arquivo);

    // Inicializar file descriptor (fd)
    fd = fopen(nome_arquivo, "w");

    if (fd == NULL) {
        printf("Erro: Não foi possível inicializar o arquivo.\n");
        return 1; // código 1 de erro
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
