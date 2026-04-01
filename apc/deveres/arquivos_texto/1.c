#include <stdio.h>
#include <string.h>

int main(void) {
    FILE *fd;
    char nome_arquivo[50];
    int qtd_alunos;

    // Pegar nome do arquivo
    printf("Digite o nome do arquivo (ex: arquivo.txt): ");
    scanf(" %[^\n]", nome_arquivo);

    // Checa se o último caractere do "nome_arquivo" é \n e o remove.
    int len = strlen(nome_arquivo) - 1;
    if (nome_arquivo[len] == '\n') nome_arquivo[len] = '\0';

    // Inicializar file descriptor (fd)
    fd = fopen(nome_arquivo, "w");

    if (fd == NULL) {
        printf("Erro: Não foi possível inicializar o arquivo.\n");
        return 1; // código 1 de erro
    }

    // Pegar quantidade de alunos
    printf("Digite a quantidade de alunos: ");
    scanf(" %d", &qtd_alunos);

    // Para cada aluno
    for (int i = 0; i < qtd_alunos; i++) {
        float notas[3];

        // Perguntar as 3 notas
        for (int p = 0; p < 3; p++) {
            printf("[ALUNO %d] Digite a nota %d: ", i+1, p+1);
            scanf("%f", &notas[p]);
        }

        // Armazenar no arquivo
        fprintf(fd, "%f %f %f\n", notas[0], notas[1], notas[2]);
    }

    printf("Notas escritas com sucesso!\n");

    // Fechar arquivo corretamente
    fclose(fd);

    return 0;
}
