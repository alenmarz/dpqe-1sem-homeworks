#include <stdio.h>
#include <stdlib.h>

typedef struct list {
    int x, y;
    struct list* next;
} list_t;


typedef struct stack {
        list_t* head;
} stack_t;


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

void push(stack_t* stack, int x, int y) {
    list_t* elem = (list_t*)malloc(sizeof(list_t));
    elem->x = x;
    elem->y = y;
    elem->next = stack->head;
    stack->head = elem;
}


int pop(stack_t* stack) {
    list_t *elem;
    if (stack && stack->head) {
        printf("(%d, %d)\n", stack->head->x, stack->head->y);
        elem = stack->head->next;
        free(stack->head);
        stack->head = elem;
        return 1;
    } else return 0;
}


int main() {

    int N, M, i, j;

    scanf("%d %d", &N, &M);

    char* str = (char*) malloc (sizeof(char) * M);

    int** map = (int**) malloc (sizeof(int*) * (N + 2)); //index = i * m + j

    for (i = 0; i < N + 2; i++) {
        map[i] = (int*) malloc (sizeof(int) * (M + 2)); //плюс внешняя рамка
        if ((i != 0) && (i != N + 1)) scanf("%s", str);
        for (j = 0; j < M + 2; j++) {
            if (i == 0 || i == N + 1 || j == 0 || j == M + 1) {
                map[i][j] = -2;
                continue;
            }
            if (str[j - 1] == '.') map[i][j] = -1;
            else map[i][j] = -2;
        }
    }

    void rec(x, y, prev_value) {
        if (map[x][y] == -2 || ((map[x][y] >= 0) && (map[x][y] < prev_value))) return;
        map[x][y] = prev_value;
        rec(x + 1, y, prev_value + 1);
        rec(x, y + 1, prev_value + 1);
        rec(x - 1, y, prev_value + 1);
        rec(x, y - 1, prev_value + 1);
    }

    stack_t* track = new_stack();

    void searching_track(x, y, last_value) {
        if (last_value == 0) return;
        push(track, x, y);
        for (i = -1; i < 2; i++)
            for (j = -1; j < 2; j++)
                if ((abs(i - j) == 1) && (map[x + i][y + j] == last_value - 1)) {
                    //push(track, x + i, y + j);
                    searching_track(x + i, y + j, last_value - 1);
                }
    }

    map[1][1] = 0;
    rec(1, 1, 0);

    int last_value = map[N][M];
    
    if (last_value < 0) {
        printf("NO!\n");
        return 0;
    }

    searching_track(N, M, last_value);

    while (pop(track));

    delete_stack(track);

    /*for (i = 0; i < N + 2; i++) {
        for (j = 0; j < M + 2; j++)
            printf("%d ", map[i][j]);
        printf("\n");  
    }*/

    free(map);
    return 0;
}
