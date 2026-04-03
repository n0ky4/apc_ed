#ifndef TINTA_H
#define TINTA_H

/// @brief Estrutura de Dados para representar uma cor.
/// @note É declarado no header file para não ser mandatório o uso de ponteiros na implementação.
typedef struct {
    double az, ve, am;
} Cor;

/// @brief Imprime uma cor.
/// @param c Cor a ser impressa.
void cor_imprimir(Cor c);

/// @brief Checa se duas cores são iguais usando um pequeno valor de tolerância (epsilon).
/// @param a Cor a
/// @param b Cor b
/// @return 1 se as cores forem iguais, 0 se forem diferentes.
int cor_sao_iguais(Cor a, Cor b);

/// @brief Checa se uma cor é preto.
/// @param c Cor
/// @return 1 se a cor for preto, 0 se não for.
int cor_e_preto(Cor c);

/// @brief Checa se uma cor é branco.
/// @param c Cor
/// @return 1 se a cor for branco, 0 se não for.
int cor_e_branco(Cor c);

/// @brief Cria uma nova cor a partir de seus valores de azul, vermelho e amarelo.
/// @param az Valor azul (0-1)
/// @param ve Valor vermelho (0-1)
/// @param am Valor amarelo (0-1)
/// @return Cor criada.
/// @note Normaliza os valores se não estiverem dentro do intervalo correto.
Cor cor_criar(double az, double ve, double am);

/// @brief Mistura duas cores.
/// @param a Cor 1
/// @param b Cor 2
/// @return Cor misturada.
Cor cor_misturar(Cor a, Cor b);

#endif // TINTA_H
