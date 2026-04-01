#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SLEN 51
#define WLEN 50

// equivale à strcmp
int mystrcmp(const char *s1, const char *s2) {
    const unsigned char *p1 = (unsigned char*)s1;
    const unsigned char *p2 = (unsigned char*)s2;
    while (*p1 != '\0' && *p1 == *p2) {
        p1++;
        p2++;
    }
    return (int)(*p1 - *p2);
}

// bubble sort que ordena em relação ao tamanho das strings
void bubbleSortMelhorado(char arr[][SLEN], int n) {
    int i, j, diff, trocou;
    for (i = 0; i < n - 1; i++) {
        trocou = 0;
        for (j = 0; j < n - 1 - i; j++) {
            diff = strlen(arr[j]) - strlen(arr[j+1]);
            if (diff < 0) {
                char aux[SLEN];
                strcpy(aux, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], aux);
                trocou = 1;
            }
        }
        if (!trocou) break;
    }
}

int main(void) {
    int n;
    scanf("%d", &n);
    getchar(); // consumir o \n

    // para cada n
    for (int i = 0; i < n; i++) {
        char palavra[SLEN]; // armazenar palavra até espaço ou \n
        char palavras[WLEN][SLEN];
        
        // char index e word index
        int char_idx = 0, w_idx = 0;
        
        while (1) {
            // pegar caractere atual
            char c = getchar();

            // se for espaço ou \n ou EOF
            if (c == ' ' || c == '\n' || c == EOF) {
                // só processar se char_idx > 0 [se lemos alguma letra antes do espaço]
                // (ignora espaços duplos)
                if (char_idx > 0) {
                    palavra[char_idx] = '\0';
                    strcpy(palavras[w_idx], palavra);
                    w_idx++;
                }

                // resetar char index
                char_idx = 0;

                // se for \n ou EOF, sair do loop
                if (c == '\n' || c == EOF) break;
                continue;
            }

            // se o char não for espaço ou \n, adicioná-lo à `palavra`
            // e incrementar o char index
            palavra[char_idx] = c;
            char_idx++;
        }

        // ordenar strings por tamanho
        bubbleSortMelhorado(palavras, w_idx);

        // imprimir em apenas uma linha
        for (int j = 0; j < w_idx; j++) {
            printf("%s", palavras[j]);
            if (j != w_idx-1) printf(" ");
        }

        printf("\n");
    }
    
    return 0;
}
