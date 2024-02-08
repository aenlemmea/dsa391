#include<stdio.h>

int binaryS(int* arr, int left, int right, int item) {
    if (right >= left) {
        int mid = left + (right - left) / 2;

        if (item == arr[mid]) {
            return mid;
        }
        else if (item < arr[mid]) {
            return binaryS(arr, left, mid - 1, item);
        }
        else {
            return binaryS(arr, mid + 1, right, item);
        }
    }
    else return -1;
}

int main() {
    int n, arr[100], i;
    int item;
    printf("Enter the no of elements = ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter the element: ");
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to be searched: ");
    scanf("%d", &item);
    i = binaryS(arr, 0, n - 1, item);
    if (i != -1) {
        printf("Element no found at %d\n", i + 1);
    }
    else {
        printf("element not found");
    }
}