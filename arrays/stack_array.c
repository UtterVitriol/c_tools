#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int len;
	int *stack;
	int last;
} Stack;

Stack *create(int size);
void destroy(Stack *stack);
int top(Stack *stack);
void push(Stack *stack, int val);
void pop(Stack *stack);
int size(Stack *stack);
bool empty(Stack *stack);

int main(void)
{
	Stack *stack = create(10);
	printf("Size: %d\n", size(stack));
	printf("Empty?: %s\n", empty(stack) ? "true" : "false");

	push(stack, 10);

	printf("Val: %d\n", top(stack));

	push(stack, 20);

	printf("Val: %d\n", top(stack));
	printf("Size: %d\n", size(stack));
	printf("Empty?: %s\n", empty(stack) ? "true" : "false");

	pop(stack);

	printf("Val: %d\n", top(stack));
	printf("Size: %d\n", size(stack));

	destroy(stack);
}

Stack *create(int size)
{
	Stack *new = malloc(sizeof(Stack));

	new->stack = malloc(size * sizeof(int));
	new->len = size;
	new->last = 0;
	return new;
}

void destroy(Stack *stack)
{
	free(stack->stack);
	free(stack);
}

int top(Stack *stack)
{
	return stack->stack[stack->last - 1];
}

void push(Stack *stack, int val)
{
	if (stack->last == stack->len) {
		puts("stack full");
		return;
	}

	stack->stack[stack->last] = val;
	stack->last++;
}

void pop(Stack *stack)
{
	stack->last--;
}

int size(Stack *stack)
{
	return stack->last;
}

bool empty(Stack *stack)
{
	if (stack->last == 0) {
		return true;
	} else {
		return false;
	}
}