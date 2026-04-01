#include <stdio.h>
#include <string.h>

int ler_string(char* buffer, size_t tamanho) {
    fgets(buffer, tamanho, stdin);
    int len = strlen(buffer);
    if (buffer[len - 1] == '\n') buffer[--len] = '\0';
    return len;
}

void limpar_buffer() {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cifra_cesar(int k, int tamanho, char *mensagem, char *saida) {
    char ref = ' '; // caractere de referência (inicial)
    char total_chars = '~' - ref + 1; // caractere final - inicial

    for (int i = 0; i < tamanho; i++) {
        char c = mensagem[i];
        int pos_original = c - ref;
        
        int pos_encriptado = (pos_original + k) % total_chars;
        if (pos_encriptado < 0) pos_encriptado += total_chars;
        
        char encriptado = ref + pos_encriptado;
        saida[i] = encriptado;
    }

    saida[tamanho] = '\0';
}

int main(void) {
    int k;
    char buffer[1000];

    // ler K
    printf("Digite k: ");
    scanf("%d", &k);

    limpar_buffer(); // consumir \n que o scanf deixou

    // ler mensagem
    printf("Digite a mensagem a ser criptografada: ");
    int len = ler_string(buffer, sizeof(buffer));

    char criptografada[len + 1]; // +1 para o \0
    cifra_cesar(k, len, buffer, criptografada);

    printf("\nOriginal: '%s'\n", buffer);
    printf("Criptografada: '%s'\n", criptografada);

    return 0;
}
