#include <stdio.h>
#include <stdlib.h>

void merge_sorted_arrays(int a[], int l, int m, int r) {
	int left_length = m - l + 1;
	int right_length = r - m;

	int temp_left[left_length];
	int temp_right[right_length];

	int i, j, k;

	for (i = 0; i < left_length; i++)
	{
		temp_left[i] = a[l + i];
	}
	for (i = 0; i < right_length; i++)
	{
		temp_right[i] = a[m + 1 + i];
	}

	for (i = 0, j = 0, k = l; k <= r; k++) {
		if ((i < left_length) && (j >= right_length) || temp_left[i] <= temp_right[i]) {
			a[k] = temp_left[i];
			i++;
		}
		else {
			a[k] = temp_right[j];
			j++;
		}
	}
}

void merge_sort_recursion(int a[], int l, int r) {
	int m = l + (r - l) / 2;
	merge_sort_recursion(a, l, m);
	merge_sort_recursion(a, m + 1, r);

	merge_sorted_arrays(a, l, m, r);
}

void merge_sort(int a[], int length) {
	merge_sort_recursion(a, 0, length - 1);
}




int main() {
	int arr[] = { 9, 4, 8, 1, 7, 0, 3 ,2, 5, 6 };
	int length = 10, i;
	
	merge_sort(arr, length);

	for (i = 0; i < length; i++)
	{
		printf("%3d", arr[i]);
	}
	return 0;
}