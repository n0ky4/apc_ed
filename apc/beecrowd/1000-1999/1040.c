#include <stdio.h>

int main(void) {
    float n1, n2, n3, n4, media;

    scanf("%f %f %f %f", &n1, &n2, &n3, &n4);
    media = (n1*2 + n2*3 + n3*4 + n4) / 10;

    printf("Media: %.1f\n", media);
    
    if (media >= 7.0) {
        printf("Aluno aprovado.\n");
        return 0;
    }

    if (media < 5.0) {
        printf("Aluno reprovado.\n");
        return 0;
    }

    printf("Aluno em exame.\n");

    float ne;
    scanf("%f", &ne);

    printf("Nota do exame: %.1f\n", ne);
    media = (media + ne) / 2;

    if (media >= 5.0) {
        printf("Aluno aprovado.\n");
    } else {
        printf("Aluno reprovado.\n");
    }
    printf("Media final: %.1f\n", media);

    return 0;
}
