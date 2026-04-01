#include <stdio.h>
#include <math.h>

int main(void) {
    int h, m;

    // leitura até o final do arquivo
    while (scanf("%d %d", &h, &m) != EOF) {
        // calcular a quantidade de testes
        int qt = (h * 60) / m;

        double x[qt];

        // soma p/ calcular a média
        double soma_x = 0;

        for (int i = 0; i < qt; i++) {
            scanf("%lf", &x[i]);
            soma_x += x[i];
        }

        double media_x = soma_x / qt;
        double somatorio = 0;

        for (int i = 0; i < qt; i++) {
            double k = (x[i] - media_x);
            k *= k; // ^2
            somatorio += k;
        }

        double sigma = sqrt((somatorio) / (qt - 1));
        printf("%.5lf\n", sigma);
    }

    return 0;
}
