#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* node = (Node*) malloc(sizeof(Node));
    if (node == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    node->value = value;
    node->next = NULL;
    return node;
}

void inserir_inicio(Node** head, int value) {
    Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

void inserir_final(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    
    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void print_all(Node** head) {
    if (*head == NULL) {
        printf("Node vazio.\n");
        return;
    }

    Node* current = *head;
    while (current != NULL) {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

int main(void) {
    Node* node = createNode(10);
    inserir_inicio(&node, 20);
    inserir_inicio(&node, 30);
    inserir_inicio(&node, 40);
    inserir_inicio(&node, 50);

    print_all(&node);

    return 0;
}
