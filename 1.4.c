#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
	char bracket;
	struct stack* prev; 
} stack;

stack* push(stack* current, char a) {
	stack* new_top = (stack*) malloc (sizeof(stack));
	new_top->bracket = a;
	new_top->prev = current;
	return new_top;
}

stack* pop(stack* to_delete) {
	stack* current = to_delete->prev;
	free(to_delete);
	return current;
}

int main() {
	stack* root = (stack*) malloc (sizeof(stack));
	root->prev = NULL;
	stack* current = root;
	char c;
	int is_true = 1;
	while ((c = getchar()) != '\n') {
		if (c == '(' || c == '{')	
			current = push(current, c);
		else
			if ((c == ')') && (current->bracket == '(') || (c == '}') && (current->bracket == '{'))
				current = pop(current);
			else
				is_true = 0;
			// ) -> ( -> allright
			// } -> { -> same
			}
	if (current != root)
		is_true = 0;
	if (is_true == 0)
		printf("Выражение не является верным!\n");
	else
		printf("Выражение является верным!\n");
	return 0;
}	
