#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "stack_array.h"

struct Stack *s_create(int size)
{
	struct Stack *new = malloc(sizeof(struct Stack));

	new->stack = malloc(size * sizeof(struct Tree *));
	new->len = size;
	new->last = 0;
	return new;
}

void s_destroy(struct Stack *stack)
{
	free(stack->stack);
	free(stack);
}

struct Tree *s_top(struct Stack *stack)
{
	return stack->stack[stack->last - 1];
}

void s_push(struct Stack *stack, struct Tree *tree)
{
	if (stack->last == stack->len) {
		puts("stack full");
		return;
	}

	stack->stack[stack->last] = tree;
	stack->last++;
}

void s_pop(struct Stack *stack)
{
	stack->last--;
}

int s_size(struct Stack *stack)
{
	return stack->last;
}

bool s_empty(struct Stack *stack)
{
	if (stack->last == 0) {
		return true;
	} else {
		return false;
	}
}