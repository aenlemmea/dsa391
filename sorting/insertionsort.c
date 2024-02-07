#include <stdio.h>
#include <stdlib.h>

/*
	Nothing is smaller or equal -> append a_i to beginning. Else append it after the element that is smaller or equal.
*/

void insertionsort(int *arr, int n) {
	int j, k, i;
	for (j = 1; j < n; j++)
	{
		k = arr[j];
		for (i = j - 1; i >= 0 && k < arr[i]; i--)
		{
			arr[i + 1] = arr[i];
			arr[i + 1] = k;
		}
	}

}

int main() {
	int arr[] = { 5, 3, 6, 7, 9, 10 };
	int n = 6, i;

	insertionsort(arr, n);
	printf("After sorting the array: \n");
	for (i = 0; i < 6; i++) {
		printf("%7d", arr[i]);
	}
}