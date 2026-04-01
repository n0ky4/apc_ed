#include <stdio.h>

// retorna 0 ou 1 dependendo se o olho está aberto (*) ou fechado (-)
int olho_bin(char c) {
    return (c == '*') ? 1 : 0;
}

// monta um número a partir de 3 bits, onde a é o mais significativo
int bindec(int a, int b, int c) {
    return (a << 2) | (b << 1) | c;
}

int main(void) {
    int gritos = 0, res = 0;

    while (gritos < 3) {
        char str[20];
        scanf(" %[^\n]", str);

        if (str[0] == 'c') {
            // é um grito, imprimir resultado e ir para a próxima
            printf("%d\n", res);
            res = 0;
            gritos++;

            continue;
        }

        int a = olho_bin(str[0]); // olho 1
        int b = olho_bin(str[1]); // olho 2
        int c = olho_bin(str[2]); // olho 3

        res += bindec(a, b, c);
    }
    
    return 0;
}
