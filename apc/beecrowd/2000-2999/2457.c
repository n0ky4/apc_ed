#include <stdio.h>

int main(void) {
    // obter caractere
    char k;
    scanf("%c", &k);
    getchar();

    // ci = índice do caractere da palavra atual
    // totw = total de palavras
    // totk = total de palavras com o caractere k
    // has = se a palavra atual já encontrou o caractere k
    int ci = 0, totw = 0, totk = 0, has = 0;
    
    while (1) {
        // pegar caractere da entrada
        char c = getchar();
        
        // se o caractere for espaço, \n ou EOF
        if (c == ' ' || c == '\n' || c == EOF) {
            // resetar variáveis para a próxima palavra
            // somente se ci > 0
            if (ci > 0) {
                totw++;
                has = 0;
                ci = 0;
            }

            // se for \n ou EOF, sair do while (entrada acabou)
            if (c == '\n' || c == EOF) break;
            
            continue;
        }

        // se o caractere atual for k, e a flag `has` não estiver marcada
        if (c == k && !has) {
            // marcar flag `has` como 1 e aumentar o 
            // número de palavras com o caractere k
            has = 1;
            totk++;
        }
        // aumentar o índice do caractere da palavra atual
        ci++;
    }

    // calcular porcentagem e imprimí-la
    float pct = 0;
    if (totw > 0) // checa divisão por zero
        pct = ((float)totk / totw) * 100.0;
    printf("%.1f\n", pct);
    
    return 0;
}
