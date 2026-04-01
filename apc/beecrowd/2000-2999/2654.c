#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char nome[101];
    int poder;
    int matou;
    int morreu;
}Entidade;

int mystrcmp(const char* s1, const char* s2) {
    const unsigned char *p1 = (const unsigned char*)s1;
    const unsigned char *p2 = (const unsigned char*)s2;
    while (*p1 != '\0' && *p1 == *p2) {
        p1++;
        p2++;
    }
    return (int)(*p1 - *p2);
}

int compare(const void* a, const void* b){
    Entidade *e1 = (Entidade *)a;
    Entidade *e2 = (Entidade *)b;

    int poderDiff = e2->poder - e1->poder;
    if (poderDiff != 0) return poderDiff;

    int matouDiff = e2->matou - e1->matou;
    if (matouDiff != 0) return matouDiff;

    int morreuDiff = e1->morreu - e2->morreu;
    if (morreuDiff != 0) return morreuDiff;

    return mystrcmp(e1->nome, e2->nome);
}

int main(void) {
    int n;
    scanf("%d", &n);
    getchar();

    Entidade entidades[100];

    for (int i = 0; i < n; i++) {
        Entidade *e = &entidades[i];
        scanf("%s %d %d %d", e->nome, &e->poder, &e->matou, &e->morreu);
    }

    qsort(entidades, n, sizeof(Entidade), compare);
    printf("%s\n", entidades[0].nome);

    return 0;
}
