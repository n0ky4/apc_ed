#include <stdio.h>
#include <string.h>

// tamanho máximo da string
#define ML 101

void populate_array(const int len, char arr[len][ML]) {
    for (int i = 0; i < len; i++) {
        char str[ML];
        scanf(" %[^\n]", str);
        strcpy(arr[i], str); // arr[i] = str
    }
}

int comparar(char *src, char *dst) {
    int i = 0;
    int match = 0;
    while (1) {
        char a = src[i], b = dst[i];
        
        if (a == '\0' || b == '\0') break;
        
        if (a == b) match++;
        else return 0;

        i++;
    }
    return match;
}

int main(void) {
    int n, q;

    scanf("%d", &n); // ler n

    // popular array pesquisas
    char dicionario[n][ML];
    populate_array(n, dicionario);

    scanf("%d", &q); // ler q

    // popular array buscas
    char buscas[q][ML];
    populate_array(q, buscas);

    for (int i = 0; i < q; i++) {
        char *busca = buscas[i];

        int matches = 0;
        int maxlen = 0;

        for (int j = 0; j < n; j++) {
            char *dict = dicionario[j];
            
            int cmp = comparar(dict, busca);
            if (cmp > 1) {
                matches++;
                int len = strlen(dict);
                if (len > maxlen) maxlen = len;
            }

        }

        if (matches > 0) {
            printf("%d %d\n", matches, maxlen);
        } else {
            printf("-1\n");
        }
    }
    
    return 0;
}
