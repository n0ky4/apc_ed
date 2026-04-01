/*
    
    De acordo com o Teorema da Divisão Euclidiana,
    um número `i` qualquer pode ser escrito como:

        i = q * n + r

    q = quociente
    n = número inserido pelo usuário
    r = resto

    Como queremos que o resto (r) seja 2:
        
        i = q * n + 2 (substituimos r por 2)

    Onde `q` é um número inteiro (0, 1, 2, 3...)

    No loop abaixo, iniciamos `i` como 2,
    e acrescentamos `n` até que `i` seja 
    menor ou igual a 10.000

    Exemplo (n = 3):
    i = 2 -> mostrar i -> i += 3
    i = 5 -> mostrar i -> i += 3
    i = 8 -> mostrar i -> i += 3
    [...]
    i = 9998 -> mostrar i -> i += 3
    [fim (pois i+3 será maior ou igual a 10.000)]

    A forma acima sempre gera números válidos sem
    necessitar usar `bruteforce`.
    
*/
#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 2; i <= 10000; i += n) {
        printf("%d\n", i);
    }
    
    return 0;
}
