#include <stdio.h>

int tamanho(char* string) {
    int i = 0;
    while (string[i] != '\0') i++;
    return i;
}

int ocorre(char* texto, int pos, char* padrao) {
    for (int j = 0; padrao[j] != '\0'; j++)
        if (
            texto[pos + j] == '\0' ||
            (texto[pos + j] != padrao[j] && padrao[j] != '*')
        ) return 0;
    return 1;
}

void imprime_trecho(char* texto, int ini, int tam) {
    for (int i = 0; (i < tam) && (texto[ini + i] != '\0'); i++) {
        printf("%c", texto[ini + i]);
    }
}

int main(void) {
    char* texto = "Muito além, nos confins inexplorados da região mais brega da Borda Ocidental desta Galáxia, há um pequeno sol amarelo e esquecido.";

    char* padrao = "*os";

    for (int i = 0; texto[i] != '\0'; i++) {
        if (ocorre(texto, i, padrao)) {
            imprime_trecho(texto, i, tamanho(padrao));
            printf("\n");
        }
    }

    return 0;
}
