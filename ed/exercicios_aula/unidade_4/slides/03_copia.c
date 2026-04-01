#include <stdio.h>

void copia(char* str1, char* str2) {
    int i;
    for (i = 0; str1[i] != '\0'; i++)
        str2[i] = str1[i];
    str2[i] = '\0';
}

int main(void) {
    char* str1 = "mr nenis";
    char str2[100] = "ola marilene a noite tainha vinho";

    copia(str1, str2);
    printf("str2: '%s'\n", str2);

    return 0;
}
