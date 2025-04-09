#include <stdio.h>
#include <stdlib.h>
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
int quickSelect(int arr[], int low, int high, int k) {
    if (k > 0 && k <= high - low + 1) {
        int pivotIndex = partition(arr, low, high);
        if (pivotIndex - low == k - 1) {
            return arr[pivotIndex];
        }
        if (pivotIndex - low > k - 1) {
            return quickSelect(arr, low, pivotIndex - 1, k);
        }
        return quickSelect(arr, pivotIndex + 1, high, k - (pivotIndex - low + 1));
    }
    return -1;
}
int findKthSmallest(int arr[], int n, int k) {
    return quickSelect(arr, 0, n - 1, k);
}
int main() {
    int n, k;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter k to find the kth smallest element: ");
    scanf("%d", &k);
    int result = findKthSmallest(arr, n, k);
    if (result != -1) {
        printf("The %dth smallest element is: %d\n", k, result);
    } else {
        printf("Invalid input for k\n");
    }
    free(arr);
    return 0;
}

