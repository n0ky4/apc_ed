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

    int classificacao_livre = streq(classificacao, "livre");
    int nao_violento_idade_ok = !streq(classificacao, "violento") && idade >= 14;
    int acompanhado_idade_ok = acompanhado && idade < 14;
    int idade_ok = idade >= 16;

    if (
        !classificacao_livre &&
        !nao_violento_idade_ok &&
        !acompanhado_idade_ok &&
        !idade_ok
    ) {
        printf("não\n");
    } else {
        printf("sim\n");
    }

    return 0;
}
