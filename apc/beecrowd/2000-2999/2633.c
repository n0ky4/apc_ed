#include <stdio.h>
#include <string.h>

typedef struct {
    char nome[21];
    int val;
} Carne;

void ask_carne(Carne* carne) {
    char str[21];
    int val;

    scanf("%s %d", str, &val);
    strcpy(carne->nome, str);

    carne->val = val;
}

void insertion_sort(Carne arr[], int tamanho) {
    int i, j;
    Carne chave;
    for (i = 1; i < tamanho; i++) {
        chave = arr[i];
        j = i - 1;
        while ((j >= 0) && (chave.val < arr[j].val)) {
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = chave;
    }
}

int main(void) {
    int n;

    while (scanf("%d", &n) != EOF) {
        Carne carnes[n];

        for (int i = 0; i < n; i++) 
            ask_carne(&carnes[i]);
        
        insertion_sort(carnes, n);

        for (int i = 0; i < n; i++) {
            printf("%s", carnes[i].nome);
            if (i == (n-1)) printf("\n");
            else printf(" ");
        }
    }
    
    return 0;
}
