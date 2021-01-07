#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int stack_create(struct stack **stack, int val)
{
	struct stack *new = NULL;

	new = malloc(sizeof(struct stack));

	new->val = val;
	new->next = NULL;

	*stack = new;

	return 1;
}

int stack_free(struct stack *stack)
{
	struct stack *temp = NULL;

	while (stack != NULL) {
		temp = stack->next;
		free(stack);
		stack = temp;
	}

	return 1;
}

int stack_top(struct stack *stack)
{
	return stack->val;
}

int stack_push(struct stack **stack, int val)
{
	struct stack *new = NULL;

	new = malloc(sizeof(struct stack));

	new->val = val;
	new->next = *stack;
	*stack = new;

	return 1;
}

int stack_pop(struct stack **stack)
{
	struct stack *temp = NULL;

	temp = *stack;
	*stack = temp->next;

	free(temp);
	return 1;
}

int stack_size(struct stack *stack)
{
	if (stack->next == NULL) {
		return 1;
	}
	int count = 1;

	while (stack->next != NULL) {
		count++;
		stack = stack->next;
	}

	return count;
}