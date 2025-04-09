// find the smallest node and swap it with first element and swap the largest node with last element

#include <stdio.h>

void swapMinMax(int arr[], int n) {
    if (n < 2) return;

    int minIdx = 0, maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIdx]) minIdx = i;
        if (arr[i] > arr[maxIdx]) maxIdx = i;
    }

    int temp = arr[0];
    arr[0] = arr[minIdx];
    arr[minIdx] = temp;

    if (maxIdx == 0) maxIdx = minIdx;

    temp = arr[n - 1];
    arr[n - 1] = arr[maxIdx];
    arr[maxIdx] = temp;
}

int main() {
    int arr[] = {7, 2, 9, 1, 5, 10, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    swapMinMax(arr, n);

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
