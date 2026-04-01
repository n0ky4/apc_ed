#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char nome[100];
    char cor[50];
    char tamanho;
} Camiseta;

// Limpa o buffer pra evitar problema em leituras futuras
void limpar_buffer(void) {
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Lê uma string com fgets e remove o \n no final (se houver)
void ler_string(char *str, int len) {
    fgets(str, len, stdin);
    int l = strlen(str) - 1;
    if (l > 0 && str[l] == '\n') str[l] = '\0';
}

// Pega o tamanho (P, M, G) e retorna um inteiro baseado em ordem decrescente (0, 1, 2)
int tamanho_int(const char tamanho) {
    switch (tamanho) {
        case 'P': return 0;
        case 'M': return 1;
        case 'G': return 2;
    }
    return -1;
}

// Compara duas strings (igual strcmp)
int gstrcmp(const char *s1, const char *s2) {
    const unsigned char *p1 = (const unsigned char*)s1;
    const unsigned char *p2 = (const unsigned char*)s2;
    // Enquanto todos os caracteres não são null e são iguais:
    while (*p1 != '\0' && *p1 == *p2) {
        p1++;
        p2++;
    }
    // Retornar a diferença entre o primeiro caractere diferente
    // Ou 0 se ambas as strings são iguais até o terminador null
    return (int)(*p1 - *p2);
}

// Função para ordenar a lista de camisetas (com tie break)
// cor(a-z) -> tamanho (p-g) -> nome (a-z)
int compare(const void* a, const void* b) {
    Camiseta *camA = (Camiseta *)a;
    Camiseta *camB = (Camiseta *)b;
    
    // Compara cor
    int diffA = strcmp(camA->cor, camB->cor);
    if (diffA != 0) return diffA;

    // Compara tamanho
    int diffB = tamanho_int(camA->tamanho) - tamanho_int(camB->tamanho);
    if (diffB != 0) return diffB;

    // Compara nome
    int diffC = strcmp(camA->nome, camB->nome);
    return diffC;
}

int main(void) {
    int mark = 0;
    while (1) {
        // Ler n
        int n;
        scanf("%d", &n);
        if (n == 0) break;

        if (mark) printf("\n");
        else mark = 1;

        limpar_buffer();
        
        // Ler camisetas
        Camiseta camisetas[n];
        for (int i = 0; i < n; i++) {
            Camiseta* c = &camisetas[i];

            ler_string(c->nome, 100);

            scanf("%s %c", c->cor, &c->tamanho);
            limpar_buffer();
        }

        // Ordenar camisetas
        qsort(camisetas, n, sizeof(Camiseta), compare);
        
        // Imprimir resultado
        for (int i = 0; i < n; i++) {
            Camiseta c = camisetas[i];
            printf("%s %c %s\n", c.cor, c.tamanho, c.nome);
        }
    }

    return 0;
}
