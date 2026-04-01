#include <stdio.h>
#include <string.h>

#define L 51 

int main(void) {
    int c = 0;
    while (1) {
        int n;
        scanf("%d", &n);

        if (n == 0) break;

        char arr[n][L];
        int lens[n];

        int maxlen = -1;

        for (int i = 0; i < n; i++) {
            scanf("%s", arr[i]);
            
            int len = strlen(arr[i]);
            lens[i] = len;

            if (len > maxlen) maxlen = len;
        }

        if (c != 0) printf("\n");
        c++;

        for (int i = 0; i < n; i++) {
            char *str = arr[i];

            int len = lens[i];
            int spc_len = maxlen - len;

            for (int j = 0; j < spc_len; j++) printf(" ");
            printf("%s\n", str);
        }

    }
    
    return 0;
}
