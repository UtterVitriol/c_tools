#include <stdio.h>
#include <stdlib.h>

#include "stack.h"

int main(void)
{
	struct stack *stack = NULL;

	stack_create(&stack, 6669);

	printf("Val: %d\n", stack_top(stack));
	printf("Val: %d\n", stack_size(stack));

	stack_push(&stack, 69);

	printf("Val: %d\n", stack_top(stack));
	printf("Val: %d\n", stack_size(stack));

	stack_pop(&stack);

	printf("Val: %d\n", stack_top(stack));
	printf("Val: %d\n", stack_size(stack));

	stack_free(stack);
	return 1;
}