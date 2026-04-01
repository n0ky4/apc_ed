#include <stdio.h>

void print_arr(int even, int arr[], int len) {
    char *t = even == 1 ? "par" : "impar";
    for (int i = 0; i < len; i++)
        printf("%s[%d] = %d\n", t, i, arr[i]);
}

void check_len(int even, int *len, int arr[], int n) {
    if (*len >= 5) {
        print_arr(even, arr, *len);
        *len = 0;
    }
    arr[*len] = n;
    *len += 1;
}


int main(void) {
    int x[15], par[5], imp[5], plen = 0, ilen = 0;

    for (int i = 0; i < 15; i++) {
        scanf("%d", &x[i]);

        if (x[i] % 2 == 0) check_len(1, &plen, par, x[i]);
        else check_len(0, &ilen, imp, x[i]);
    }

    if (ilen > 0) print_arr(0, imp, ilen);
    if (plen > 0) print_arr(1, par, plen);

    return 0;
}
