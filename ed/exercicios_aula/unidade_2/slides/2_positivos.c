#include <stdio.h>

#define TAM 10

int main(void) {
    int arr[TAM];
    for (int i = 0; i < TAM; i++) {
        printf("Digite o número %d: ", i+1);
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < TAM; i++)
        if (arr[i] > 0) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
