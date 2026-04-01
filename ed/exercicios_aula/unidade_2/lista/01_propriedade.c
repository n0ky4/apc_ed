#include <stdio.h>

#define ERRO_ENTRADA -1
#define IS_NUM(x) ((x) >= '0' && (x) <= '9')

// 4 dígitos + '\n' + '\0' = 6 bytes
#define BUFFER_SIZE 6

int tem_propriedade(const char buffer[BUFFER_SIZE]) {
    // ab + cd = x
    // x^2 == abcd
    int ab = (buffer[0] - '0') * 10 + (buffer[1] - '0');
    int cd = (buffer[2] - '0') * 10 + (buffer[3] - '0');
    int abcd = (buffer[0] - '0') * 1000 +
               (buffer[1] - '0') * 100 +
               (buffer[2] - '0') * 10 +
               (buffer[3] - '0');
    int x = ab + cd;

    return x*x == abcd;
}

int ler_numero(char buffer[BUFFER_SIZE]) {
    if (!fgets(buffer, BUFFER_SIZE, stdin)) return ERRO_ENTRADA;

    // se a posição 4 não for uma nova linha ou \0, é um número com mais de 4 dígitos
    if (buffer[4] != '\n' && buffer[4] != '\0') return ERRO_ENTRADA;

    // checar se cada caractere é realmente um dígito
    for (int i = 0; i < 4; i++) 
        if (!IS_NUM(buffer[i])) return ERRO_ENTRADA;

    // setar a posição 4 como \0
    buffer[4] = '\0';

    return 0;
}

int main() {
    char buffer[BUFFER_SIZE];
    
    printf("Digite um número de 4 dígitos: ");
    if (ler_numero(buffer) == ERRO_ENTRADA) {
        printf("Erro: Entrada inválida.\n");
        return 1;
    }
  
    int resultado = tem_propriedade(buffer);
    printf("%s tem a propriedade?: %s\n", buffer, resultado ? "SIM" : "NÃO");
    
    return 0;
}
// 2025, 3025, 9801
