typedef struct list {
    float value;
    struct list* next;
} list_t;


typedef struct stack {
    list_t* head;
} stack_t;

typedef struct queue {
    list_t *head, *end;
} queue_t;


stack_t* new_stack();
void delete_stack(stack_t *stack);
void push(stack_t* stack, int a);
int pop(stack_t* stack, int* a);
int dequeue(queue_t* queue, int* a);
void enqueue(queue_t* queue, int a);
