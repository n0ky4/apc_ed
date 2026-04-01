/*
[ Stack - Pilha (com array) ]
 - LIFO (Last In, First Out): Último a entrar, primeiro a sair
 - Pilha de pratos
 - Principais operações: push e pop
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5

typedef struct {
    int valores[MAX];
    int topo;
} Stack;

Stack init_stack(void) {
    Stack stack;
    stack.topo = -1;
    return stack;
}

void push(Stack *stack, int value) {
    if (stack->topo == MAX-1) {
        printf("Erro: Stack chegou ao limite.\n");
        exit(1);
    }
    stack->valores[++stack->topo] = value;
}

int pop(Stack *stack) {
    return stack->valores[stack->topo--];
}

int peek(Stack *stack) {
    return stack->valores[stack->topo];
}

int main(void) {
    Stack stack = init_stack();

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));
    printf("%d\n", pop(&stack));

    printf("Peek: %d\n", peek(&stack));

    return 0;
}
