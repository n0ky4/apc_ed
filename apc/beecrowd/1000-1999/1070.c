#include <stdio.h>

int main(void) {
    int n;
    scanf("%d", &n);
    if (n%2!=0) n--;
    for (int i = 0; i < 6; i++) {
        printf("%d\n", n+(2*i+1));
    }
    return 0;
}
