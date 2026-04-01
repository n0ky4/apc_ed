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
    char nome_entrada[50], nome_saida[50];
    
    printf("Digite o nome do arquivo de entrada: ");
    ler_string(nome_entrada);
    
    FILE* in_file = fopen(nome_entrada, "r+");
    if (in_file == NULL) { 
        printf("Erro: Arquivo de entrada inexistente.\n");
        return 1;
    }

    printf("Digite o nome do arquivo de saída: ");
    ler_string(nome_saida);

    FILE* out_file = fopen(nome_saida, "w");
    if (out_file == NULL) { 
        printf("Erro: Não foi possível inicializar o arquivo de saída.\n");
        return 1;
    }

    int n = 0, codigo;
    char nome[50];
    float p1, p2, p3;

    while (fscanf(in_file, " %[^0-9] %d %f %f %f", nome, &codigo, &p1, &p2, &p3) != EOF) {
        int len = strlen(nome);

        // Checar se o nome é inválido
        if (len == 1 && nome[0] == '\n') continue;

        // Apagar espaço do final do nome
        if (nome[len-1] == ' ') nome[len-1] = '\0';

        float media = (p1 + p2 + p3) / 3;
        printf("[%d] %s - Média: %f\n", codigo, nome, media);

        fprintf(out_file, "%d %f\n", codigo, media);

        n++;
    }

    fclose(in_file);
    fclose(out_file);
    
    printf("%d médias processadas com sucesso.\n", n);

    return 0;
}
