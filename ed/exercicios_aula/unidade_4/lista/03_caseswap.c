#include <stdio.h>

void ler_string(char* buffer, size_t tamanho) {
    fgets(buffer, tamanho, stdin);
    for (int i = 0; buffer[i] != '\0'; i++)
        if (buffer[i] == '\n') {
            buffer[i] = '\0';
            break;
        }
}

int main(void) {
    char buffer[1000];

    printf("Digite o texto: ");
    ler_string(buffer, sizeof(buffer));

    for (int i = 0; buffer[i] != '\0'; i++) {
        char original = buffer[i];
        int eh_letra = original >= 'A' && original <= 'z';

        if (!eh_letra) continue;

        int maiusculo = original < 'a';
        char trocado = maiusculo ? original + ' ' : original - ' ';

        buffer[i] = trocado;
    }

    printf("%s\n", buffer);

    return 0;
}
