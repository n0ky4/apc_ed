#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SLEN 100
#define WLEN 1001

typedef struct {
    char nome[SLEN];
    int freq;
}Item;

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

// compare para ordenar em ordem alfabética
int compare(const void *a, const void *b) {
    Item *ia = (Item *)a;
    Item *ib = (Item *)b;
    return mystrcmp(ia->nome, ib->nome);
}

int main(void) {
    int n;
    scanf("%d", &n);
    getchar(); // consumir o \n

    // para cada n
    for (int i = 0; i < n; i++) {
        char palavra[SLEN]; // armazenar palavra até espaço ou \n
        Item itens[WLEN]; // array com itens únicos e suas frequências de aparição
        
        // char index e word index
        int char_idx = 0, w_idx = 0;
        
        while (1) {
            // pegar caractere atual
            char c = getchar();

            // se for espaço ou \n (fim da string)
            if (c == ' ' || c == '\n' || c == EOF) {
                // só processar se char_idx > 0 [se lemos alguma letra antes do espaço]
                // (ignora espaços duplos)
                if (char_idx > 0) {
                    palavra[char_idx] = '\0';

                    // checar se há uma entrada com o mesmo nome.
                    // se sim, incrementar freq.
                    int found = 0;
                    for (int j = 0; j < w_idx; j++) {
                        if (mystrcmp(palavra, itens[j].nome) == 0) {
                            itens[j].freq += 1;
                            found = 1;
                            break;
                        }
                    }

                    // caso contrário, criar entrada
                    if (found == 0) {
                        itens[w_idx].freq = 1;
                        strcpy(itens[w_idx].nome, palavra);
                        w_idx++;
                    }
                }

                // resetar char index
                char_idx = 0;

                // se for \n, sair do loop
                if (c == '\n' || c == EOF) break;
                continue;
            }

            // se o char não for espaço ou \n, adicioná-lo à `palavra`
            // e incrementar o char index
            palavra[char_idx] = c;
            char_idx++;
        }

        // ordenar os itens por ordem alfabética
        qsort(itens, w_idx, sizeof(Item), compare);

        // imprimir os itens em apenas uma linha
        for (int j = 0; j < w_idx; j++) {
            printf("%s", itens[j].nome);
            if (j != w_idx-1) printf(" ");
        }
        printf("\n");
    }
    
    return 0;
}
