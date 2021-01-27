#include "min_heap.h"

Heap *create_heap(u64 size)
{
	Heap *new = malloc(sizeof(Heap));

	new->array = calloc(size, sizeof(Item *));
	new->count = 0;
	new->size = size;
	new->pos = malloc(size * sizeof(u64));

	return new;
}

Item *create_item(u64 v, u64 dist)
{
	Item *new = malloc(sizeof(Item));

	new->v = v;
	new->dist = dist;

	return new;
}

void heap_insert(Heap *heap, u64 v, u64 dist)
{
	Item *new = create_item(v, dist);

	heap->array[heap->count] = new;
	heap->count++;

	if (heap->count == 1) {
		return;
	}

	heapify_upshift(heap, heap->count - 1);
}

void heapify_upshift(Heap *heap, u64 index)
{
	u64 p = (index - 1) / 2;
	if (heap->array[index]->dist < heap->array[p]->dist) {
		Item *temp = heap->array[index];
		heap->array[index] = heap->array[p];
		heap->array[p] = temp;
		heapify_upshift(heap, p);
	}
}

void buildheap(u64 len, Heap *heap)
{
	for (u64 i = (len / 2) - 1; i > 0; i--) {
		heapify_downshift(i, heap, len);
	}
}

void heapify_downshift(u64 index, Heap *heap, u64 len)
{
	u64 left = (2 * index) + 1;
	u64 right = left + 1;
	u64 smallest = index;

	if (left < len &&
	    heap->array[left]->dist < heap->array[smallest]->dist) {
		smallest = left;
	}

	if (right < len &&
	    heap->array[right]->dist < heap->array[smallest]->dist) {
		smallest = right;
	}

	if (smallest != index) {
		Item *small = heap->array[smallest];
		Item *idx = heap->array[index];

		heap->pos[small->v] = index;
		heap->pos[idx->v] = smallest;

		Item *temp = heap->array[index];
		heap->array[index] = heap->array[smallest];
		heap->array[smallest] = temp;
		heapify_downshift(smallest, heap, len);
	}
}

void heapsort(u64 len, Heap *heap)
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
	// if (heap->count == 0) {
	// 	return NULL;
	// }

	if (heap->count == 1) {
		heap->count--;
		return heap->array[0];
	}

	Item *temp = heap->array[0];
	heap->array[0] = heap->array[heap->count - 1];
	heap->count--;
	heapify_downshift(0, heap, heap->count);

	return temp;
}
