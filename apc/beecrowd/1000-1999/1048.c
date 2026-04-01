#include <stdio.h>

int main(void) {
    float s, r;
    scanf("%f", &s);

    if (s <= 400.0f) r = 0.15f;
    if (s > 400.0f && s <= 800.0f) r = 0.12f;
    if (s > 800.0f && s <= 1200.0f) r = 0.10f;
    if (s > 1200.0f && s <= 2000.0f) r = 0.07f;
    if (s > 2000.0f) r = 0.04f;

    printf(
        "Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: %.0f %%\n",
        s*(1.0f+r), s*r, (r*100.0f)
    );

    return 0;
}
