// Kth smallest element using quicksort

#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low;
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[high]);
    return i;
}

void quickSelect(int arr[], int low, int high, int k) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex == k) return;
        if (pivotIndex > k)
            quickSelect(arr, low, pivotIndex - 1, k);
        else
            quickSelect(arr, pivotIndex + 1, high, k);
    }
}

void findSmallestK(int arr[], int n, int k) {
    quickSelect(arr, 0, n - 1, k);
    for (int i = 0; i < k; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {7, 10, 4, 3, 20, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;
    findSmallestK(arr, n, k);
    return 0;
}
