#include <stdio.h>
#include <string.h>

int main(void) {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        char str[101];
        scanf(" %[^\n]", str);

        int len = strlen(str);
        int mid = len / 2;

        char res[101];
        int k = 0;

        for (int j = mid - 1; j >= 0; j--) {
            res[k] = str[j];
            k++;
        }

        for (int j = len - 1; j >= mid; j--) {
            res[k] = str[j];
            k++;
        }

        res[k] = '\0';

        printf("%s\n", res);
    }
    
    return 0;
}
