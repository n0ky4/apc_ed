#include <stdio.h>

// Retorna 1 se duas strings forem iguais.
// Caso contrário, retorna 0.
int streq(char *str1, char *str2) {
    for (int i = 0; str1[i] == str2[i]; i++)
        if (str1[i] == '\0') return 1;
    return 0;
} 

int main(void) {
    int idade;
    char classificacao[30];
    int acompanhado;

    printf("Digite a idade: ");
    scanf("%d", &idade);

    printf("Digite a classificação (livre, moderado, violento): ");
    scanf("%s", classificacao);

    printf("A pessoa está acompanhada? (1: SIM ; 0: NÃO): ");
    scanf("%d", &acompanhado);

    if (streq(classificacao, "livre")) {
        printf("sim\n");
    } else if (!streq(classificacao, "violento") && idade >= 14) {
        printf("sim\n");
    } else if (acompanhado && idade < 14) {
        printf("sim\n");
    } else if (idade >= 16) {
        printf("sim\n");
    } else {
        printf("não\n");
    }

    return 0;
}
