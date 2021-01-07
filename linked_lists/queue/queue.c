#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

// add empty check

int queue_create(struct queue **queue, int val)
{
	struct queue *new = NULL;

	new = malloc(sizeof(struct queue));

	new->val = val;
	new->next = NULL;

	*queue = new;

	return 1;
}

int queue_free(struct queue *queue)
{
	struct queue *temp = NULL;

	while (queue != NULL) {
		temp = queue->next;
		free(queue);
		queue = temp;
	}

	return 1;
}

int queue_front(struct queue *queue)
{
	return queue->val;
}

int enqueue(struct queue **queue, int val)
{
	struct queue *new = NULL;
	struct queue *temp = *queue;
	struct queue *temp_tail = NULL;

	new = malloc(sizeof(struct queue));

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

int dequeue(struct queue **queue)
{
	struct queue *temp = NULL;

	temp = *queue;
	temp->next->tail = temp->tail;
	*queue = temp->next;

	free(temp);
	temp == NULL;
	return 1;
}

int queue_size(struct queue *queue)
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

int queue_empty(struct queue *queue)
{
	if (queue == NULL) {
		return 1;
	}

	return 1;
}