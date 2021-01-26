#pragma once

#include <stdint.h>

#include "../graph.h"

#define u64 uint64_t

typedef struct Queue {
	struct Queue *tail;
	struct Node *val;
	struct Queue *next;
} Queue;

Queue *queue_create(Node *val);

int queue_free(Queue *queue);

Node *queue_front(Queue *queue);

int enqueue(Queue **queue, Node *val);

int dequeue(Queue **queue);

int queue_size(Queue *queue);

int queue_empty(Queue *queue);

void destroy_graph(Graph *graph);

void destroy_list(Node *node);