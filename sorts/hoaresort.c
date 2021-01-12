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
	int array[10] = {0, 1, 2, 4, 3, 5, 6, 7, 8, 9};

	for (int i = 0; i < 10; i++) {
		// array[i] = rand() % 10;
		printf("%d ", array[i]);
	}
	puts("");
	quicksort(array, 0, 9);

	for (int i = 0; i < 10; i++) {
		printf("%d ", array[i]);
	}
	puts("");
}

int partition(int *arr, int l, int r)
{
	static int count = 0;
	int piv = arr[l];
	l = l - 1;
	r = r + 1;
	while (true) {
		count++;
		do {
			l++;
		} while (arr[l] < piv);

		do {
			r--;
		} while (arr[r] > piv);

		if (l < r) {
			arr[l] = arr[l] ^ arr[r];
			arr[r] = arr[l] ^ arr[r];
			arr[l] = arr[l] ^ arr[r];
		} else {
			// printf("Hoare: %d\n", count);
			return r;
		}
	}
}

void quicksort(int *arr, int l, int r)
{
	int p = 0;
	if (l < r) {
		p = partition(arr, l, r);
		quicksort(arr, l, p);
		quicksort(arr, p + 1, r);
	}
}