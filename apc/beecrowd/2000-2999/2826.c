#include <stdio.h>

#define L 21

int mystrcmp(const char *a, const char *b) {
    const unsigned char *p1 = (const unsigned char*)a;
    const unsigned char *p2 = (const unsigned char*)b;
    while (*p1 != '\0' && *p1 == *p2) {
        p1++;
        p2++;
    }
    return (int)(*p1 - *p2);
}

char *mystrcpy(char *dest, const char *src) {
    char *og_dest = dest;
    while((*dest++ = *src++) != '\0');
    return og_dest;
}

int main(void) {
    char a[L], b[L], aux[L];
    scanf("%s %s", a, b);

    int diff = mystrcmp(a, b);
    if (diff > 0) {
        mystrcpy(aux, a); // aux = a;
        mystrcpy(a, b); // a = b
        mystrcpy(b, aux); // b = aux(a)
    }

    printf("%s\n%s\n", a, b);
    return 0;
}
