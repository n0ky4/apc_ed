#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* create_node(int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro: Não foi possível alocar memória.");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insert_begin(Node** head, int value) {
    Node *newNode = create_node(value);
    newNode->next = *head;
    *head = newNode;
}

void print_nodes(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void free_all(Node** head) {
    Node* current = *head;
    Node* next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main(void) {
    Node* head = create_node(10);
    insert_begin(&head, 20);
    insert_begin(&head, 30);
    insert_begin(&head, 40);
    insert_begin(&head, 50);
    print_nodes(head);
    free_all(&head);
}
