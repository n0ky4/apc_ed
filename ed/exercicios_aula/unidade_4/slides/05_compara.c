#include <stdio.h>

int compara(char* str1, char* str2) {
    int i = 0;
    for (i = 0; str1[i] == str2[i]; i++) {
        if (str1[i] == '\0') return 0;
    }
    return str1[i] - str2[i];
}

int main(void) {
    char str1[] = "Gustavo";
    char str2[] = "Gustavor";
    printf("%d\n", compara(str1, str2));
}
