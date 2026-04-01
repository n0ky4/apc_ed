#include <stdio.h>
#include <ctype.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int a, b, res;
        char ch;

        scanf("%d%c%d", &a, &ch, &b);

        if (a == b) {
            res = a*b; 
        } else {
            int upper = isupper(ch);

            if (upper) res = -(a-b);
            else res = a+b;
        }

        printf("%d\n", res);
    }
    
    return 0;
}
