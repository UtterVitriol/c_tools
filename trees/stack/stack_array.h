#pragma once

#include "../bin_tree.h"

struct Stack {
	int len;
	struct Tree **stack;
	int last;
};

struct Stack *s_create(int size);
void s_destroy(struct Stack *stack);
struct Tree *s_top(struct Stack *stack);
void s_push(struct Stack *stack, struct Tree *tree);
void s_pop(struct Stack *stack);
int s_size(struct Stack *stack);
bool s_empty(struct Stack *stack);