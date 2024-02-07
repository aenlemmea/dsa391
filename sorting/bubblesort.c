#include <stdio.h>
#include <stdlib.h>
 
void bubblesort(int *arr, int n) {
	int p, q, xchanges, temp;

	for (p = 0; p < n - 1; p++) {
		xchanges = 0;
		for (q = 0; q < (n - 1 - p); q++) {
			if (arr[q] > arr[q + 1]) {
				temp = arr[q];
				arr[q] = arr[q + 1];
				arr[q + 1] = temp;
				xchanges++;
			}
		}
		if (xchanges == 0) {
			break;
		}
	}
}

int main() {
	int arr[] = { 5, 3, 6, 7, 9, 10 };
	int n = 6, i;
	
	bubblesort(arr, n);
	printf("After sorting the array: \n");
	for (i = 0; i < 6; i++) {
		printf("%7d", arr[i]);
	}
}