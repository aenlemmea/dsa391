#include <stdio.h>

int linearsearch(int *arr, int n, int tosearch) {
	int j;
	for (j = 0; j < n; j++)
	{
		if (arr[j] == tosearch) {
			return j;
		}
 	}
	return -1;
}

int main() {
	int arr[] = { 5, 3, 6, 7, 9, 10 };
	int n = 6, i, tosearch;

	printf("\nWhat element you want to search?: ");
	scanf("%d", &tosearch);

	i = linearsearch(arr, n, tosearch);
	if (i != -1) {
		printf("Element found at %d\n", i + 1);
	}
	else {
		printf("Element not found.")
	}
}