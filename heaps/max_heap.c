#include <stdio.h>
#include <stdlib.h>

#include "max_heap.h"

int main(void)
{
	int x[] = {4, 7, 3, 9, 6, 10, 2, 1, 5, 8};
	int z[] = {4, 7, 3, 9, 6, 10, 2, 1, 5, 8};
	int m = sizeof(z) / sizeof(int);
	int n = 0;
	int a[] = {[0 ... 19] = 0};

	printf("build heap from: 4, 7, 3, 9, 6, 10, 2, 1, 5, 8\n");
	buildheap(m, z);

	for (int i = 0; i < m; i++) {
		printf("%d ", z[i]);
	}
	puts("");

	printf("In heap order? %s\n", heap_order(m, z) ? "true" : "false");
	printf("\n");

	printf("creating new heap by inserting one item at a time:\n");
	printf("insert 4, 7, 3, 9, 6, 10, 2, 1, 5, 8\n");
	for (int i = 0; i < sizeof(x) / sizeof(int); ++i) {
		printf("adding new item %d to heap of %d items\n", x[i], n);
		heap_insert(n, a, x[i]);
		++n;
	}

	for (int i = 0; i < m; i++) {
		printf("%d ", a[i]);
	}
	puts("");

	printf("In heap order? %s\n", heap_order(n, a) ? "true" : "false");
	printf("\n");

	buildheap(m, x);
	heapsort(m, x);

	for (int i = 0; i < m; i++) {
		printf("%d ", x[i]);
	}
}

void heap_insert(int count, int *arr, int new)
{
	arr[count] = new;

	heapify_upshift(count, arr);
}

void heapify_upshift(int index, int *arr)
{
	if (index < 0)
		return;

	if (arr[index] > arr[(index - 1) / 2]) {
		arr[index] = arr[index] ^ arr[(index - 1) / 2];
		arr[(index - 1) / 2] = arr[index] ^ arr[(index - 1) / 2];
		arr[index] = arr[index] ^ arr[(index - 1) / 2];

		heapify_upshift((index - 1) / 2, arr);
	}
}

void buildheap(int len, int *arr)
{
	for (int i = len - 1; i >= 0; i--) {
		if (arr[i] > arr[(i - 1) / 2]) {
			arr[i] = arr[i] ^ arr[(i - 1) / 2];
			arr[(i - 1) / 2] = arr[i] ^ arr[(i - 1) / 2];
			arr[i] = arr[i] ^ arr[(i - 1) / 2];
		}
	}
}

int heap_order(int len, int *arr)
{
	for (int i = 0; i < len; i++) {
		int left = (2 * i) + 1;
		int right = (2 * i) + 2;

		if (left < len) {
			if (arr[i] < arr[left])
				return 0;
		}

		if (right < len) {
			if (arr[i] < arr[right])
				return 0;
		}
	}

	return 1;
}

void heapify_downshift(int index, int *arr, int len)
{
	int left = (2 * index) + 1;
	int right = (2 * index) + 2;
	int temp = 0;

	if (index >= len) {
		return;
	}

	if (arr[index] > arr[left] && arr[index] > arr[right]) {
		return;
	}

	if (left < len) {
		if (arr[left] > arr[index] && arr[left] > arr[right]) {
			temp = arr[index];
			arr[index] = arr[left];
			arr[left] = temp;
			heapify_downshift(left, arr, len);
		}
	}
	if (right < len) {
		if (arr[right] > arr[index] && arr[right] > arr[left]) {
			temp = arr[index];
			arr[index] = arr[right];
			arr[right] = temp;
			heapify_downshift(right, arr, len);
		}
	}
}

void heapsort(int len, int *arr)
{
	if (len <= 1) {
		return;
	}

	int temp = arr[0];
	arr[0] = arr[len - 1];
	arr[len - 1] = temp;

	heapify_downshift(0, arr, len - 1);

	heapsort(len - 1, arr);
}

// void heap_insert(int len, int *arr, int val)
// {
// 	// (i - 1) / 2 = parent node
// 	// (2 * i) + 1 = left child
// 	// (2 * i) + 2 = right child
// }