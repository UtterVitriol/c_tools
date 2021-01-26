#include <stdio.h>
#include <stdlib.h>

#include "queue.h"
#include "../graph.h"

// add empty check

Queue *queue_create(Node *val)
{
	Queue *new = NULL;

	new = malloc(sizeof(Queue));

	new->val = val;
	new->next = NULL;

	return new;
}

int queue_free(Queue *queue)
{
	Queue *temp = NULL;
	if (queue_empty(queue)) {
		return 1;
	}
	while (queue) {
		temp = queue->next;
		free(queue);
		queue = temp;
	}

	return 1;
}

Node *queue_front(Queue *queue)
{
	return queue->val;
}

int enqueue(Queue **queue, Node *val)
{
	Queue *new = NULL;
	Queue *temp = *queue;
	Queue *temp_tail = NULL;

	new = malloc(sizeof(Queue));

	new->val = val;
	new->next = NULL;
	new->tail = NULL;

	if (temp->tail == NULL) {
		temp->tail = new;
		temp->next = new;
		return 1;
	}

	temp_tail = temp->tail;
	temp_tail->next = new;
	temp->tail = new;

	return 1;
}

int dequeue(Queue **queue)
{
	Queue *temp = NULL;

	temp = *queue;
	if (temp->next) {
		temp->next->tail = temp->tail;
	}
	*queue = temp->next;

	free(temp);
	temp = NULL;
	return 1;
}

int queue_size(Queue *queue)
{
	if (queue->next == NULL) {
		return 1;
	}

	int count = 1;

	while (queue->next != NULL) {
		count++;
		queue = queue->next;
	}

	return count;
}

int queue_empty(Queue *queue)
{
	if (queue == NULL) {
		return 1;
	}

	return 0;
}