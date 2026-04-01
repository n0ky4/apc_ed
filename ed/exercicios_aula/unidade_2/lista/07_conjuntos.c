#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int busca_linear(const int target, const int n, const int arr[n]) {
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        if (x == target) return i;
    }
    return -1;
}

int ler_conjunto(int arr[MAX_SIZE]) {
    int n = 0;
    int tmp;

    while (scanf("%d", &tmp) == 1) {
        // checar se o número não é repetido
        if (busca_linear(tmp, n, arr) == -1) {
            arr[n] = tmp;
            n++;
        }

        if (getchar() == '\n') break;

        if (n >= MAX_SIZE) {
            printf("Erro: excedeu o tamanho máximo.\n");
            exit(1);
        }
    }

    return n;
}

int calcular_intersecao(
    const int a[MAX_SIZE],
    const int b[MAX_SIZE],
    const int asize,
    const int bsize,
    const int intersect_max_size,
    int intersecao[intersect_max_size]
) {
    int n = 0;
    for (int i = 0; i < asize; i++) {
        int xa = a[i];
        if (busca_linear(xa, bsize, b) != -1) {
            intersecao[n] = xa;
            n++;
        }
    }
    return n;
}

int calcular_uniao(
    const int a[MAX_SIZE],
    const int b[MAX_SIZE],
    const int asize,
    const int bsize,
    const int isize,
    const int intersecao[MAX_SIZE],
    const int union_max_size,
    int uniao[union_max_size]
) {
    int usize = 0;
    for (; usize < asize; usize++)
        uniao[usize] = a[usize];

    // para cada elemento em B
    for (int i = 0; i < bsize; i++) {
        int xb = b[i];
        // checar se não intersecciona
        if (busca_linear(xb, isize, intersecao) == -1) {
            uniao[usize] = xb;
            usize++;
        }
    }

    return usize;
}

int calcular_diferenca(
    const int a[MAX_SIZE],
    const int asize,
    const int isize,
    const int intersecao[MAX_SIZE],
    const int diff_max_size,
    int diferenca[diff_max_size]
) {
    int dsize = 0;

    // checar se não há intersecções -> o resultado é o conjunto A
    if (isize == 0) {
        for (; dsize < asize; dsize++)
            diferenca[dsize] = a[dsize];
        return dsize;
    }

    for (int i = 0; i < asize; i++) {
        int xa = a[i];
        if (busca_linear(xa, isize, intersecao) == -1) {
            diferenca[dsize] = xa;
            dsize++;
        }
    }
    return dsize;
}

void imprimir_numeros(int n, int arr[n]) {
    if (n == 0) {
        printf("(vazio)\n");
        return;
    }

    for (int i = 0; i < n; i++) 
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int a[MAX_SIZE], b[MAX_SIZE];

    printf("Digite o conjunto 1: ");
    int asize = ler_conjunto(a);

    printf("Digite o conjunto 2: ");
    int bsize = ler_conjunto(b);

    // calcular intersecção
    int intersect_max_size = MIN(asize, bsize);
    int intersecao[intersect_max_size];
    int isize = calcular_intersecao(a, b, asize, bsize, intersect_max_size, intersecao);
    
    printf("A interseção é: ");
    imprimir_numeros(isize, intersecao);

    // calcular união
    int union_max_size = (asize + bsize) - isize;
    int uniao[union_max_size];
    int usize = calcular_uniao(a, b, asize, bsize, isize, intersecao, union_max_size, uniao);
    
    printf("A união é: ");
    imprimir_numeros(usize, uniao);

    printf("A diferença é: ");
    int diff_max_size = asize - isize;
    int diferenca[diff_max_size];
    int dsize = calcular_diferenca(a, asize, isize, intersecao, diff_max_size, diferenca);
    imprimir_numeros(dsize, diferenca);

    return 0;
}
