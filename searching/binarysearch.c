#include <stdio.h>
#include <stdlib.h>

int binarysearch(int *arr, int left, int right, int tosearch) {
	
	if (right >= left) {
		int mid = left + (right - left) / 2;

		if (tosearch == arr[mid]) {
			return mid;
		} else if (tosearch < arr[mid]) {
			return binarysearch(arr, left, mid - 1, tosearch);
		}
		else {
			return binarysearch(arr, mid + 1, right, tosearch);
		}
	}
	else return -1;
}

int main() {
	int arr[] = { 3, 5, 6, 7, 9, 10 }; // Assume sorted elements.
	int n = 6, i, tosearch;

	printf("\nWhat element you want to search?: ");
	scanf("%d", &tosearch);

	i = binarysearch(arr, 0, n - 1 , tosearch);
	if (i != -1) {
		printf("Element found at %d\n", i + 1);
	}
	else {
		printf("Element not found.");
	}
}