/*
[ Linked List - Lista Encadeada ]
 - Cada elemento aponta para o próximo (e para o anterior, se duplamente encadeada)
 - Fácil de inserir / Remover
 - Não-contígua na memória (arrays são contíguas)
 - Memória alocada quando necessário (não precisa realocar)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int value) {
    Node *newNode = malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Erro ao alocar memória.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// O(1)
void insertBegin(Node **head, int value) {
    Node *newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// O(n)
void insertEnd(Node **head, int value) {
    Node *newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

void printList(Node *head) {
    Node *current = head;
    printf("Lista: ");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

void freeList(Node **head) {
    Node *current = *head;
    Node *next;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main(void) {
    Node *list = NULL;

    insertBegin(&list, 10);
    insertBegin(&list, 20);
    insertBegin(&list, 30);

    printList(list);

    insertEnd(&list, -10);
    insertEnd(&list, -20);
    insertEnd(&list, -30);

    printList(list);

    return 0;
}
