// Paul Burkhardt
// 01/06/2020
//
// Tutorial for a max heap.
//------------------------------------------------------------------------------
#ifndef __MAX_HEAP_
#define __MAX_HEAP_
void heapsort(int, int *);

// make array heap order
void buildheap(int, int *);

// corrections
void heapify_downshift(int, int *, int);
void heapify_upshift(int, int *);

// insert and remove?
void heap_insert(int, int *, int);
void heap_extract(int, int *);

// is array in heap order?
int heap_order(int, int *);
#endif
