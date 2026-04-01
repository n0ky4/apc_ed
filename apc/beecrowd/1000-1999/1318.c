#include <stdio.h>
#include <string.h>

int main(void) {
    while (1) {
        int n, m;
        scanf("%d %d", &n, &m);

        if (n == 0 && m == 0) break;

        int t[n + 1];
        memset(t, 0, sizeof(t));

        int r = 0;
        for (int i = 0; i < m; i++) {
            int tmp; 
            scanf("%d", &tmp);

            if (t[tmp] == 0) t[tmp] = 1;
            else if (t[tmp] == 1) {
                t[tmp] = 2;
                r++;
            }
        }

        printf("%d\n", r);
    }

    return 0;
}
