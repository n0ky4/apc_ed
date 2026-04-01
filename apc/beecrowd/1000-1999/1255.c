#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct {
    char letra;
    int freq;
}Letra;

void limpar_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int compare(const void* a, const void* b) {
    Letra *letraA = (Letra *)a;
    Letra *letraB = (Letra *)b;

    int diff = letraB->freq - letraA->freq;
    if (diff != 0) return diff;

    return (int)letraA->letra - (int)letraB->letra;
}

int main(void) {
    int n;
    scanf("%d", &n);

    limpar_buffer();

    for (int i = 0; i < n; i++) {
        Letra letras[26];
        for (int i = 0; i < 26; i++) {
            letras[i].freq = 0;
            letras[i].letra = 'A' + i;
        }

        int highest = 0;
        char c;
        
        while ((c = getchar()) != '\n') {
            if (!isalpha(c)) continue;

            char upper = toupper(c);
            int idx = (int)upper - 65;

            letras[idx].freq += 1;
            if (highest < letras[idx].freq) highest = letras[idx].freq;
        }

        qsort(letras, 26, sizeof(Letra), compare);

        int current_freq = letras[0].freq, idx = 0;

        while (current_freq == highest) {
            printf("%c", tolower(letras[idx].letra));
            idx++;
            current_freq = letras[idx].freq;
        }

        printf("\n");
    }
    
    return 0;
}
