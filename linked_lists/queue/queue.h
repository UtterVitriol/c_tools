#pragma once

struct queue {
	struct queue *tail;
	int val;
	struct queue *next;
};

int queue_create(struct queue **queue, int val);

int queue_free(struct queue *queue);

int queue_front(struct queue *queue);

int enqueue(struct queue **queue, int val);

int dequeue(struct queue **queue);

int queue_size(struct queue *queue);

int queue_empty(struct queue *queue);