#include <stdio.h>
#include <stdlib.h>

int calls = 0;
int busca_binaria(int *data, int l, int r, int x) {
    calls++;
    int m = (l + r) / 2; // Valor do meio
    
    // Casos base:
    if (l > r) return -1; // Se esquerda > direita, não encontrou
    if (data[m] == x) return m; // Meio == alvo, retornar índice
    
    // Casos recursivos:
    // - Se o meio < alvo:  
    if (data[m] < x) return busca_binaria(data, m + 1, r, x);
    else return busca_binaria(data, l, m - 1, x); // - Se o meio >= alvo
}

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

void print_arr(int *arr, int n) {
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
}

int main(void) {
    int v[] = { 9, 2, 4, 1, -29, 543, 81, 92, 0, -12, -52 };
    int n = sizeof(v) / sizeof(v[0]);

    printf("Vetor Original:\n");
    print_arr(v, n);

    qsort(v, n, sizeof(v[0]), compare); // Ordenar array

    printf("\nVetor Ordenado:\n");
    print_arr(v, n); printf("\n");

    int x;
    printf("Digite o alvo: ");
    scanf("%d", &x);

    int idx = busca_binaria(v, 0, n, x);
    if (idx == -1) printf("Valor não encontrado.");
    else printf("Índice: %d", idx);
    printf(" (chamadas: %d)\n", calls);

    return 0;
}
