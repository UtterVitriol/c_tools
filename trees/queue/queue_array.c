#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue_array.h"

Queue *q_create(int size)
{
	Queue *new = malloc(sizeof(Queue));

	new->queue = malloc(size * sizeof(struct Tree *));

	new->head = 0;
	new->tail = 0;
	new->len = size;
	new->size = 0;

	return new;
}

void q_destroy(Queue *queue)
{
	free(queue->queue);
	free(queue);
}

struct Tree *q_front(Queue *queue)
{
	if (queue->size > 0) {
		return queue->queue[queue->head];
	} else {
		puts("empty queue");
		return NULL;
	}
}

void q_enqueue(Queue *queue, struct Tree *tree)
{
	if (queue->head == queue->tail && queue->size > 0) {
		puts("queue full");
		return;
	}

	queue->queue[queue->tail] = tree;
	queue->tail++;

	queue->size++;

	if (queue->tail == queue->len) {
		queue->tail = 0;
	}
}

void q_dequeue(Queue *queue)
{

	if (queue->size > 0) {
		queue->size--;
		queue->head++;
	} else {
		puts("queue emptyyy");
		return;
	}

	if (queue->head == queue->len) {
		if (queue->tail > 0) {
			queue->head = 0;
			queue->size--;
			return;
		}
	}
}

int q_size(Queue *queue)
{
	return queue->size;
}

bool q_empty(Queue *queue)
{
	if (queue->head == queue->tail) {
		return true;
	} else {
		return false;
	}
}