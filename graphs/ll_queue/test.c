#include <stdio.h>
#include <stdlib.h>

#include "queue.h"

int main(void)
{
	struct queue *queue = NULL;

	queue_create(&queue, 10);
	printf("Val: %d\n", queue_front(queue));

	enqueue(&queue, 20);
	enqueue(&queue, 30);
	enqueue(&queue, 40);

	printf("REE: %d\n", queue_size(queue));

	dequeue(&queue);
	dequeue(&queue);

	printf("Val: %d\n", queue_front(queue));

	queue_free(queue);
	return 1;
}