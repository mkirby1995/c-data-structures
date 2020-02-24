#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {
      int *storage;
      int length;
      int capacity;
} Stack;


Stack *createStack(int capacity)
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->storage = malloc(capacity * sizeof(int));
    newStack->length = 0;
    newStack->capacity = capacity;
    return newStack;
}


void destroyStack(Stack *stack)
{
    free(stack->storage);
    free(stack);
}


void pushStack(Stack *stack, int value)
{
    *(stack->storage + stack->length) = value;
    stack->length ++;
}


int popStack(Stack *stack)
{
    int return_value = *(stack->storage + stack->length - 1);
    *(stack->storage + stack->length - 1) = 0;
    stack->length --;
    return return_value;
}


void printStack(Stack *stack)
{
    int i = 0;
    for (i = 0; i <= stack->length; i++) {
        printf("Value %d: %d\n", i, *(stack->storage + i));
    };
}


int main(void) {
    Stack S = *createStack(40);
    printStack(&S);
    printf("%d\n", S.capacity);
    printf("Push 4\n");
    pushStack(&S, 4);
    printf("Push 7\n");
    pushStack(&S, 7);
    printf("Push 8\n");
    pushStack(&S, 8);
    printStack(&S);
    printf("Pop: %d\n", popStack(&S));
    printf("Pop: %d\n", popStack(&S));
    printf("Pop: %d\n", popStack(&S));
    printf("Push 10\n");
    pushStack(&S, 10);
    printStack(&S);

    return 0;
}
