#include <stdio.h>
#include <string.h>

// gerar ID único do animal usando operador bitwise
int id(int tipo, int categoria, int subcategoria) {
    return (tipo << 3) | (categoria << 2) | subcategoria;
}

// pegar ID dos tipos/cat/sub a partir da entrada do usuário usando o primeiro
// caractere e tamanho da string (se primeiro caractere colidirem)
int input(void) {
    char tmp[14];
    scanf(" %s", tmp);

    switch (tmp[0]) {
        case 'v': return 0; // vertebrado
        case 'c': return 0; // carnivoro
        case 'm': return 1; // mamifero
        case 'o': return 1; // onivoro
        case 'i': return (strlen(tmp) == 6 ? 0 : 1); // inseto | invertebrado 
        case 'a': return (strlen(tmp) == 3 ? 0 : 1); // ave | anelideo
        case 'h': return (strlen(tmp) == 9 ? 2 : 3); // herbivoro | hematofago 
    }

    return -1;
}

int main(void) {
    char* a[16] = { NULL }; // tamanho 16 pq os ids vao de 0-15

    a[id(0, 0, 0)] = "aguia"; 
    a[id(0, 0, 1)] = "pomba"; 
    a[id(0, 1, 1)] = "homem"; 
    a[id(0, 1, 2)] = "vaca"; 
    a[id(1, 0, 3)] = "pulga"; 
    a[id(1, 0, 2)] = "lagarta"; 
    a[id(1, 1, 3)] = "sanguessuga"; 
    a[id(1, 1, 1)] = "minhoca"; 
    
    int tipo = input();
    int cat = input();
    int sub = input();

    printf("%s\n", a[id(tipo, cat, sub)]);

    return 0;
}
