#include <stdio.h>
#include <string.h>

int carimbadas_compradas(int carimbadas[], int compradas[], int car_len, int com_len) {
    int c = 0, done[300];
    memset(done, 0, sizeof(done));

    for (int i = 0; i < car_len; i++) {
        for (int j = 0; j < com_len; j++) {
            if (carimbadas[i] == compradas[j]) {
                if (done[i] != 1) {
                    c++;
                    done[i] = 1;
                }
            }
        }
    }

    return c;
}

int main(void) {
    int n, c, m;
    scanf("%d %d %d", &n, &c, &m);

    int carimbadas[c];
    for (int i = 0; i < c; i++) 
        scanf("%d", &carimbadas[i]);

    int compradas[m];
    for (int i = 0; i < m; i++) 
        scanf("%d", &compradas[i]);

    int carcom = carimbadas_compradas(carimbadas, compradas, c, m);

    int f = c - carcom;
    printf("%d\n", f);
    
    return 0;
}
