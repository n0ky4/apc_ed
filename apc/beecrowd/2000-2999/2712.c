#include <stdio.h>

int gisupper(char c) {
    return (c >= 'A' && c <= 'Z');
}
int gislower(char c) {
    return(c >= 'a' && c <= 'z');
}
int gisnumber(char c) {
    return (c >= '0' && c <= '9');
}
size_t gstrlen(const char *str) {
    size_t len;
    for (len = 0; str[len] != '\0'; len++);
    return len;
}

int validar(const char* str, const int len) {
    if (len != 8) return -1;
    if (str[3] != '-') return -1;

    for (int i = 0; i <= 2; i++) {
        char ch = str[i];
        if (!gisupper(ch)) return -1;
    }

    for (int i = 4; i <= 7; i++) {
        char ch = str[i];
        if (!gisnumber(ch)) return -1;
    }

    char d = str[7];

    if (d == '1' || d == '2') return 0;
    if (d == '3' || d == '4') return 1;
    if (d == '5' || d == '6') return 2;
    if (d == '7' || d == '8') return 3;
    if (d == '9' || d == '0') return 4;

    return -1;
}

int main(void) {
    int n;
    scanf("%d", &n);

    const char dias[5][10] = {
        "MONDAY",
        "TUESDAY",
        "WEDNESDAY",
        "THURSDAY",
        "FRIDAY"
    };

    for (int i = 0; i < n; i++) {
        char str[101];
        scanf(" %[^\n]", str);

        int val = validar(str, gstrlen(str));
        if (val == -1) {
            printf("FAILURE\n");
            continue;
        }

        printf("%s\n", dias[val]);
    }
    
    return 0;
}
