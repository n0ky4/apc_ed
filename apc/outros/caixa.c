#include <stdio.h>
#define CM_KG (166)

int main(void)
{
    int altura, largura, profundidade, volume, peso;

    printf("Digite a altura da caixa: ");
    scanf("%d", &altura);

    printf("Digite a largura da caixa: ");
    scanf("%d", &largura);

    printf("Digite a profundidade da caixa: ");
    scanf("%d", &profundidade);

    printf("Dimensões: %dx%dx%d cm\n", altura, largura, profundidade);
    volume = altura * largura * profundidade;

    printf("Volume: %d\n", volume);
    peso = (volume + CM_KG - 1) / CM_KG;

    printf("Peso: %d kg\n", peso);

    return 0;
}
