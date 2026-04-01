#include <stdio.h>

#define ARQUIVO "alunos.bin"
#define ARQUIVO_MEDIA "media.txt"
#define QTD_ALUNOS 10
#define SEP "+------------------------------------------------------------------------------+\n"

// Definição do tipo `Aluno`
typedef struct {
    int matricula;
    float provas[3];
    float trabalhos[5];
} Aluno;

// Função para criar um struct de `Aluno`
Aluno create_aluno(const int matricula, const float provas[3], const float trabalhos[5]) {
    Aluno aluno;
    
    aluno.matricula = matricula;
    for (int i = 0; i < 5; i++) {
        if (i < 3) aluno.provas[i] = provas[i];
        aluno.trabalhos[i] = trabalhos[i];
    }

    return aluno;
}

// Função para perguntar a opção de programa desejada
int perguntar_opcao(void) {
    printf("ATIVIDADE 1 - AULA PRÁTICA - ARQUIVOS BINÁRIOS\n\n");
    printf("\t1. Gravação com vetores\n");
    printf("\t2. Gravação direta (sem vetores)\n\n");

    int op, valid;
    do {
        printf("Escolha a opção desejada: ");
        scanf("%d", &op);

        valid = op == 1 || op == 2;
        if (!valid) printf("Erro: Opção inválida.\n");
    } while (!valid);
    
    printf("\n");
    
    return op;
}

// Função para mostrar uma tabela de alunos
void mostrar_tabela(const Aluno alunos[]) {
    printf("\n");
    printf(SEP);
    printf("| Matrícula    | P1    | P2    | P3    | T1    | T2    | T3    | T4    | T5    |\n");
    printf(SEP);

    for (int i = 0; i < QTD_ALUNOS; i++) {
        Aluno a = alunos[i];
        printf(
            "| %-12d | %-5.2f | %-5.2f | %-5.2f | %-5.2f | %-5.2f | %-5.2f | %-5.2f | %-5.2f |\n",
            a.matricula,
            a.provas[0], a.provas[1], a.provas[2],
            a.trabalhos[0], a.trabalhos[1], a.trabalhos[2], a.trabalhos[3], a.trabalhos[4]
        );
    }

    printf(SEP);
}

// Função para ler o arquivo binário, gerar arquivo de médias e armazenar os alunos em um vetor
int gerar_medias(Aluno alunos[QTD_ALUNOS]) {
    FILE* fd = fopen(ARQUIVO, "rb");
    FILE* fdm = fopen(ARQUIVO_MEDIA, "w");

    if (fd == NULL) {
        printf("Erro: Não foi possível ler o arquivo.\n");
        return 1;
    }

    if (fdm == NULL) {
        printf("Erro: Não foi possível inicializar o arquivo de média.\n");
        return 1;
    }

    for (int i = 0; i < QTD_ALUNOS; i++) {
        fread(&alunos[i], sizeof(Aluno), 1, fd);

        Aluno a = alunos[i];

        // Calcular média ponderada das provas
        float mp = (
            (2 * a.provas[0]) +
            (3 * a.provas[1]) +
            (3 * a.provas[2])
        ) / 8;
        
        // Calcular média aritmética dos trabalhos
        float mt = 0;
        for (int j = 0; j < 5; j++) 
            mt += a.trabalhos[j];
        mt /= 5;
        
        float mf = (2 * mt + 8 * mp) / 10;

        fprintf(fdm, "%d %f\n", a.matricula, mf);
    }
    
    // Finalizar arquivos corretamente
    fclose(fd);
    fclose(fdm);

    printf("Médias gravadas com sucesso!\n");

    return 0;
}

void perguntar_aluno(int indice, int* matricula, float provas[3], float trabalhos[5]) {
    printf("[ALUNO %d] Digite a matrícula: ", indice);
    scanf("%d", matricula);

    for (int i = 0; i < 3; i++) {
        printf("[ALUNO %d] Digite a nota da Prova %d: ", indice, i+1);
        scanf("%f", &provas[i]);
    }

    for (int i = 0; i < 5; i++) {
        printf("[ALUNO %d] Digite a nota do Trabalho %d: ", indice, i+1);
        scanf("%f", &trabalhos[i]);
    }
}

// Opção 1 - Armazenar N alunos em um vetor de `Alunos` e depois gravar no arquivo binário
int gravacao_vetores(void) {
    Aluno alunos[QTD_ALUNOS];
    FILE* fd = fopen(ARQUIVO, "wb");

    if (fd == NULL) {
        printf("Erro: Não foi possível inicializar o arquivo binário.\n");
        return 1;
    }

    for (int i = 0; i < QTD_ALUNOS; i++) {
        int matricula;
        float provas[3];
        float trabalhos[5];
        perguntar_aluno(i+1, &matricula, provas, trabalhos);

        alunos[i] = create_aluno(matricula, provas, trabalhos);
    }

    // Gravar no arquivo binário
    for (int i = 0; i < QTD_ALUNOS; i++) {
        Aluno aluno = alunos[i];
        fwrite(&aluno, sizeof(Aluno), 1, fd);
    }

    printf("%d alunos gravados com sucesso!\n", QTD_ALUNOS);

    // Finalizar arquivo corretamente
    fclose(fd);

    return 0;
}

// Opção 2 - Armazenar aluno diretamente no arquivo binário
int gravacao_direta(void) {
    FILE* fd = fopen(ARQUIVO, "wb");

    if (fd == NULL) {
        printf("Erro: Não foi possível inicializar o arquivo binário.\n");
        return 1;
    }

    for (int i = 0; i < QTD_ALUNOS; i++) {
        int matricula;
        float provas[3];
        float trabalhos[5];
        perguntar_aluno(i+1, &matricula, provas, trabalhos);

        Aluno tmp = create_aluno(matricula, provas, trabalhos);
        fwrite(&tmp, sizeof(Aluno), 1, fd);
    }

    printf("%d alunos gravados com sucesso!\n", QTD_ALUNOS);

    // Finalizar arquivo corretamente
    fclose(fd);

    return 0;
}

int main(void) {
    int op = perguntar_opcao(); // Programa desejado
    int rc = 0; // Return code

    if (op == 1) rc = gravacao_vetores();
    if (op == 2) rc = gravacao_direta();

    // Se aconteceu algum erro, finalizar
    if (rc != 0) return rc;

    // Ler arquivo binário recém criado e gerar médias
    Aluno alunos[QTD_ALUNOS];
    if (gerar_medias(alunos) != 0) return 1; // Checar se houve erro de arquivo

    // Mostrar tabela de alunos do arquivo binário
    mostrar_tabela(alunos);
    
    return 0;
}
