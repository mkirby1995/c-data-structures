#include <stdio.h>
#include <stdlib.h>


typedef struct Stack {
      char *storage;
      int length;
      int capacity;
} Stack;


Stack *createStack(int capacity)
{
    Stack *newStack = malloc(sizeof(Stack));
    newStack->storage = malloc(capacity * sizeof(char));
    newStack->length = 0;
    newStack->capacity = capacity;
    return newStack;
}


void destroyStack(Stack *stack)
{
    free(stack->storage);
    free(stack);
}


void pushStack(Stack *stack, char value)
{
    *(stack->storage + stack->length) = value;
    stack->length ++;
}


char popStack(Stack *stack)
{
    char return_value = *(stack->storage + stack->length - 1);
    *(stack->storage + stack->length - 1) = 0;
    stack->length --;
    return return_value;
}


void printStack(Stack *stack)
{
    int i = 0;
    for (i = 0; i <= stack->length; i++) {
        printf("Value %d: %c\n", i, *(stack->storage + i));
    };
}


int main(void) {
    Stack S = *createStack(40);
    printStack(&S);
    printf("%d\n", S.capacity);
    printf("Push a\n");
    pushStack(&S, 'a');
    printf("Push b\n");
    pushStack(&S, 'b');
    printf("Push c\n");
    pushStack(&S, 'c');
    printStack(&S);
    printf("Pop: %c\n", popStack(&S));
    printf("Pop: %c\n", popStack(&S));
    printf("Pop: %c\n", popStack(&S));
    printf("Push d\n");
    pushStack(&S, 'd');
    printStack(&S);

    return 0;
}
