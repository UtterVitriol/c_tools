// Paul Burkhardt
// 01/08/2020
//
// Tutorial for a max heap.
//------------------------------------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <max_heap.h>
#define CAPACITY 10
//------------------------------------------------------------------------------
int main()
{
  int x[] = {4,7,3,9,6,10,2,1,5,8};
  int z[] = {4,7,3,9,6,10,2,1,5,8};
  int m = sizeof(z)/sizeof(int);
  int n = 0;
  int a[] = {[0 ... 19] = 0};

  printf("build heap from: 4, 7, 3, 9, 6, 10, 2, 1, 5, 8\n");
  buildheap(m, z);
  printf("In heap order? %s\n", heap_order(m, z) ? "true" : "false");
  printf("\n");

  printf("creating new heap by inserting one item at a time:\n");
  printf("insert 4, 7, 3, 9, 6, 10, 2, 1, 5, 8\n");
  for (int i = 0; i < sizeof(x)/sizeof(int); ++i)
  {
    printf("adding new item %d to heap of %d items\n", x[i], n);
    heap_insert(n, a, x[i]);
    ++n;
  }

  printf("In heap order? %s\n", heap_order(n, a) ? "true" : "false");
  printf("\n");

  printf("extract three items\n");
  printf("item extracted is %d\n", a[0]);
  heap_extract(n, a);
  --n;
  printf("item extracted is %d\n", a[0]);
  heap_extract(n, a);
  --n;
  printf("item extracted is %d\n", a[0]);
  heap_extract(n, a);
  --n;

  printf("heap is now:\n");
  for (int i = 0; i < n; ++i)
  {
      printf("a[%d] = %d\n", i, a[i]);
  }

  printf("In heap order? %s\n", heap_order(n, a) ? "true" : "false");
  printf("\n");

  printf("now insert 12, 9, 8, 14, 11, 10, 15, 13\n");
  int y[] = {12,9,8,14,11,10,15,13};
  for (int i = 0; i < sizeof(y)/sizeof(int); ++i)
  {
    heap_insert(n, a, y[i]);
    ++n;
  }
  
  printf("In heap order? %s\n", heap_order(n, a) ? "true" : "false");
  printf("\n");

  printf("sort heap using heapsort\n");
  heapsort(n, a);

  printf("final sorted output:\n");
  for (int i = 0; i < n; ++i)
  {
    printf("a[%d]=%d\n", i, a[i]);
  }

  printf("\n");
  printf("creating new heap of size %d\n", CAPACITY);
  int b[CAPACITY];
  n = 0;
  for (int i = 0; i < CAPACITY; ++i)
  {
    printf("adding new item %d to heap of %d items\n", i, n);
    heap_insert(n, b, i);
    ++n;
  }

  printf("In heap order? %s\n", heap_order(n, b) ? "true" : "false");
  printf("\n");

  int N = n;
  for (int i = 0; i < N; ++i)
  {
    printf("extracting root %d\n", b[0]);
    heap_extract(n, b);
    --n;
  }

  return 0;
}
