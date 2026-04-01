#include <stdio.h>

char resposta(int n) {
    switch(n) {
        case 15: return 'A';
        case 23: return 'B';
        case 27: return 'C';
        case 29: return 'D';
        case 30: return 'E';
        default: return '*';
    }
}

int main(void) {
    while (1) {
        int n;
        scanf("%d", &n);

        if (n == 0) break;

        for (int i = 0; i < n; i++) {
            int x[5], res = 0;

            scanf("%d %d %d %d %d", &x[0], &x[1], &x[2], &x[3], &x[4]);

            for (int j = 0; j < 5; j++) {
                int bit = (x[j] > 127); // >127 ? 1 : 0
                res = (res << 1) | bit;
            }

            char r = resposta(res);
            printf("%c\n", r);
        }
    }

    return 0;
}
