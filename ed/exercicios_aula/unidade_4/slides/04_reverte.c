#include <stdio.h>

void reverte(char* str) {
    int len = 0;
    while (str[len] != '\0') len++;

    for (int i = 0; i < len / 2; i++) {
        char a = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = a;
    }
}

int main(void) {
    char str1[] = "ovatsug";
    reverte(str1);

    printf("%s\n", str1);

    return 0;
}
