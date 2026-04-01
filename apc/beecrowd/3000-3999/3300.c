#include <stdio.h>

int ma_sorte(const char *str) {
    int is_one = 0;
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] == '3' && is_one) 
            return 1;
        is_one = (str[i] == '1');
    }
    return 0;
}

int main(void) {
    char mala[] = "es de Mala Suerte";
    char no_mala[] = "NO es de Mala Suerte";
    char str[101];
    
    scanf("%s", str);
    
    int ma = ma_sorte(str);
    printf("%s %s\n", str, ma ? mala : no_mala);
    
    return 0;
}
