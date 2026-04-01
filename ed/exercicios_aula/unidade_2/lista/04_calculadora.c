#include <stdio.h>

typedef enum {
    SOMA = 1,
    SUB,
    MULT,
    DIV,
    SAIR
} OP;

OP ler_operacao() {
    int n, valido = 0;

    while (!valido) { 
        printf("Selecione uma operação:\n  1 - Soma\n  2 - Subtração\n  3 - Multiplicação\n  4 - Divisão\n  5 - Sair\n> ");
        scanf("%d", &n);

        if (n < 1 || n > 5) {
            printf("Erro: Operação inválida.\n");
            continue;
        }

        valido = 1;
    }

    return (OP) n;
}

double ler_numero(int indice) {
    char* label = indice == 1 ? "Primeiro" : "Segundo";
    printf("%s número: ", label);
    
    double tmp;
    scanf("%lf", &tmp);

    return tmp;
}

int main() {
    OP operacao = ler_operacao();

    if (operacao == SAIR) {
        printf("Até a próxima!\n");
        return 0;
    }

    double a = ler_numero(1);
    double b = ler_numero(2);
    double res = 0;

    switch (operacao) {
        case SOMA:
            res = a + b;
            break;
        case SUB:
            res = a - b;
            break;
        case MULT:
            res = a * b;
            break;
        case DIV:
            res = a / b;
            break;
        default: break;
    }

    printf("Resultado: %.2lf\n", res);

    return 0;
}
