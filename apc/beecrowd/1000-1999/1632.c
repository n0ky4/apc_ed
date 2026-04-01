#include <stdio.h>
#include <string.h>
#include <ctype.h>

void ler_string(char *str, int n) {
    fgets(str, n, stdin);
    int s = strlen(str) - 1;
    if (s > 0 && str[s] == '\n')
        str[s] = '\0';
}

int variacoes(char *str) {
    int var = 0;
    for (int i = 0; str[i] != '\0'; i++) {
        char c = toupper(str[i]);

        int m = 0;
        if (
            c == 'A' ||
            c == 'E' ||
            c == 'I' ||
            c == 'O' ||
            c == 'S'
        )
            m = 3;
        else
            m = 2;

        if (var == 0) {
            var = m;
            continue;
        }

        var *= m;
    }

    return var;
}

int main(void) {
    int n;
    scanf("%d", &n);
    getchar();

    for (int i = 0; i < n; i++) {
        char tmp[100];
        ler_string(tmp, sizeof(tmp));
        int var = variacoes(tmp);
        printf("%d\n", var);
    }
    
    return 0;
}
