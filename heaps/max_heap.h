#pragma once

typedef struct Item {
	char val;
	int key;
} Item;

typedef struct Heap {
	Item **array;
	int count;
	int size;
} Heap;

Heap *create_heap(int size);
Item *create_item(char item, int key);

void heapsort(int len, Heap *heap);
void buildheap(int len, Heap *heap);
void heapify_downshift(int index, Heap *heap, int len);
void heapify_upshift(Heap *heap, int index);
void heap_insert(Heap *heap, char val, int key);
Item *heap_extract(Heap *heap);
// int heap_order(int, int *);