#include <stdio.h>
#include <ctype.h>

#include "list.h"


void case_ (char symbol, stack_t* stack) {
    int new_value;
    if (pop(stack, &new_value))
        switch (symbol) {
            case '+':
                stack->head->value += new_value;
                break;
            case '-':
                stack->head->value -= new_value;
                break;
            case '/':
                stack->head->value /= new_value;
                break;
            case '*':
                stack->head->value *= new_value;
                break;
        }
}



int main() {
    stack_t* stack = new_stack();
    char c;
    int work_with_digit = 0; //чтобы программа реагировала и на ноль
    int digit = 0;
    while ((c = getchar())!= '\n') {    
        if (isdigit(c)) {
            digit = digit * 10 + (c - '0');
            work_with_digit = 1;
        }
        else if (work_with_digit) { 
                push(stack, digit);
                digit = 0;
                work_with_digit = 0;
            }
            
        else if (c != ' ')
                case_(c, stack);
    }
    printf("%f\n", stack->head->value);
    delete_stack(stack);
    return 0;
}
