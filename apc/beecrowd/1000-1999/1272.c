#include <stdio.h>

int main(void) {
    int n;
    scanf("%d ", &n);

    for (int i = 0; i < n; i++) {
        char str[51];

        scanf("%[^\n]%*c", str); // ler até \n e discartá-lo

        char res[51];

        int j = 0;
        int k = 0;
        int space = 1;
        while (1) {
            char ch = str[j];

            if (ch == '\0') {
                res[k] = '\0';
                break;
            }

            if (ch == ' ') {
                space = 1;
            } else {
                if (space == 1) {
                    res[k] = ch;
                    k++;
                    space = 0;
                }
            }

            j++;
        }

        printf("%s\n", res);
    }
    
    return 0;
}
