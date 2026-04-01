/*
Recriação das principais funções do string.h
*/
#include <stdio.h>
#include <string.h>

// Retorna o tamanho de uma string
size_t gstrlen(const char *str) {
    size_t len;
    for (len = 0; str[len] != '\0'; len++);
    return len;
}

int gstrcmp(const char *s1, const char *s2) {
    const unsigned char *p1 = (const unsigned char*)s1;
    const unsigned char *p2 = (const unsigned char*)s2;
    // Enquanto todos os caracteres não são null e são iguais:
    while (*p1 != '\0' && *p1 == *p2) {
        p1++;
        p2++;
    }
    // Retornar a diferença entre o primeiro caractere diferente
    // Ou 0 se ambas as strings são iguais até o terminador null
    return (int)(*p1 - *p2);
}

int gisupper(char c) {
    return (c >= 'A' && c <= 'Z');
}
int gislower(char c) {
    return(c >= 'a' && c <= 'z');
}
int gisnumber(char c) {
    return (c >= '0' && c <= '9');
}


void remove_trailing_nl(char* str) {
    int i = 0;
    while (1) {
        char ch = str[i];
        if (ch == '\n') {
            str[i] = '\0';
            break;
        }
        if (ch == '\0') break;
        i++;
    }
}


int main(void) {
    char* s1 = "Gustavo";
    char* s2 = "Gustavo";

    int cmp = gstrcmp(s1, s2);
    printf("%d = %d\n", cmp, strcmp(s1, s2));

    return 0;
}
