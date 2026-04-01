/*
[ Stack - Pilha ]
 - LIFO (Last In, First Out): Último a entrar, primeiro a sair
 - Pilha de pratos
 - Principais operações: push e pop [ O(1) ]
*/
#include <stdio.h>
#include <stdlib.h>

// Linked List
typedef struct Node {
    int data;
    struct Node* next;
} Node;

void push(Node** top, int value) {
    // Criar um novo node
    Node* newNode = (Node*) malloc(sizeof(Node));

    // Checar erro ao alocar
    if (newNode == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }

    // Definir data para value
    newNode->data = value;
    newNode->next = *top; // Novo node aponta para o antigo node do topo

    // O novo node do topo é o newNode
    *top = newNode;
}

int pop(Node** top) {
    // Checar se a stack está vazia
    if (*top == NULL) {
        printf("Stack vazia.\n");
        return -1;
    }

    // Criar um node temporário, cópia do topo
    Node *tmp = *top;
    int value = tmp->data; // Armazenar o valor do topo

    *top = tmp->next; // Topo vira o `next` do topo antigo
    free(tmp); // Liberar espaço do topo antigo

    return value; // Retornar valor removido
}

int main(void) {
    Node *stack = NULL;
    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);

    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));

    return 0;
}
