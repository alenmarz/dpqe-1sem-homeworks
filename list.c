#include "stdlib.h"

#include "list.h"


stack_t* new_stack() {
    stack_t* stack = (stack_t*)malloc(sizeof(stack_t));
    stack->head = NULL;
    return stack;
}


void delete_stack(stack_t *stack) {
    list_t *next, *elem = stack->head;
    while (elem){
        next = elem->next;
        free(elem);
        elem = next;
    }
    free(stack);
}

void delete_queue(queque_t *queue) {
    list_t *next, *elem = queue->head; //добавляем в end, убираем из head
    while (elem){
        next = elem->next;
        free(elem);
        elem = next;
    }
    free(stack);
}


void push(stack_t* stack, int a) {
    list_t* elem = (list_t*)malloc(sizeof(list_t));
    elem->value = a;
    elem->next = stack->head;
    stack->head = elem;
}


int pop(stack_t* stack, int* a) {
    list_t *elem;
    if (stack && stack->head) {
        *a = stack->head->value;
        elem = stack->head->next;
        free(stack->head);
        stack->head = elem;
        return 1;
    } else return 0;
}


int dequeue(queue_t* queue, int* a) {
    queue_t *elem;
    if (queue && queue->head) {
        *a = queue->head->value;
        elem = queue->head->next;
        free(queue->head);
        queue->head = elem;
        return 1;
    } else return 0;
}


void enqueue(queue_t* queue, int a) {
    list_t* elem = (list_t*)malloc(sizeof(list_t));
    queue->end->next = elem;
    elem->value = a;
    queue->end = elem;
}
