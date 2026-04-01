#include <stdio.h>
#include <string.h>

// checa se dois caracteres são iguais (case insensitive)
int check_letter(char a, char b) {
    char low = b + 32; // versão minúscula
    return (a == b || a == low);
}

// conta a quantidade de caracteres unicos utilizados
int count_letters(char* str, int len) {
    int unique[26], count = 0;
    memset(unique, 0, sizeof(unique)); // preencher array com zeros

    for (int i = 0; i < len; i++) {
        char ch = str[i];
        for (int j = 65; j <= 90; j++) { // 'A' - 'Z'
            int memi = j - 65; // offset para o índice do array `unique`
            // se o caractere ainda não foi marcado como utilizado, marcá-lo.
            if (unique[memi] == 0 && check_letter(ch, j)) {
                unique[memi] = 1;
                count++;
            }
        }
    }

    return count;
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char str[1001];
        scanf(" %[^\n]", str);

        int letters = count_letters(str, strlen(str));
        
        if (letters == 26) printf("frase completa\n");
        else if (letters >= 13) printf("frase quase completa\n");
        else printf("frase mal elaborada\n");
    }
    
    return 0;
}
