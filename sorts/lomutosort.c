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
	int array[10] = {0};

	for (int i = 0; i < 10; i++) {
		array[i] = rand() % 1000;
		printf("%d ", array[i]);
	}
	puts("");
	quicksort(array, 0, 9);

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	puts("");
}

int partition(int *arr, int i, int j)
{
	int p = arr[j];
	int l = i;
	int r = i;
	while (r < j) {
		if (arr[r] < p) {
			if (arr[r] != arr[l]) {
				arr[l] = arr[l] ^ arr[r];
				arr[r] = arr[l] ^ arr[r];
				arr[l] = arr[l] ^ arr[r];
			}
			l++;
		}
		r++;
	}

	if (arr[l] != arr[j]) {
		arr[l] = arr[l] ^ arr[j];
		arr[j] = arr[l] ^ arr[j];
		arr[l] = arr[l] ^ arr[j];
	}
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