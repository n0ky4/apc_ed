#include <stdio.h>
#include "tinta.h"

int main(void) {
    Cor cor1 = cor_criar(0.5, 0.5, 0.0);
    Cor cor2 = cor_criar(0.0, 0.0, 1.0);

    Cor misturada = cor_misturar(cor1, cor2);
    Cor esperada = cor_criar(0.25, 0.25, 0.5);

    Cor branco = cor_criar(0.0, 0.0, 0.0);
    Cor preto = cor_criar(1.0, 1.0, 1.0);

    Cor misturada_branco = cor_misturar(cor1, branco);
    Cor misturada_preto = cor_misturar(cor1, preto);

    Cor crazy_values = cor_criar(32.5, -59428, 0.5);

    printf("Cor 1: ");
    cor_imprimir(cor1); printf("\n");

    printf("Cor 2: ");
    cor_imprimir(cor2); printf("\n");

    printf("Cor Crazy Values: ");
    cor_imprimir(crazy_values); printf("\n");

    printf("Cor Misturada: ");
    cor_imprimir(misturada); printf("\n");

    printf("Cor Misturada = Cor Esperada? %s\n", cor_sao_iguais(misturada, esperada) ? "SIM" : "NÃO");
    printf("Cor Branco = Cor Preto? %s\n", cor_sao_iguais(branco, preto) ? "SIM" : "NÃO");

    printf("Cor Branco é Branco? %s\n", cor_e_branco(branco) ? "SIM" : "NÃO");
    printf("Cor Preto é Preto? %s\n", cor_e_preto(preto) ? "SIM" : "NÃO");

    printf("Cor misturada com Branco é ela mesma? %s\n", cor_sao_iguais(misturada_branco, cor1) ? "SIM" : "NÃO");

    printf("Cor misturada com Preto é Preto? %s\n", cor_e_preto(misturada_preto) ? "SIM" : "NÃO");

    return 0;
}
