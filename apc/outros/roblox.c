#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define limpar() system("clear")

typedef struct
{
    char username[100];
    long long int robux;
} User;

void mostrar_banner(void) {
    printf("             ___.   .__                \n");
    printf("_______  ____\\_ |__ |  |   _______  ___\n");
    printf("\\_  __ \\/  _ \\| __ \\|  |  /  _ \\  \\/  /\n");
    printf(" |  | \\(  <_> ) \\_\\ \\  |_(  <_> >    < \n");
    printf(" |__|   \\____/|___  /____/\\____/__/\\_ \\\n");
    printf("                  \\/                 \\/\n");
}

int perguntar_operacao(void) {
    int x;
    printf("Operações:\n1. Criar cliente\n2. Depositar\n3. Mostrar usuarios\n4. Sair\n\n");

    printf("Digite a operação: ");
    scanf("%d", &x);
    printf("\n");

    return x;
}

void clear_buffer(void) {
    char ch;
    while ((ch = getchar()) != '\n' && ch != EOF);
}

void criar_cliente(User *cliente) {
    char username[100];
    long long int robux;

    printf("Nome: ");
    clear_buffer();

    fgets(username, sizeof(username), stdin);
    username[strcspn(username, "\n")] = 0;

    printf("Robux: ");
    scanf("%lld", &robux);

    strcpy(cliente->username, username);
    cliente->robux = robux;
}

void mostrar_cliente(User *cliente, int index) {
    printf("%-*d|  %-*s|  %lld R$\n", 4, index, 16, cliente->username, cliente->robux);
}

int buscar_cliente(int index) {
    int i;
    while (1)
    {
        printf("Digite o índice do cliente (%d usuarios disponíveis, -1 para cancelar): ", index);
        scanf("%d", &i);

        if (i == -1) return -1;

        if (i >= 0 && i <= index) return i;
        else
        {
            printf("Erro: Índice inválido.");
            continue;
        }
    }
}

int depositar(int index, User *usuarios) {
    /*
        [códigos de erro]
        -1      Operação cancelada
        -2      Índice inválido
        -3      Saldo insuficiente
        -4      IDs iguais
    */
    int from, to;
    long long int valor;

    printf("ID do remetente: ");
    scanf("%d", &from);

    if (from < 0) return -1;

    if (from > index) return -2;

    printf("Robux a depositar (R$): ");
    scanf("%lld", &valor);

    if (valor < 0) return -1;

    User *rem = &usuarios[from];
    if (rem->robux < valor) return -3;

    printf("ID do destinatário: ");
    scanf("%d", &to);

    if (to < 0) return -1;
    if (to > index) return -2;
    if (from == to) return -4;

    User *dest = &usuarios[to];

    rem->robux -= valor;
    dest->robux += valor;

    return 1;
}

void increase_array(User **usuarios, int *size) {
    printf("size (before): %d\n", *size);
    int new_size = *size + 1;
    printf("new size: %d\n", new_size);

    User *temp = realloc(*usuarios, new_size * sizeof(User));

    if (temp == NULL) {
        perror("Erro ao realocar memória");
        free(usuarios);
        exit(1);
    }

    *usuarios = temp;
    *size = new_size;
    printf("size (after): %d\n", *size);
}

int main(void) {
    int index = 0;
    int size = 2;
    User *usuarios = malloc(size * sizeof(User));

    if (usuarios == NULL) {
        perror("Erro ao alocar memória");
        exit(1);
    }

    limpar();

    while (1)
    {
        mostrar_banner();
        int operacao = perguntar_operacao();

        limpar();

        if (operacao == 1) { // criar cliente
            User c;

            if (size < index+1) increase_array(&usuarios, &size);
            criar_cliente(&c);

            usuarios[index] = c;
            printf("User %d criado com sucesso!\n", index);

            index++;
        }
        else if (operacao == 2) { // depositar 
            if (index < 2) {
                printf("Erro: Ao menos 2 usuarios são necessários para realizar depósito.\n");
                continue;
            }

            int code = depositar(index, usuarios);

            switch (code) {
                case 1: printf("Saldo realizado com sucesso!\n"); break;
                case -1: printf("Operação cancelada.\n"); break;
                case -2: printf("Erro: Índice inválido.\n"); break;
                case -3: printf("Erro: Saldo insuficiente.\n"); break;
                case -4: printf("Erro: IDs iguais.\n"); break;
            }
        }
        else if (operacao == 3) { // mostrar cliente
            if (index == 0) {
                printf("Erro: Não há usuarios para mostrar.\n");
                continue;
            }

            printf("%-*s|  %-*s|  Robux\n", 4, "ID", 16, "Nome");
            for (int i = 0; i < index; i++) {
                mostrar_cliente(&usuarios[i], i);
            }
        }
        else if (operacao == 4) // sair
        {
            printf("Programa finalizado.\n");
            break;
        }
        else // operação inválida
        {
            printf("Erro: Operação inválida!\n");
        }
    }

    free(usuarios);

    return 0;
}
