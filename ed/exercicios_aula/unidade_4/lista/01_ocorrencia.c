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
    char buffer[1000], c;
    
    printf("Digite o texto: ");
    ler_string(buffer, sizeof(buffer));
    
    printf("Digite o caractere: ");
    scanf("%c", &c);

    for (int i = 0; buffer[i] != c && buffer[i] != '\0'; i++)
        printf("%c", buffer[i]);
    printf("\n");

    return 0;
}
