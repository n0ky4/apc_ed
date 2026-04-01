/*
Conversor de temperatura
*/
#include <stdio.h>

#define FREEZING_PT (32.0)
#define SF_1 (5.0)
#define SF_2 (9.0)

float ftoc(int f)
{
    return (f - FREEZING_PT) * (SF_1 / SF_2);
}

float ctof(int c)
{
    return (c * SF_2 / SF_1) + FREEZING_PT;
}

int perguntar_opcao(void)
{
    int temp;
    printf("Escolha o que deseja converter:\n");
    printf("    1. Celsius    => Fahrenheit\n");
    printf("    2. Fahrenheit => Celsius\n");
    printf("    0. Sair\n\n");
    printf("> ");
    scanf("%d", &temp);
    return temp;
}

void perguntar_temp(float *temp, int tipo)
{
    // *temp => pointer para temp.
    // quando usamos perguntar_temp(&temp, 0), estamos passando
    // o endereço da memória de temp no primeiro argumento

    if (tipo == 0)
    {
        printf("Digite a temperatura (Celsius) > ");
    }
    else
    {
        printf("Digite a temperatura (Fahrenheit) > ");
    }
    scanf("%f", temp);
}

int main(void)
{
    while (1)
    {
        int opcao = perguntar_opcao();
        float temp, conv;

        if (opcao == 1)
        {
            perguntar_temp(&temp, 0);
            conv = ctof(temp);
            printf("\nResultado: %.1f°C = %.1f°F\n\n", temp, conv);
        }
        else if (opcao == 2)
        {
            perguntar_temp(&temp, 1);
            conv = ftoc(temp);
            printf("\nResultado: %.1f°F = %.1f°C\n\n", temp, conv);
        }
        else if (opcao == 0)
        {
            printf("\nPrograma finalizado.\n");
            break;
        }
        else
        {
            printf("\nErro: Escolha inválida.\n\n");
        }
    }

    return 0;
}
