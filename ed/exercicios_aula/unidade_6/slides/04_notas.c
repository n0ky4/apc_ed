#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int alunos;
    double* notas;
} Turma;

void alocar_notas(Turma* turma) {
    turma->notas = malloc(turma->alunos * sizeof(double));
    if (turma->notas == NULL) {
        printf("Erro: Não foi possível alocar memória.\n");
        exit(EXIT_FAILURE);
    }
}

double pegar_maior_nota(Turma* turma) {
    double maior = turma->notas[0];
    for (int i = 0; i < turma->alunos; i++)
        if (turma->notas[i] > maior)
            maior = turma->notas[i];
    return maior;
}

int main(void) {
    Turma turma;
    double maior;

    // ler n
    printf("Digite o número de alunos: ");
    scanf("%d", &turma.alunos);

    // criar Turma e ler notas
    alocar_notas(&turma);
    for (int i = 0; i < turma.alunos; i++) {
        printf("Digite a nota %d: ", i + 1);
        scanf("%lf", &turma.notas[i]);
    }

    // pegar e imprimir maior nota
    maior = pegar_maior_nota(&turma);
    printf("Maior nota: %.2lf\n", maior);

    // limpar notas
    free(turma.notas);

    return 0;
}
