#pragma once

#include "../graph.h"

typedef struct Stack {
	int len;
	Node **stack;
	int last;
} Stack;

Stack *stack_create(int size);
void stack_destroy(Stack *stack);
Node *stack_top(Stack *stack);
void stack_push(Stack *stack, Node *val);
void stack_pop(Stack *stack);
int stack_size(Stack *stack);
bool stack_empty(Stack *stack);