#pragma once

struct stack {
	int val;
	struct stack *next;
};

int stack_create(struct stack **stack, int val);

int stack_free(struct stack *stack);

int stack_top(struct stack *stack);

int stack_push(struct stack **stack, int val);

int stack_pop(struct stack **stack);

int stack_size(struct stack *stack);

// int stack_empty(); lol no