#pragma once

#include <stdbool.h>

typedef struct {
	int len;
	int *stack;
	int last;
} Stack_i;

Stack_i *i_create(int size);
int i_top(Stack_i *stack);
void i_push(Stack_i *stack, int val);

void i_destroy(Stack_i *stack);
void i_pop(Stack_i *stack);
int i_size(Stack_i *stack);
bool i_empty(Stack_i *stack);