#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
	int head;
	int *queue;
	int tail;
	int len;
	int size;
} Queue;

Queue *create(int size);
void destroy(Queue *queue);
int front(Queue *queue);
void enqueue(Queue *queue, int val);
void dequeue(Queue *queue);
int size(Queue *queue);
bool empty(Queue *queue);

int main(void)
{
	Queue *queue = create(3);
	/// printf("Empty?: %s\n", empty(queue) ? "true" : "false");

	enqueue(queue, 10);
	printf("Val: %d\n", front(queue));

	enqueue(queue, 20);
	enqueue(queue, 30);

	dequeue(queue);
	enqueue(queue, 40);
	dequeue(queue);
	dequeue(queue);
	// dequeue(queue);

	printf("Size: %d\n", size(queue));

	printf("Val: %d\n", front(queue));

	destroy(queue);
}

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

int front(Queue *queue)
{
	if (size > 0) {
		return queue->queue[queue->head];
	} else {
		puts("empty queue");
		return 0;
	}
}

void enqueue(Queue *queue, int val)
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

int size(Queue *queue)
{
	return queue->size;
}

bool empty(Queue *queue)
{
	if (queue->head == queue->tail) {
		return true;
	} else {
		return false;
	}
}