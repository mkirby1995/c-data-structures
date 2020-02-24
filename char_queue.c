#include <stdio.h>
#include <stdlib.h>


typedef struct Queue {
      char *storage;
      int length;
      int capacity;
} Queue;


Queue *createQueue(int capacity)
{
    Queue *newQueue = malloc(sizeof(Queue));
    newQueue->storage = malloc(capacity * sizeof(char));
    newQueue->length = 0;
    newQueue->capacity = capacity;
    return newQueue;
}


void destroyQueue(Queue *queue)
{
    free(queue->storage);
    free(queue);
}


void pushQueue(Queue *queue, char value)
{
    *(queue->storage + queue->length) = value;
    queue->length ++;
}


char popQueue(Queue *queue)
{
    int i = 0;
    char return_value = *queue->storage;
    for (i = 0; i <= queue->length; i++) {
        *(queue->storage + i) = *(queue->storage + i + 1);
    };
    queue->length --;
    return return_value;
}


void printQueue(Queue *queue)
{
    int i = 0;
    for (i = 0; i <= queue->length; i++) {
        printf("Value %d: %c\n", i, *(queue->storage + i));
    };
}


int main(void) {
    Queue Q = *createQueue(40);
    printQueue(&Q);
    printf("%d\n", Q.capacity);
    printf("Push a\n");
    pushQueue(&Q, 'a');
    printf("Push b\n");
    pushQueue(&Q, 'b');
    printf("Push c\n");
    pushQueue(&Q, 'c');
    printQueue(&Q);
    printf("Pop: %c\n", popQueue(&Q));
    printf("Pop: %c\n", popQueue(&Q));
    printf("Pop: %c\n", popQueue(&Q));
    printf("Push d\n");
    pushQueue(&Q, 'd');
    printQueue(&Q);

    return 0;
}
