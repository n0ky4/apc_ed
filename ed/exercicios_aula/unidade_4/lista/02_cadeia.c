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

    printf("Digite a cadeia: ");
    ler_string(buffer, sizeof(buffer));

    int cadeia = 0, maior = 0;
    for (int i = 0; buffer[i] != '\0'; i++) {
        char c = buffer[i];
        if (c == '0') {
            cadeia++;
        } else {
            if (cadeia > maior) maior = cadeia;
            cadeia = 0;
        }
    }

    printf("%d\n", maior);
    return 0;
}
