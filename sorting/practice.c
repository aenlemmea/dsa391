#include <stdio.h>

void insertionsort(int* arr, int N) {
	int j, k, i;
	for (j = 1; j < N; j++) {
		k = arr[j];
		for (i = j - 1; i >= 0 && k < arr[i]; i--) {
			arr[i + 1] = arr[i];
		}
		arr[i + 1] = k;
	}
}

void selectionsort(int* arr, int N) {
	int j, smallest, i, temp;

	for (j = 0; j < N - 1; j++) {
		smallest = j;
		for (i = j + 1; i < N; i += 1) {
			if (arr[i] < arr[smallest]) {
				smallest = i;
			}
		}
		if (smallest != j) {
			temp = arr[j];
			arr[j] = arr[smallest];
			arr[smallest] = temp;
		}
	}
}


int main() {
	int arr[] = { 5, 3, 6, 7, 9, 10 };
	int n = 6, i;

	insertionsort(arr, n);
	printf("After sorting the array with insertion sort: \n");
	for (i = 0; i < 6; i++) {
		printf("%7d", arr[i]);
	}
	
	selectionsort(arr, n);
	printf("\n\nAfter sorting the array with insertion sort: \n");
	for (i = 0; i < 6; i++) {
		printf("%7d", arr[i]);
	}

}
