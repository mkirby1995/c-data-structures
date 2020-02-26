#include <stdio.h>
#include <stdlib.h>


typedef struct Node {
    int value;
    struct Node *next;
} Node;


typedef struct Linked_List {
    Node *head;
    Node *tail;
    int length; 
} Linked_List;


Node *create_node(int value)
{
    Node *new_node = malloc(sizeof(Node));
    new_node->value = value;
    return new_node;
};


Linked_List *create_linked_list(int value)
{
    Linked_List *new_list = malloc(sizeof(Node) + sizeof(Node) + sizeof(int));
    Node *head = create_node(value);
    new_list->head = head;
    new_list->tail = head;
    new_list->length = 1;
    return new_list;
};


// Push to tail
void push_to_tail(Linked_List *list, int value)
{
    Node *new_tail = create_node(value);
    list->tail->next = new_tail;
    list->tail = new_tail;
    list->length ++;
};


// Push to head
void push_to_head(Linked_List *list, int value)
{
    Node *current = list->head;
    Node *new_node = create_node(value);
    new_node->next = current;
    list->head = new_node;
    list->length++;
};


// Insert at index
void insert(Linked_List *list, int value, int index)
{
    if (index == 0) {
        push_to_head(list, value);
        list->length++;
    } else if (index == list->length) {
        push_to_tail(list, value);
        list->length++;
    } else if (index > list->length) {
        printf("Index too large.\n");
    } else {
        int i = 1;
        Node *current = list->head->next;
        Node *previous = list->head;
        Node *new_node = create_node(value);
        while (i < list->length && i != index) {
            previous = previous->next;
            current = current->next;
            i++;
        };
        new_node->next = current;
        previous->next = new_node;
        list->length++;
    };
};


// Remove Node at index
void remove_node(Linked_List *list, int index)
{
    if (index > list->length) {
        printf("No node to remove\n");
    } else if (index == 0) {
        Node *current = list->head->next;
        Node *previous = list->head;
        list->head = current;
        free(previous);
        list->length--;
    } else {
        int i = 0;
        Node *current = list->head->next;
        Node *previous = list->head;
        while (i < list->length && i < index - 1) {
            previous = previous->next;
            current = current->next;
            i++;
        };
        previous->next = current->next;
        free(current);
        list->length--;
    };
};


// Destroy list
void destroy_list(Linked_List *list)
{
    int i = 0;
    Node *current = list->head->next;
    Node *previous = list->head;
    for (i = 0; i < list->length; i++) {
        previous = current;
        current = current->next;
        free(previous);
        list->length--;
    };
    free(list->head);
}


// Traverse list
void traversal(Linked_List *list)
{
    int i = 0;
    Node *current = list->head;
    for (i = 0; i < list->length; i++) {
        printf("Value %d: %d\n", i, current->value);
        current = current->next;
    };
}


int main()
{
    Linked_List ll = *create_linked_list(8);
    push_to_tail(&ll, 9);
    push_to_tail(&ll, 10);
    push_to_head(&ll, 15);
    push_to_tail(&ll, 3);
    push_to_tail(&ll, 4);
    insert(&ll, 20, 2);
    remove_node(&ll, 2);
    remove_node(&ll, 0);
    remove_node(&ll, 2);
    remove_node(&ll, 3);
    traversal(&ll);
    destroy_list(&ll);
    return 0;
}
