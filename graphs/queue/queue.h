#pragma once
#include <stdbool.h>

#include "../graph.h"

typedef struct Queue {
	int head;
	Node **queue;
	int tail;
	int len;
	int size;
} Queue;

Queue *create(int size);
void destroy(Queue *queue);
Node *front(Queue *queue);
void enqueue(Queue *queue, Node *val);
void dequeue(Queue *queue);
int size(Queue *queue);
int empty(Queue *queue);