#include <stdio.h>

// Macro para calcular o módulo (valor absoluto)
#define abs(x) (x) >= 0 ? (x) : -(x)

// Converter DD:HH:MM:SS para segundos (tempo absoluto)
int tempo_s(int d, int h, int m, int s) {
    return (d * 86400) + (h * 3600) + (m * 60) + s;
}

// Converter segundos para DD:HH:MM:SS
void s_tempo(int ss, int *d, int *h, int *m, int *s) {
    *d = ss / 86400;
    ss %= 86400;

    *h = ss / 3600;
    ss %= 3600;

    *m = ss / 60;
    ss %= 60;

    *s = ss;
}

int main(void) {
    /*
        Algoritmo (esse foi difícil kk):
        - 1. Perguntar 1º horário (D, HH : MM : SS)
        - 2. Perguntar 2º horário (D, HH : MM : SS)
        - 3. Converter os 2 horários em tempo absoluto (segundos)
            - D * (60*60*24) [86400]
            - HH * (60*60) [3600]
            - MM * 60
            - SS
        - 4. Calcular o módulo da diferença entre os dois tempos -> |t2 - t1|
        - 5. Converter a diferença em dia, hora, minutos e segundos
    */

    int d1, h1, m1, s1,
        d2, h2, m2, s2;

    scanf("Dia %d", &d1);
    scanf("%d : %d : %d", &h1, &m1, &s1);

    int t1 = tempo_s(d1, h1, m1, s1);

    scanf(" Dia %d", &d2); // Espaço para consumir o \n do scanf passado (sem ter que limpar o buffer)
    scanf("%d : %d : %d", &h2, &m2, &s2);

    int t2 = tempo_s(d2, h2, m2, s2);
    int diff = abs(t2 - t1);

    int d, m, h, s;
    s_tempo(diff, &d, &h, &m, &s);

    printf("%d dia(s)\n%d hora(s)\n%d minuto(s)\n%d segundo(s)\n", d, h, m, s);

    return 0;
}
