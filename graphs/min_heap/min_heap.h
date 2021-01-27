#pragma once

#include "../graph.h"

typedef struct Item {
	u64 v;
	u64 dist;
} Item;

typedef struct Heap {
	Item **array;
	u64 count;
	u64 size;
	u64 *pos;
} Heap;

Heap *create_heap(u64 size);
Item *create_item(u64 v, u64 dist);

void heapsort(u64 len, Heap *heap);
void buildheap(u64 len, Heap *heap);
void heapify_downshift(u64 index, Heap *heap, u64 len);
void heapify_upshift(Heap *heap, u64 index);
void heap_insert(Heap *heap, u64 v, u64 dist);
Item *heap_extract(Heap *heap);
// int heap_order(int, int *);