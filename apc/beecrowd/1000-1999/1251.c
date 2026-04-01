#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int ascii;
    int freq;
} Letra;

int compare(const void* a, const void* b) {
    Letra *letraA = (Letra *)a;
    Letra *letraB = (Letra *)b;

    // ordem crescente de freq
    int diff = letraA->freq - letraB->freq;
    if (diff != 0) return diff;

    // ordem decrescente de ascii (se houver empate)
    return letraB->ascii - letraA->ascii;
}

int main(void) {
    char buf[1005];
    int first = 1; // checar se é o primeiro (pra printar \n se for >primeiro)

    while (fgets(buf, sizeof(buf), stdin) != NULL) {
        if (first != 1) printf("\n");
        else first = 0;

        int len = strlen(buf);
        // remover \n do fgets
        while (len > 0 && (buf[len-1] == '\n' || buf[len-1] == '\r')) {
            buf[len-1] = '\0';
            len--;
        }

        Letra letras[128];
        for (int k = 0; k < 128; k++) {
            letras[k].freq = 0;
            letras[k].ascii = k;
        }

        for (int k = 0; k < len; k++) {
            // casting pra unsigned char (evitar problemas com ascii extendido)
            int ascii = (unsigned char)buf[k]; 
            if(ascii < 128) letras[ascii].freq++;
        }

        qsort(letras, 128, sizeof(Letra), compare);
        
        for (int k = 0; k < 128; k++) {
            if (letras[k].freq > 0) printf("%d %d\n", letras[k].ascii, letras[k].freq);
        }
    }
    
    return 0;
}
