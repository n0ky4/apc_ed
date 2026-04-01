#include <stdio.h>

#define L 21

// equivale ao strcmp do string.h
int gstrcmp(const char *s1, const char *s2) {
    int res = 0, pos = 0;
    while (1) {
        char p1 = s1[pos];
        char p2 = s2[pos];

        if (p1 != p2) {
            if (p2 == '\0') res = 1;
            else res = -1;
            break;
        }

        if (p1 == '\0' || p2 == '\0') break;
        pos++;
    }
    return res;
}

// checa se todas as strings de uma array são iguais
int all_eq(int len, char arr[len][L]) {
    int eq = 1;
    for (int i = 0; i < (len-1); i++) {
        char *s1 = arr[i];
        char *s2 = arr[i+1];
        
        int cmp = gstrcmp(s1, s2);
        if (cmp != 0) {
            eq = 0;
            break;
        }
    }
    return eq;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int pessoas;
        scanf("%d", &pessoas);

        char idiomas[pessoas][L];

        for (int p = 0; p < pessoas; p++) {
            scanf("%s", idiomas[p]);
        }

        if (all_eq(pessoas, idiomas)) {
            // se todas as pessoas falam L   -> L
            printf("%s\n", idiomas[0]);
        } else {
            // se diver pessoas q falam diff -> Inglês
            printf("ingles\n");
        }

    }
    
    return 0;
}
