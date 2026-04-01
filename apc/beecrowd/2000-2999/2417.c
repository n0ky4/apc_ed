#include <stdio.h>

int main(void) {
    int cv, ce, cs, fv, fe, fs;
    scanf("%d %d %d %d %d %d", &cv, &ce, &cs, &fv, &fe, &fs);

    int cp = cv*3 + ce;
    int fp = fv*3 + fe;

    if (cp > fp) printf("C\n");
    else if (fp > cp) printf("F\n");
    else {
        if (cs > fs) printf("C\n");
        else if (fs > cs) printf("F\n");
        else printf("=\n");
    }

    return 0;
}
