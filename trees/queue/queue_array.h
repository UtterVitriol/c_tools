#pragma once

#include <stdbool.h>
#include "../bin_tree.h"

typedef struct {
	int head;
	struct Tree **queue;
	int tail;
	int len;
	int size;
} Queue;

Queue *q_create(int size);
void q_destroy(Queue *queue);
struct Tree *q_front(Queue *queue);
void q_enqueue(Queue *queue, struct Tree *tree);
void q_dequeue(Queue *queue);
int q_size(Queue *queue);
bool q_empty(Queue *queue);