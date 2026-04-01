#include <stdio.h>
#include <string.h>

// calcula a soma dos algarismos de n (ex: 123 -> 1 + 2 + 3)
int soma_alg(int n) {
    int res = 0;
    while (n >= 1) {
        res += n % 10; // pega o último dígito do número
        n /= 10; // remove o último dígito (divisão inteira)
    }
    return res;
}

int main(void) {
    while (1) {
        int n;
        scanf("%d", &n);

        if (n == 0) break;

        for (int t = 0; t < n; t++) {
            int qtd_zeros = 0, qtd_uns = 0;

            char str[1001];
            scanf("%s", str);

            int len = strlen(str);
            int max_size = (len * 9) + 1; // tamanho máximo possível de um valor descompactado

            char descompactado[max_size];
            int desc_i = 0; // índice p/ construção da string descompactada

            int atual = '0';
            for (int i = 0; i < len; i++) {
                char ch = str[i];

                int k = ch - '0'; // converter o char em `i` para inteiro
                
                // preencher o array com o caractere `atual` k vezes
                for (int j = 0; j < k; j++) {
                    descompactado[desc_i] = atual;
                    desc_i++;

                    // contar a quantidade de 0s ou 1s
                    if (atual == '0') qtd_zeros++;
                    else qtd_uns++;
                }

                // trocar o caractere
                if (atual == '0') atual = '1';
                else atual = '0';
            }

            // adicionar \0 (final de string) em `descompactado`
            descompactado[desc_i] = '\0';

            int digito = soma_alg(qtd_zeros) + soma_alg(qtd_uns);

            printf("%d\n", digito);
        }
    }
    

    return 0;
}
