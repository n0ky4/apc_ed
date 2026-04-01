#include <stdio.h>

// [MDC ITERATIVO]
// int mdc(int a, int b) {
//     while (b != 0) {
//         int tmp = b;
//         b = a % tmp;
//         a = tmp;
//     }
//     return a;
// }

// [MDC RECURSIVO]
int mdc(int a, int b) {
    if (b == 0) return a;
    return mdc(b, a % b);
}

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", mdc(a,b));
    }
    
    return 0;
}
