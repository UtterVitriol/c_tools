#include <stdio.h>
#include <stdlib.h>

#include "max_heap.h"

int main(void)
{
	// int x[] = {4, 7, 100, 9, 6, 10, 2, 1, 5, 8};
	// int z[] = {4, 7, 3, 9, 6, 10, 2, 1, 5, 8};
	// int m = sizeof(z) / sizeof(int);
	// int n = 0;
	// int a[] = {[0 ... 19] = 0};

	// printf("build heap from: 4, 7, 3, 9, 6, 10, 2, 1, 5, 8\n");
	// buildheap(m, z);

	// for (int i = 0; i < m; i++) {
	// 	printf("%d ", z[i]);
	// }
	// puts("");

	// printf("In heap order? %s\n", heap_order(m, z) ? "true" : "false");
	// printf("\n");

	// printf("creating new heap by inserting one item at a time:\n");
	// printf("insert 4, 7, 3, 9, 6, 10, 2, 1, 5, 8\n");
	// for (int i = 0; i < sizeof(x) / sizeof(int); ++i) {
	// 	printf("adding new item %d to heap of %d items\n", x[i], n);
	// 	heap_insert(n, a, x[i]);
	// 	++n;
	// }

	// for (int i = 0; i < m; i++) {
	// 	printf("%d ", a[i]);
	// }
	// puts("");

	// printf("In heap order? %s\n", heap_order(n, a) ? "true" : "false");
	// printf("\n");

	// buildheap(m, x);
	// for (int i = 0; i < m; i++) {
	// 	printf("%d ", x[i]);
	// }

	// puts("");
	// heapsort(m, x);

	// for (int i = 0; i < m; i++) {
	// 	printf("%d ", x[i]);
	// }

	Heap *heap = create_heap(10);

	char test[] = "jihgfedcba";

	for (int i = 0; i < 10; i++) {
		heap_insert(heap, test[i], (int)test[i]);
		// heap->array[i] = create_item(test[i], test[i]);
	}

	for (int i = 0; i < heap->count; i++) {
		printf("%c ", heap->array[i]->val);
	}

	// buildheap(heap->count, heap);

	heap_extract(heap);
	heap_extract(heap);
	heap_extract(heap);

	heapsort(heap->count, heap);

	puts("");

	for (int i = 0; i < heap->count; i++) {
		printf("%c ", heap->array[i]->val);
	}
}

Heap *create_heap(int size)
{
	Heap *new = malloc(sizeof(Heap));

	new->array = calloc(size, sizeof(Item *));
	new->count = 0;
	new->size = size;

	return new;
}

Item *create_item(char item, int key)
{
	Item *new = malloc(sizeof(Item));

	new->val = item;
	new->key = key;

	return new;
}

void heap_insert(Heap *heap, char val, int key)
{
	// if (heap->count == heap->size) {
	// 	puts("heap full...");
	// 	return;
	// }
	Item *new = create_item(val, key);

	heap->array[heap->count] = new;
	heap->count++;

	if (heap->count == 1) {
		return;
	}

	heapify_upshift(heap, heap->count - 1);
	// heapify_upshift(count, arr);
}

void heapify_upshift(Heap *heap, int index)
{
	int p = (index - 1) / 2;
	if (heap->array[index]->key < heap->array[p]->key) {
		Item *temp = heap->array[index];
		heap->array[index] = heap->array[p];
		heap->array[p] = temp;
		heapify_upshift(heap, p);
	}
}

void buildheap(int len, Heap *heap)
{
	for (int i = (len / 2) - 1; i >= 0; i--) {
		heapify_downshift(i, heap, len);
	}
}

// int heap_order(int len, int *arr)
// {
// 	for (int i = 0; i < len; i++) {
// 		int left = (2 * i) + 1;
// 		int right = (2 * i) + 2;

// 		if (left < len) {
// 			if (arr[i] > arr[left])
// 				return 0;
// 		}

// 		if (right < len) {
// 			if (arr[i] > arr[right])
// 				return 0;
// 		}
// 	}

// 	return 1;
// }

void heapify_downshift(int index, Heap *heap, int len)
{
	int left = (2 * index) + 1;
	int right = left + 1;
	int largest = index;

	if (left < len && heap->array[left]->key < heap->array[largest]->key) {
		largest = left;
	}

	if (right < len &&
	    heap->array[right]->key < heap->array[largest]->key) {
		largest = right;
	}

	if (largest != index) {
		Item *temp = heap->array[index];
		heap->array[index] = heap->array[largest];
		heap->array[largest] = temp;
		heapify_downshift(largest, heap, len);
	}
}

void heapsort(int len, Heap *heap)
{
	if (len <= 1) {
		return;
	}

	Item *temp = heap->array[0];
	heap->array[0] = heap->array[len - 1];
	heap->array[len - 1] = temp;

	heapify_downshift(0, heap, len - 1);

	heapsort(len - 1, heap);
}

Item *heap_extract(Heap *heap)
{
	if (heap->count == 0) {
		return NULL;
	}

	if (heap->count == 1) {
		return heap->array[0];
	}

	Item *temp = heap->array[0];
	heap->array[0] = heap->array[heap->count - 1];
	heap->count--;
	heapify_downshift(0, heap, heap->count);

	return temp;
}

// void heap_insert(int len, int *arr, int val)
// {
// 	// (i - 1) / 2 = parent node
// 	// (2 * i) + 1 = left child
// 	// (2 * i) + 2 = right child
// }