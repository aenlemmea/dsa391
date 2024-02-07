#include <stdio.h>
#include <stdlib.h>

/*
	Selection sort: 
		Extension of minimum/maximum technique. 
			Find  the  minimum  value  in  the  list
			Swap  it  with  the  value  in  the  first  position
			Repeat the steps above for remaining elements in the list starting at the second position
*/


void selectionsort(int *arr, int n) {
	int p, q, temp, smallest;

	for (p = 0; p < n - 1 ; p++)
	{
		smallest = p;
		for (q = p + 1; q < n; q++)
		{
			if (arr[smallest] > arr[q]) {
				smallest = q;
			}
 		}
		if (p != smallest) {
			temp = arr[p];
			arr[p] = arr[smallest];
			arr[smallest] = temp;
		}
	}
}

int main() {
	int arr[] = { 5, 3, 6, 7, 9, 10 };
	int n = 6, i;

	selectionsort(arr, n);
	printf("After sorting the array: \n");
	for (i = 0; i < 6; i++) {
		printf("%7d", arr[i]);
	}
}