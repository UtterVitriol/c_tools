#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_array_c.h"

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

Stack_c *c_create(int size)
{
	Stack_c *new = malloc(sizeof(Stack_c));

	new->stack = malloc(size * sizeof(char));
	new->len = size;
	new->last = 0;
	return new;
}

void c_destroy(Stack_c *stack)
{
	free(stack->stack);
	free(stack);
}

char c_top(Stack_c *stack)
{
	return stack->stack[stack->last - 1];
}

void c_push(Stack_c *stack, char val)
{
	if (stack->last == stack->len) {
		puts("stack full");
		return;
	}

	stack->stack[stack->last] = val;
	stack->last++;
}

void c_pop(Stack_c *stack)
{
	stack->last--;
}

int c_size(Stack_c *stack)
{
	return stack->last;
}

bool c_empty(Stack_c *stack)
{
	if (stack->last == 0) {
		return true;
	} else {
		return false;
	}
}