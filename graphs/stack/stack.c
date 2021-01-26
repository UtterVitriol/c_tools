#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack.h"

Stack *stack_create(int size)
{
	Stack *new = malloc(sizeof(Stack));

	new->stack = malloc(size * sizeof(Node *));
	new->len = size;
	new->last = 0;
	return new;
}

void stack_destroy(Stack *stack)
{
	free(stack->stack);
	free(stack);
}

Node *stack_top(Stack *stack)
{
	return stack->stack[stack->last - 1];
}

void stack_push(Stack *stack, Node *val)
{
	if (stack->last == stack->len) {
		puts("stack full");
		return;
	}

	stack->stack[stack->last] = val;
	stack->last++;
}

void stack_pop(Stack *stack)
{
	stack->last--;
}

int stack_size(Stack *stack)
{
	return stack->last;
}

bool stack_empty(Stack *stack)
{
	if (stack->last == 0) {
		return true;
	} else {
		return false;
	}
}