#include <stdio.h>
#include <string.h>

int eh_palindromo(char *texto, int inicio, int fim) {
    if (inicio >= fim) return 1;
    return texto[inicio] == texto[fim]
        && eh_palindromo(texto, inicio + 1, fim - 1);
}

int main(void) {
    while (1) {
        char buffer[1000];
        
        printf("> ");
        fgets(buffer, sizeof(buffer), stdin);
        int size = strlen(buffer);
        if (buffer[size - 1] == '\n') buffer[--size] = '\0';
        
        if (strcmp(buffer, "sair") == 0) break;

        printf("'%s' é palíndromo? %s.\n", buffer, eh_palindromo(buffer, 0, size - 1) ? "SIM" : "NÃO");
    }
    return 0;
}
