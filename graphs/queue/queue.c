#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "queue.h"

Queue *create(int size)
{
	Queue *new = malloc(sizeof(Queue));

	new->queue = malloc(size * sizeof(int));

	new->head = 0;
	new->tail = 0;
	new->len = size;
	new->size = 0;

	return new;
}

void destroy(Queue *queue)
{
	free(queue->queue);
	free(queue);
}

Node *front(Queue *queue)
{
	if (size(queue) > 0) {
		return queue->queue[queue->head];
	} else {
		puts("empty queue");
		return 0;
	}
}

void enqueue(Queue *queue, Node *val)
{
	if (queue->head == queue->tail && queue->size > 0) {
		puts("queue full");
		return;
	}

	queue->queue[queue->tail] = val;
	queue->tail++;

	queue->size++;

	if (queue->tail == queue->len) {
		queue->tail = 0;
	}
}

void dequeue(Queue *queue)
{

	if (queue->size > 0) {
		queue->size--;
		queue->head++;
	} else {
		puts("queue empty");
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

int size(Queue *queue)
{
	return queue->size;
}

int empty(Queue *queue)
{
	if (queue->head == queue->tail || queue->size <= 0) {
		return 1;
	} else {
		return 0;
	}
}