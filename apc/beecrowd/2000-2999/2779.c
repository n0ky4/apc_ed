#include <stdio.h>
#include <string.h>

int main(void) {
    int n, m, unicas = 0, faltando;
    scanf("%d %d", &n, &m);
    
    int arr[n];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < m; i++) {
        int tmp;
        scanf("%d", &tmp);

        if (arr[tmp] != 1) {
            arr[tmp] = 1;
            unicas++;
        }
    }

    faltando = n - unicas;
    printf("%d\n", faltando);
    
    return 0;
}
