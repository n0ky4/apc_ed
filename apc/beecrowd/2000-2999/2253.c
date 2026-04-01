#include <stdio.h>

int mai(char c) {
    return (c >= 'A' && c <= 'Z');
}
int min(char c) {
    return(c >= 'a' && c <= 'z');
}
int num(char c) {
    return (c >= '0' && c <= '9');
}

int validar(char* str, int len) {
    if (len < 6 || len > 32) return 0;
    int ma = 0, mi = 0, n = 0;
    for (int i = 0; i < len; i++) {
        char ch = str[i];
        if (mai(ch)) ma++;
        else if (min(ch)) mi++;
        else if (num(ch)) n++;
        else return 0;
    }
    return (ma && mi && n);
}

int slen(char* str) {
    int len = 0;
    while (1) {
        char ch = str[len];
        if (ch == '\0') break;
        len++;
    }
    return len;
}

int main(void) {
    char str[128];
    while (scanf(" %[^\n]", str) != EOF) {
        int len = slen(str);
        int valid = validar(str, len);
        if (valid) printf("Senha valida.\n");
        else printf("Senha invalida.\n");
    }
    return 0;
}
