#include <stdio.h>

void print_arvore(int l, int start_space) {
    for (int i = 1; i <= l; i++) {
        int space = start_space - i; // qtd. de espaços
        int a = (2*i) - 1; // qtd. de asteriscos
        for (int j = 0; j < space; j++)
            printf(" ");
        for (int j = 0; j < a; j++) 
            printf("*");
        printf("\n");
    }
}

int main(void) {
    int n;
    while (scanf("%d", &n) != EOF) {
        int l = (n+1) / 2;
        print_arvore(l, l);
        print_arvore(2, l);
        printf("\n");
    }
    
    return 0;
}
