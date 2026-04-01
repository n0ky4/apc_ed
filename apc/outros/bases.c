#include <stdio.h>

#define MAX_BASE 62

char DICT[MAX_BASE] = {
    '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
    'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T',
    'U', 'V', 'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd',
    'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
    'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
    'y', 'z'};


int dec_base(long long int num, int base, char res[100])
{
    if (num == 0)
    {
        res[0] = '0';
        res[1] = '\0';
        return 1;
    }

    // Erros (código -1)
    if (base < 2 || base > MAX_BASE || num < 0) return -1;

    int len = 0;

    while (num != 0)
    {
        res[len] = DICT[(num % base)];
        num /= base;
        len++;
    }

    for (int x = 0; x < len / 2; x++)
    {
        char c = res[x];
        int inv = len - 1 - x;
        res[x] = res[inv];
        res[inv] = c;
    }

    res[len] = '\0';
    return len;
}

int main(void)
{
    char res[100];
    int base;
    long long int n;

    printf("[Conversor de Bases do Decimal]\n\n");

    while (1)
    {

        printf("Digite a base final (2, 8, 16, etc.): ");
        scanf("%d", &base);

        if (base == -1)
            break;

        if (base < 2 || base > MAX_BASE)
        {
            printf("Erro: Base não suportada.\n");
            continue;
        }

        printf("Digite o número em decimal: ");
        scanf("%lld", &n);

        if (n < 0)
        {
            printf("Erro: Apenas números não negativos são suportados.\n");
            continue;
        }

        int code = dec_base(n, base, res);
        if (code != -1) printf("\nResultado: %s\n\n", res);
        
    }

    printf("Programa finalizado.\n");

    return 0;
}
