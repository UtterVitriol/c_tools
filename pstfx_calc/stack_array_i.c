#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_array_i.h"

// int main(void)
// {
// 	Stack *stack = create(10);
// 	printf("Size: %d\n", size(stack));
// 	printf("Empty?: %s\n", empty(stack) ? "true" : "false");

// 	push(stack, 10);

// 	printf("Val: %d\n", top(stack));

// 	push(stack, 20);

// 	printf("Val: %d\n", top(stack));
// 	printf("Size: %d\n", size(stack));
// 	printf("Empty?: %s\n", empty(stack) ? "true" : "false");

// 	pop(stack);

// 	printf("Val: %d\n", top(stack));
// 	printf("Size: %d\n", size(stack));

// 	destroy(stack);
// }

Stack_i *i_create(int size)
{
	Stack_i *new = malloc(sizeof(Stack_i));

	new->stack = malloc(size * sizeof(int));
	new->len = size;
	new->last = 0;
	return new;
}

void i_destroy(Stack_i *stack)
{
	free(stack->stack);
	free(stack);
}

int i_top(Stack_i *stack)
{
	return stack->stack[stack->last - 1];
}

void i_push(Stack_i *stack, int val)
{
	if (stack->last == stack->len) {
		puts("stack full");
		return;
	}

	stack->stack[stack->last] = val;
	stack->last++;
}

void i_pop(Stack_i *stack)
{
	stack->last--;
}

int i_size(Stack_i *stack)
{
	return stack->last;
}

bool i_empty(Stack_i *stack)
{
	if (stack->last == 0) {
		return true;
	} else {
		return false;
	}
}