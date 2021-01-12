#pragma once

#include <stdbool.h>

typedef struct {
	int len;
	char *stack;
	int last;
} Stack_c;

Stack_c *c_create(int size);
char c_top(Stack_c *stack);
void c_push(Stack_c *stack, char val);

void c_destroy(Stack_c *stack);
void c_pop(Stack_c *stack);
int c_size(Stack_c *stack);
bool c_empty(Stack_c *stack);