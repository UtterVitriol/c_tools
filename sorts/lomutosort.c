#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
int partition(int *arr, int l, int r);
void quicksort(int *arr, int l, int r);

int main(void)
{
	time_t t;
	srand((unsigned)time(&t));
	int array[1000] = {0};

	for (int i = 0; i < 1000; i++) {
		array[i] = rand() % 10000;
		printf("%d ", array[i]);
	}
	puts("");
	quicksort(array, 0, 999);

	// for (int i = 0; i < 10; i++) {
	// 	printf("%d ", array[i]);
	// }
	// puts("");
}

int partition(int *arr, int i, int j)
{
	static int count = 0;
	int p = arr[j];
	int l = i;
	int r = i;
	while (r < j) {
		count++;
		if (arr[r] < p) {
			arr[l] = arr[l] ^ arr[r];
			arr[r] = arr[l] ^ arr[r];
			arr[l] = arr[l] ^ arr[r];
			l++;
		}
		r++;
	}

	arr[l] = arr[l] ^ arr[j];
	arr[j] = arr[l] ^ arr[j];
	arr[l] = arr[l] ^ arr[j];

	printf("Lomuto: %d\n", count);
	return l;
}

void quicksort(int *arr, int i, int j)
{
	int p = 0;

	if (i < j) {
		p = partition(arr, i, j);
		quicksort(arr, i, p - 1);
		quicksort(arr, p + 1, j);
	}
}